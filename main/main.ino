#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "rgb_lcd.h"
#include "piches_h"
#include "digicode_h"

//initialize and define GLOBAL VARIABLE
String password = "hello";

//initialize and define RGB LCD SCREEN
rgb_lcd lcd;
int colorR;
int colorG;
int colorB;

void setup() {
  Serial.begin(9600);   //initialize the serial monitor

  lcd.init();    //initialize the lcd screen
  lcd.backlight();

}

void loop() {
  

}
