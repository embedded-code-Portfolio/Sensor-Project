# Sensor technology  in embedded Systems
Data acquisition using nano and sensors using preferred Protocols 

## Overview 
This project demonstrates or prototypes the communication protocols commonly used in embedded systems to  communicate between microcontrollers and peripherals as defined in the protocol section of this README. Example:
I2C, SPI, UART and 1-Wire.

## Operation
This has been achieved by connecting two Arduino Nanos which are codenamed Collector and Receiver for this purpose.
The Collector node gets raw data from sensors and sends them to the Receiver using the UART protocol. The receiver node gets data from the Collector node and sends them to the LCD screen display using the I2C module attached to it.


## Data acquisition modules and display
* BMP280 - supports SPI and I2C of which SPI is used in this project.
* DHT11 -  humidity and temperature sensor. It uses 1-Wire protocol
* MPU6050 - used protocol I2C (not yet implemented)
* LCD1602(16x2) and  I2C interface module

## Serial communication protocol definition 
* Inter-Integrated Circuit abbreviated (I2C) -  uses two wires (SCL and SDA ) to exchange data between devices. It is half-duplex, meaning data is sent two-way not simultaneously, multi-master and multi-slave protocol.
* Serial Peripheral Interface (SPI) - uses four wires (MOSI, MISO, SCL, CS) to send and receive data between devices. SPI is a full-duplex that is data sent two-way simultaneously, it is a single master and multi-slave protocol. Said to be faster at 10MB/s i.e., 2 times  I2C.
* Universal Asynchronous Receiver / Transmitter (UART) - uses two wires (TX and RX) it is often either simplex (one direction), half-duplex or full-duplex.
* 1-Wire - it uses one wire to send data, and it is a wired half-duplex data bus.

## Block diagram
![image alt](https://github.com/embedded-code-Portfolio/Sensor-Project/blob/a138ee29309db54c5fcca23a53854dee94d8e331/wiring.jpg)




## Programming environment 
vscode 
Extension platformIO

## Libraries used
Display **[LiquidCrystal](https://github.com/adafruit/Adafruit_LiquidCrystal)**.



## Useful links 
* [Inter-Integrated Circuit abbreviated](https://en.wikipedia.org/wiki/I%C2%B2C).
* [Serial Peripheral Interface](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface).
* [Universal asynchronous receiver-transmitter](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter).
* [1-Wire](https://en.wikipedia.org/wiki/1-Wire).






