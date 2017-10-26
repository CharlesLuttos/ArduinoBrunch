#include <LiquidCrystal.h>

// initialize the library

LiquidCrystal lcd(22,23,24,25,26,27);
byte caractere1[8] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00001
};

byte caractere2[8] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00001
};

byte customChar[8] = {
  0b00001,
  0b00011,
  0b00101,
  0b01001,
  0b01001,
  0b01001,
  0b11011,
  0b11011
};

byte charSorriso[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b01010,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

void setup()
{
  // create a new custom character
  lcd.createChar(0, customChar);
  lcd.createChar(1, customChar);
  // set up number of columns and rows
  lcd.begin(16, 2);

  // print the custom char to the lcd
  lcd.write(byte(1));
  // why typecast? see: http://arduino.cc/forum/index.php?topic=74666.0
}

void loop()
{
  
}
