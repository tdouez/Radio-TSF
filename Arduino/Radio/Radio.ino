//--------------------------------------------------------------------
// 01/2018 - V1.00      
// Radio
//--------------------------------------------------------------------
//   __|              _/           _ )  |                       
//   _| |  |   ` \    -_)   -_)    _ \  |   -_)  |  |   -_)     
//  _| \_,_| _|_|_| \___| \___|   ___/ _| \___| \_,_| \___|     
//--------------------------------------------------------------------
#include <SPI.h>
#include <EEPROM.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <radio.h>
#include <si4703.h>
#include <RDSParser.h>

#define OLED_MOSI  12
#define OLED_CLK   13
#define OLED_DC    10
#define OLED_CS    11
#define OLED_RESET 9


#define ENCODER_PUSH  A2
#define ENCODER_PINA  A0
#define ENCODER_PINB  A1

#define SWITCH_FREQ1  3      
#define SWITCH_FREQ2  4
#define SWITCH_FREQ3  5
#define SWITCH_FREQ4  6

struct RadioConfigStruct {
  unsigned int freq1;
  unsigned int freq2;
  unsigned int freq3;
  unsigned int freq4;
} radio_config;

unsigned int freq;
int memo_choix_freq=-1;
int scan_freq_up;
int scan_freq_down;
int etape=0;
String rdsdata;
unsigned long previousMillis_encoder=0;
unsigned long previousMillis_splash=0;    
unsigned long previousMillis_radio=0;  
unsigned long currentTime;
unsigned long loopTime;
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;
unsigned int choix_freq;

extern const unsigned char radio0_bits[] PROGMEM;
extern const unsigned char radio1_bits[] PROGMEM;
extern const unsigned char radio2_bits[] PROGMEM;
extern const unsigned char radio3_bits[] PROGMEM;
extern const unsigned char radio4_bits[] PROGMEM;
extern const unsigned char radio5_bits[] PROGMEM;
extern const unsigned char radio6_bits[] PROGMEM;
extern const unsigned char radio7_bits[] PROGMEM;
extern const unsigned char fb_bits[] PROGMEM;


U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, OLED_CLK, OLED_MOSI, OLED_CS, OLED_DC, U8X8_PIN_NONE);
SI4703   radio;    ///< Create an instance of a SI4703 chip radio.
/// get a RDS parser
RDSParser rds;
RADIO_INFO ri;
/// State definition for this radio implementation.
enum RADIO_STATE {
  STATE_PARSECOMMAND, ///< waiting for a new command character.
  
  STATE_PARSEINT,     ///< waiting for digits for the parameter.
  STATE_EXEC          ///< executing the command.
};

RADIO_STATE state; ///< The state variable is used for parsing input characters.

//------------------------------------------------------------------
void draw(int etape) {
char buffer[20];

  switch (etape) {
    default:
    case 1:
    case 2:
      // splash screen -----
      u8g2.drawXBMP(0, 0, 128, 64, fb_bits);
      break;

    case 3:
      // rssi --------------
      if (ri.rssi == 0) u8g2.drawXBMP(10, 0, 17, 7, radio0_bits);
      if (ri.rssi >= 5 && ri.rssi < 15) u8g2.drawXBMP(10, 0, 17, 9, radio1_bits);
      if (ri.rssi >= 15 && ri.rssi < 20) u8g2.drawXBMP(10, 0, 17, 9, radio2_bits);
      if (ri.rssi >= 20 && ri.rssi < 25) u8g2.drawXBMP(10, 0, 17, 9, radio3_bits);
      if (ri.rssi >= 25 && ri.rssi < 30) u8g2.drawXBMP(10, 0, 17, 9, radio4_bits);
      if (ri.rssi >= 30 && ri.rssi < 35) u8g2.drawXBMP(10, 0, 17, 9, radio5_bits);
      if (ri.rssi >= 35 && ri.rssi < 40) u8g2.drawXBMP(10, 0, 17, 9, radio6_bits);
      if (ri.rssi >= 40) u8g2.drawXBMP(10, 0, 17, 9, radio7_bits);
      // frequence & rds info ---------
      radio.formatFrequency(buffer, sizeof(buffer));
      u8g2.setFont(u8g2_font_helvR14_tr);
      u8g2.drawStr(18, 30, buffer);
      u8g2.setFont(u8g2_font_helvR12_tr);
      u8g2.drawStr(23, 50, rdsdata.c_str());
      // choix
      sprintf(buffer, "%d", choix_freq);
      u8g2.setFont(u8g2_font_t0_15_tr);
      u8g2.drawStr(1, 63, buffer);
      break;

    case 10:
      u8g2.setFont(u8g2_font_helvR12_tr);
      u8g2.drawStr(15, 40, "Memo Station");
      break;
  }
}

//------------------------------------------------------------------
int lecture_switch_station()
{
  if (digitalRead(SWITCH_FREQ1) == LOW) return 1;
  if (digitalRead(SWITCH_FREQ2) == LOW) return 2;
  if (digitalRead(SWITCH_FREQ3) == LOW) return 3;
  if (digitalRead(SWITCH_FREQ4) == LOW) return 4;
  return 0;
}

//------------------------------------------------------------------
int recup_freq_station(int choix_freq)
{
  if (choix_freq == 1) return radio_config.freq1;  
  if (choix_freq == 2) return radio_config.freq2;  
  if (choix_freq == 3) return radio_config.freq3;  
  if (choix_freq == 4) return radio_config.freq4; 
  return 8888;
}


void RDS_process(uint16_t block1, uint16_t block2, uint16_t block3, uint16_t block4) {
  rds.processData(block1, block2, block3, block4);
}

void DisplayServiceName(char *name)
{
  rdsdata = name;
}

//------------------------------------------------------------------
void setup()
{
  pinMode(ENCODER_PUSH, INPUT_PULLUP);
  pinMode(ENCODER_PINA, INPUT_PULLUP);
  pinMode(ENCODER_PINB, INPUT_PULLUP);
  pinMode(SWITCH_FREQ1, INPUT_PULLUP);
  pinMode(SWITCH_FREQ2, INPUT_PULLUP);
  pinMode(SWITCH_FREQ3, INPUT_PULLUP);
  pinMode(SWITCH_FREQ4, INPUT_PULLUP);

  
  // Init Serial interface -----------------
  Serial.begin(115200);
  
  Serial.println("Load config.");
  loadConfig();

  Serial.println(F("Init LCD."));
  u8g2.begin();
 
}



void loop()
{
unsigned long currentMillis = millis();


    u8g2.firstPage();  
    do {
      draw(etape);
    } while( u8g2.nextPage() );

    switch (etape) {
      case 0:
        Serial.println(".0.");
        previousMillis_splash = currentMillis;
        etape=1;
        break;
      
      case 1:
        Serial.println(".1.");
        Serial.println("Init si4703");
        // Initialize the Radio 
        radio.init();
        radio.setMono(true);
        radio.setMute(false);
        radio.setVolume(6);
        radio.setBandFrequency(RADIO_BAND_FM, 9140);
        // setup the information chain for RDS data.
        radio.attachReceiveRDS(RDS_process);
        rds.attachServicenNameCallback(DisplayServiceName);
        
        etape=2;
        break;

      case 2:
        Serial.println(".2.");
        if(currentMillis - previousMillis_splash > 800L) {
            previousMillis_splash = currentMillis;
            etape=3;
        }
        break;
        
      case 10:
        delay(1000);
        etape=3;
        break;
        
      default:
        // Lecture choix station ----------------------------------------------
        choix_freq=lecture_switch_station();
        
        if (choix_freq != memo_choix_freq) {
          memo_choix_freq=choix_freq;
          rdsdata="";
          //radio.clearRDS();
          freq = recup_freq_station(choix_freq);  
          Serial.println(freq);
            
          radio.setFrequency(freq);
          radio.getRadioInfo(&ri);
        }
          
        // Lecture encodeur bouton central pour mémorisation station ----------------------------------
        if (digitalRead(ENCODER_PUSH) == LOW) {
            Serial.println("Memo station");
            switch(choix_freq) {
              case 1:
                radio_config.freq1=freq;
                break;
              case 2: 
                radio_config.freq2=freq;
                break;
              case 3: 
                radio_config.freq3=freq;
                break;
              case 4:
                radio_config.freq4=freq;
                break;
            }
            saveConfig();
            etape=10;
        }
        
        //http://www.hobbytronics.co.uk/arduino-tutorial6-rotary-encoder
        // get the current elapsed time
        currentTime = millis();
        if(currentTime >= (loopTime + 5)){
          // 5ms since last check of encoder = 200Hz  
          encoder_A = digitalRead(ENCODER_PINA);    // Read encoder pins
          encoder_B = digitalRead(ENCODER_PINB);   
          if((!encoder_A) && (encoder_A_prev)){
            // A has gone from high to low 
            if(encoder_B) {     
              radio.seekUp(true);   
              freq=radio.getFrequency();    
            }   
            else {  
              radio.seekDown(true);   
              freq=radio.getFrequency();           
            }   
            rdsdata="";
          }   
          encoder_A_prev = encoder_A;     // Store value of A for next time            
          loopTime = currentTime;  // Updates loopTime
        }
        
        // Lecture niveau receptionFM ---------------
        if(currentMillis - previousMillis_radio > 1000L) {
          radio.getRadioInfo(&ri);
          freq=radio.getFrequency();
          previousMillis_radio=currentMillis;
        }
        
        // Lecture RDS --------------------------------------------
        radio.checkRDS();
        break;
    }
}



