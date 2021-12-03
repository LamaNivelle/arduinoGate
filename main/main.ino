#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "rgb_lcd.h"
#include "pitches.h"

//initialize and define GLOBAL VARIABLE
String password = "hello";
String adminPassword = "admin";

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

int checkPassword(){
  String inputPassword;
  int errorCounter=0;
  int correctPassword=0;

  while(correctPassword!=1){
    if(errorCounter==3){
      for(int i=0;i<3;i++){     //make the user wait for 3 seconds
          lcd.clear();
          lcd.setCursor(2,0);
          lcd.print("Too many errors, wait for ");
          lcd.print(3-i);
          lcd.print(" seconds");
          delay(1000);
        }
        errorCounter=0;   //put the counter back to 0
    }
    lcd.clear(); lcd.setCursor(1,0); lcd.print("Enter password:");    //adjusting the screen
    if(Serial.available()){
      inputPassword = Serial.readStringUntil('\n');   //read password until hit enter key
      if(inputPassword == password){    //user enter the right password
        lcd.clear(); lcd.setCursor(4,1); lcd.setRGB(0,255,0); lcd.print("Correct");
        correctPassword=1;
      } else if (inputPassword == adminPassword){   //user asks to change password
        changePassword();
      } else errorCounter++;
    }
  }
  return correctPassword;
}

void changePassword(){
  lcd.clear(); lcd.setCursor(0,0); lcd.print("Enter new password:");
  if(Serial.available()){
    password = Serial.readStringUntil('\n');
  }
}

void setup() {
  Serial.begin(9600);   //initialize the serial monitor
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);

}

void loop() {
  

}
