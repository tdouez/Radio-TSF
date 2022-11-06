#include "FreqCounter.h"
#include <radio.h>
#include <TEA5767.h>
#include <EEPROM.h>

#define VERSION   "v1.0.0"

#define INPUT_NE555     5 
#define INPUT_BP        11

#define DEFAULT_MIN_COUNT 0
#define DEFAULT_MAX_COUNT 600
#define INIT_EEPROM       '*'
#define MAX_CHANNEL       100
#define MAX_HISTO_FREQ    10
#define ECART_FREQ_BAS    1
#define ECART_FREQ_HAUT   5


unsigned int step_prog_cv = 0;

struct RadioConfigStruct {
  char init;
  RADIO_FREQ min_freq;
  RADIO_FREQ max_freq;
} radio_config;

RADIO_FREQ histo_freq[MAX_HISTO_FREQ];
RADIO_FREQ memo_channel[MAX_CHANNEL];

TEA5767 radio;  
RADIO_INFO radio_info;

RADIO_FREQ channel, last_channel;                     
unsigned int frequency, memo_frequency, last_frequency;
unsigned int ecart = ECART_FREQ_BAS;

//--------------------------------------------------------------------     
void flash_led(int nbr_flash, int tps_flash)
{
int i; 

  for (i=0; i<nbr_flash; i++) {
    delay(tps_flash);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(tps_flash);
    digitalWrite(LED_BUILTIN, LOW);
  }
}

//--------------------------------------------------------------------  
void loadConfig() {
    for (unsigned int t=0; t<sizeof(radio_config); t++)
      *((char*)&radio_config + t) = EEPROM.read(t);
      
    Serial.println(F("---------------------------------"));
    if (radio_config.init != INIT_EEPROM) {
        radio_config.min_freq = DEFAULT_MIN_COUNT;
        radio_config.max_freq = DEFAULT_MAX_COUNT;
        Serial.println(F(" >> init <<"));
    }
    Serial.print(F("Min count:"));
    Serial.println(radio_config.min_freq);
    Serial.print(F("Max count:"));
    Serial.println(radio_config.max_freq);
    Serial.println(F("---------------------------------"));
}


//--------------------------------------------------------------------  
void saveConfig() {
  for (unsigned int t=0; t<sizeof(radio_config); t++)
    EEPROM.write(t, *((char*)&radio_config + t));
}

//--------------------------------------------------------------------  
void print_histo_freq() {

  for (unsigned int i=0; i<MAX_HISTO_FREQ; i++) {
    Serial.print("Freq");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(histo_freq[i]); 
  }
}

//--------------------------------------------------------------------  
float verif_histo_freq() {
  int cpt=0, memo_cpt = 0;

  for (unsigned int i=0; i<MAX_HISTO_FREQ; i++) {
    for (unsigned int j=i; j<MAX_HISTO_FREQ; j++) {
      if (histo_freq[i] == histo_freq[j]) {
        cpt++;

      }
    }
    if (cpt > memo_cpt) {
      memo_cpt = cpt;

    }
    cpt=0;
  }

  return ((float)memo_cpt/MAX_HISTO_FREQ)*100;
}

//--------------------------------------------------------------------  
void memo_histo_freq(RADIO_FREQ f) {
  unsigned int i;

  for (i=MAX_HISTO_FREQ-1; i>0; i--) {
    histo_freq[i] = histo_freq[i-1];
  }
  histo_freq[i] = f;
}

//--------------------------------------------------------------------  
void init_histo_freq(RADIO_FREQ f) {
  for (unsigned int i=0; i<MAX_HISTO_FREQ; i++) {
    histo_freq[i] = f;
  }
}

//--------------------------------------------------------------------  
void setup()
{
  Serial.begin(115200);
  Serial.println(F("   __|              _/           _ )  |"));
  Serial.println(F("   _| |  |   ` \\    -_)   -_)    _ \\  |   -_)  |  |   -_)"));
  Serial.println(F("  _| \\_,_| _|_|_| \\___| \\___|   ___/ _| \\___| \\_,_| \\___|"));
  Serial.println(VERSION);

  pinMode(INPUT_NE555,INPUT);
  pinMode(INPUT_BP, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  loadConfig();

  // Mise en route du module FM, volume 15
  radio.init();
  radio.setMute(false);
  radio.setBand(RADIO_BAND_FM);
  radio.setMono(false);
  radio.setVolume(15);

  init_histo_freq(radio.getFrequency());
  
  last_channel=0;
}

//--------------------------------------------------------------------  
void loop(){
  Oscillateur();
  if (step_prog_cv == 0) {
    commandeCV();
  }

  // first step - set first count value
  if (!digitalRead(INPUT_BP) && step_prog_cv == 0) {
    step_prog_cv = 1;
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print(F("First value: "));
    Serial.println(frequency);
    memo_frequency = frequency;
    saveConfig();
    delay(200); 
  }
  // second step - wait first release button
  if (digitalRead(INPUT_BP) && step_prog_cv == 1) {
    //Serial.println(F("First release button"));
    step_prog_cv = 2;
    delay(200); 
  }

  // third step - set second count value
  if (!digitalRead(INPUT_BP) && step_prog_cv == 2) {
    step_prog_cv = 3;
    Serial.print(F("Second value: "));
    Serial.println(frequency);
    if (memo_frequency < frequency) {
      radio_config.min_freq = frequency;
      radio_config.max_freq = memo_frequency;
    }
    else {
      radio_config.min_freq = memo_frequency;
      radio_config.max_freq = frequency;
    }
    
    radio_config.init = INIT_EEPROM;
    digitalWrite(LED_BUILTIN, LOW);
    saveConfig();
    flash_led(4, 500);
  }
  // fourth step - wait second release button
  if (digitalRead(INPUT_BP) && step_prog_cv == 3) {
    //Serial.println(F("Second release button"));
    step_prog_cv = 0;
  }
 }

//--------------------------------------------------------------------  
void Oscillateur(){    
  FreqCounter::f_comp= 8;             // Set compensation to 12
  FreqCounter::start(100);            // Start counting with gatetime of 100ms
  while (FreqCounter::f_ready == 0)  ;// wait until counter ready
  frequency=FreqCounter::f_freq;      // read result
  delay(20);
}

//--------------------------------------------------------------------  
void commandeCV(){

  
  if (fabs(last_frequency-frequency)>1) {

    channel=map(frequency, radio_config.min_freq, radio_config.max_freq, 8750, 10770);
  /*memo_histo_freq(channel);
  float p = verif_histo_freq();
  Serial.println(p);
  // mémorise historiques, si constant l'ecart peut être plus grand => stabilité de réception
  if (p > 50) {
    ecart = ECART_FREQ_HAUT;
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    ecart = ECART_FREQ_BAS;
    digitalWrite(LED_BUILTIN, LOW);
  }*/
/*
    Serial.print("Tuned to: ");
    Serial.print(channel);
    Serial.println("Mhz");*/
    radio.setFrequency(channel);

    radio.getRadioInfo(&radio_info); 
    if (radio_info.tuned) digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(LED_BUILTIN, LOW);
    /*
    Serial.print(radio_info.rssi);
    Serial.print(" / ");
    Serial.print(radio_info.tuned);
    Serial.print(" / ");
    Serial.println(radio.getFrequency());
    */
     last_frequency=frequency;
  }
   
}