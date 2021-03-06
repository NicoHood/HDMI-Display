#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
  struct Data                   // use only int16_6 or uint16_6 variables, because of the AT register read/write commands (ATSx? and ATSx=value)!
  {
    int16_t   x0, x1;           // calibration values x-axis
    int16_t   y0, y1;           // calibration values y-axis
    uint16_t  screensaverTime;  // time in seconds, 0 = always on
    uint16_t  brightness;       // backlight brightness (0..255)
    uint16_t  orientation;      // orientation
    //--------------------------
    uint8_t   checksum;         // checksum of the data above
  };

  private:
    static const PROGMEM Data defaults;    // default values

  public:
    Data data;

  private:
    uint8_t calcChecksum(Data *d);
    bool    load();                  // load data from internal EEPROM, if checksum is correct

  public:
    Settings();
    void setup();
    void save();                     // save data to internal EEPROM
};

#endif //SETTINGS_H
