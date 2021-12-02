#include <LiquidCrystal_I2C.h>
#include "digicode_h"

void initialization(){
  lcd.clear();
  lcd.setRGB(255,255,255);
  checkPassword();
}

void checkPassword(){
  String inputPassword;
  int errorCounter=0;
  
  lcd.clear(); lcd.setCursor(1,0); lcd.print("Enter password:");
  if(Serial.available(){
    inputPassword = Serial.readStringUntil('\n');
    if(inputPassword == password){
      lcd.clear(); lcd.setCursor(4,1); lcd.setRGB(0,255,0); lcd.print("Correct");
    } else if (inputPassword == '#'){
      changePassword();
    } else errorCounter++;
  }
}

void changePassword(){
  lcd.clear(); lcd.setCursor(0,0); lcd.print("Enter new password:");
}
