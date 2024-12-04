// Interfacing nano with sensors
// inlude arduino libraries
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// custom libs
#include "BMP280.h"

// Component libraries
#include <LiquidCrystal_I2C.h>
#include <Adafruit_BMP280.h>

// Function declarations
void scanAvailableAddress();
void readBmp280Sensor();
void getHumidityDataOnUart();
// Global variables
// #define DHTPIN 2 // connected to pin 2
// #define DHTTYPE DHT11

// SPI Pins
#define BMP_SCL 13
#define BMP_SDO 12
#define BMP_SDA 11
#define BMP_CSB 10

// UART communication
// Buffer to receive DHT11 data usint
char uartBuffer[100];

// I2C
// Set lcd address and screen size
LiquidCrystal_I2C lcd(0x27, 16, 2);

Adafruit_BMP280 bmp(BMP_CSB, BMP_SDA, BMP_SDO, BMP_SCL);

// setup conde
void setup()
{
  Wire.begin(); // initilize i2c
  Serial.begin(9600);

  lcd.init();      // Initilize the lcd
  lcd.backlight(); // Turning on the lcd back light
  lcd.setCursor(0, 0);

  // scan if connections are Ok.
  scanAvailableAddress();
  Serial.print("done scanning");

  lcd.setCursor(0, 0);
  lcd.print("done scanning");
  delay(3000);
  lcd.clear();

  // print from BMP280 to lcd
  //char tmpBuffer[10];
  double data = readBMP280();
  //dtostrf(myValue, 4, 2, tmpBuffer);
  
  lcd.setCursor(0, 0);
  lcd.print("data = ");
  lcd.print(data, 2);  

  delay(3000);
  lcd.clear();

  // lcd.setCursor(0,0);
  

  // delay(3000);
  // lcd.clear();

  delay(1000);
}

//-------------------------------------------------------------
void loop()
{
  /* display BMP280 results on lcd */
  // readBmp280Sensor();
  delay(3000);
  // lcd.clear();

  /* Get humidity data from sender arduino */

  // getHumidityDataOnUart();

  delay(1000);
}
//----------------------------------------------------------------------
void getHumidityDataOnUart()
{
  Serial.readBytes(uartBuffer, 100);
  Serial.print(uartBuffer);
}

// Dispay on lcd
void readBmp280Sensor()
{
  lcd.setCursor(0, 0);
  lcd.print("BMP280 on SPI");
  delay(3000);
  lcd.clear();

  if (!bmp.begin())
  {
    Serial.println("sensor not found ");
    lcd.setCursor(0, 0);
    lcd.print("no sensor");
  }
  // read sensor data

  float temperature = bmp.readTemperature();
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" *C");
  Serial.println();

  float pressure = bmp.readPressure();
  Serial.print("psi: ");
  Serial.print(pressure);
  Serial.println();

  float altitude = bmp.readAltitude();
  Serial.print("Alt: ");
  Serial.print(altitude);
  Serial.print(" m");
  Serial.println();

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("T ");
  lcd.print(temperature);
  lcd.setCursor(7, 0);
  lcd.print(",");

  lcd.setCursor(9, 0);
  lcd.print("Alt ");
  lcd.print(altitude);

  lcd.setCursor(0, 1);
  lcd.print("Pa ");
  lcd.print(pressure);

  delay(3000);
}

// put function definitions here:
void scanAvailableAddress()
{
  // variables
  byte errorValue;          // Error code
  byte address;             // the 7-bit address of the device to transmit to
  byte lowerAddress = 0x08; // Lowest valid address
  byte upperAddress = 0x77; // Highest valid address
  byte addressCount;        // Number of devices found

  // put your main code here, to run repeatedly:
  Serial.println("Scanning I2C addresses ");
  if (lowerAddress < 0x10) //
    Serial.print("0");
  Serial.print(lowerAddress, HEX);
  Serial.print(" to 0x");
  Serial.print(upperAddress, HEX);
  Serial.println(".");

  addressCount = 0;
  // Loop through  all addressed
  for (address = lowerAddress; address <= upperAddress; address++)
  {
    // Serial.print("0");
    // Serial.println(address, HEX);
    Wire.beginTransmission(address);     // begin communication from the current address
    errorValue = Wire.endTransmission(); // returns 0 if transmission  at current address was successful
    if (errorValue == 0)
    {
      Serial.print("I2C device found at address 0x");

      if (address < 0x10) // not valid address
        Serial.print("0");
      Serial.println(address, HEX); // Print address
      addressCount++;
    }
  }
  // Print to serial
  Serial.print("Addresses found: ");
  Serial.print(addressCount);
  Serial.println();

  // Print to lcd
  lcd.setCursor(0, 0);
  lcd.print("Device address ");
  lcd.setCursor(0, 1);
  lcd.print(addressCount);
  delay(3000);
  lcd.clear();
}
