# Sensor Technology  In Embedded Systems

## Overview 
This project demonstrates the communication protocols commonly used in embedded systems. Microcontrollers and peripherals often send or receive data using either; I2C, SPI, UART or 1-Wire.The choice always depends on the specific functionality to be achieved.

In this project, two Arduino Nanos are used, nanoA and nanoB where nanoA gets raw data from DHT11 sensors and transmits it to the nanoB using the UART protocol. The receiver (nanoB) gets data from the sender(nanoA) and sends it to the LCD screen display using the I2C module attached.



## Data acquisition modules
* BMP280 - supports SPI and I2C of which SPI is used in this project.
* DHT11 -  humidity and temperature sensor. It uses 1-Wire protocol
* MPU6050 - used protocol I2C 
## Display
* LCD1602(16x2) and  I2C interface module

## Serial communication protocol definition 
* Inter-integrated circuit abbreviated (I2C) -  uses two wires (SCL and SDA ) to exchange data between devices. It is half-duplex, meaning data is sent two-way not simultaneously, multi-master and multi-slave protocol.
* Serial Peripheral Interface (SPI) - uses four wires (MOSI, MISO, SCL, CS) to send and receive data between devices. SPI is a full-duplex that is data sent two-way simultaneously, it is a single master and multi-slave protocol.
  This protocol is faster and runs at 10MB/s i.e., 2 times  I2C.
* Universal Asynchronous Receiver / Transmitter (UART) - uses two wires (TX and RX) it is often either simplex (one direction), half-duplex or full-duplex.
* 1-Wire - it uses one wire to send data and is a wired half-duplex data bus.

## Block diagram
![Block diagram](https://github.com/embedded-code-Portfolio/Sensor-Project/blob/fa9cbc1b81b3509137abf0c5a0b017d4a78c91ad/Nano_sensor_diagram.jpeg)

## Wiring
![Wirig](https://github.com/embedded-code-Portfolio/Sensor-Project/blob/e9399dd2dc4cd4ec659ccaf01b4c21e7f02fb8ea/wiring_new.jpeg)


## Programming environment 
Vscode 
Extension platformIO

## Libraries used
Display **[LiquidCrystal](https://github.com/adafruit/Adafruit_LiquidCrystal)**.



## Useful links 
* [Inter-Integrated Circuit abbreviated](https://en.wikipedia.org/wiki/I%C2%B2C).
* [Serial Peripheral Interface](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface).
* [Universal asynchronous receiver-transmitter](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter).
* [1-Wire](https://en.wikipedia.org/wiki/1-Wire).






