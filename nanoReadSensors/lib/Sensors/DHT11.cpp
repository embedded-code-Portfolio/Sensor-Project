#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "DHT11.h"

//Global
char uartBuffer[100];
LiquidCrystal_I2C lcd(0x27, 16, 2);


void readDHT11(){
Serial.begin(9600);
Serial.readBytes(uartBuffer, 100);

  Serial.print("Humidity = ");
  Serial.println(uartBuffer);
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("Humidity = ");
  lcd.print(uartBuffer);
  delay(1000);
  lcd.clear();
}
