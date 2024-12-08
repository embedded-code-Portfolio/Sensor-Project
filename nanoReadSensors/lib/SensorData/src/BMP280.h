#ifndef BMP280_H
#define BMP280_H

#include <Adafruit_BMP280.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


void readBmp280Sensor();

// SPI Pins
#define BMP_SCL 13
#define BMP_SDO 12
#define BMP_SDA 11
#define BMP_CSB 10

Adafruit_BMP280 bmp(BMP_CSB, BMP_SDA, BMP_SDO, BMP_SCL);

double readBMP280();

#endif