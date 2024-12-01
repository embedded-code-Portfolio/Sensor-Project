// Interfacing nano with sensors

#include <Arduino.h>
#include <Wire.h> // I2C lib
// #include <Adafruit_LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

// Function declarations
void deviceAddress();
void lcdDisplay();

// Global variables
#define DHTPIN 6 // connected to pin 2
#define DHTTYPE DHT11

// set lcd address and screen size
LiquidCrystal_I2C lcd(0x27, 16, 2);

// setup
void setup()
{
  Wire.begin(); // initilize i2c
  Serial.begin(115200);
  lcd.init();      // initilize the lcd
  lcd.backlight(); // tunning on the lcd back light
  lcd.setCursor(0, 0);
  lcd.print("I2C connection ");
  delay(3000);
  lcd.clear();

  // scan if connections are Ok.
  deviceAddress();
  lcdDisplay();
  delay(500);
}
//-------------------------------------------------------------
void loop()
{

  delay(2000);
}
//----------------------------------------------------------------------
// Dispay on lcd

void lcdDisplay()
{
}

// put function definitions here:

void deviceAddress()
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
  Serial.print("Addresses found: ");
  Serial.print(addressCount);
  Serial.println();
  lcd.setCursor(0, 0);
  lcd.print("Device address ");
  lcd.setCursor(0, 1);
  lcd.print(addressCount);
  delay(3000);
  lcd.clear();
}
