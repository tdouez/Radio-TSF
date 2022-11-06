#define CONFIG_START            0

//----------------------------------------------------
void loadConfig() {
    for (unsigned int t=0; t<sizeof(radio_config); t++)
      *((char*)&radio_config + t) = EEPROM.read(CONFIG_START + t);
      
    if (radio_config.freq1 < 8750 || radio_config.freq1 > 10800) radio_config.freq1 = 8750;
    if (radio_config.freq2 < 8750 || radio_config.freq2 > 10800) radio_config.freq2 = 8750;
    if (radio_config.freq3 < 8750 || radio_config.freq3 > 10800) radio_config.freq3 = 8750;
    if (radio_config.freq4 < 8750 || radio_config.freq4 > 10800) radio_config.freq4 = 8750;
}

//----------------------------------------------------
void saveConfig() {
  for (unsigned int t=0; t<sizeof(radio_config); t++)
    EEPROM.write(CONFIG_START + t, *((char*)&radio_config + t));
}
