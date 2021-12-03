#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "rgb_lcd.h"
#include "pitches.h"

//initialize and define GLOBAL VARIABLE
String password = "hello";

//initialize and define RGB LCD SCREEN
rgb_lcd lcd;
int colorR;
int colorG;
int colorB;

//define my functions

void initialization(){
  lcd.clear();
  lcd.setRGB(255,255,255);
  checkPassword();
}

void checkPassword(){
  String inputPassword;
  int errorCounter=0;
  
  lcd.clear(); lcd.setCursor(1,0); lcd.print("Enter password:");
  if(Serial.available()){
    inputPassword = Serial.readStringUntil('\n');
    if(inputPassword == password){
      lcd.clear(); lcd.setCursor(4,1); lcd.setRGB(0,255,0); lcd.print("Correct");
    } else if (inputPassword == "#"){
      changePassword();
    } else errorCounter++;
  }
}

void changePassword(){
  lcd.clear(); lcd.setCursor(0,0); lcd.print("Enter new password:");
}


void setup() {
  Serial.begin(9600);   //initialize the serial monitor
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);

}

void loop() {
  

}
