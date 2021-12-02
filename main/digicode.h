#ifndef DIGICODE_H
#define DIGICODE_H
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

void initialization();
void checkPassword();
void changePassword();

#endif
