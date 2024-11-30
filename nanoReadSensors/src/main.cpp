#include <Arduino.h>
//  Interfacing nano with sensors
#include <Wire.h> // I2C lib

// put function declarations here:
void deviceAddress();

void setup()
{
  Wire.begin(); // initilize i2c
  Serial.begin(9600);
  while (!Serial)
    delay(10);

  deviceAddress();
}

void loop()
{
  // put your main code here, to run repeatedly:
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
}

