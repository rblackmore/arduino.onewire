# Arduino.OneWire
## Introduction
Arduino.OneWire sketch converts DS1990A 1-Wire input, and sends the data out via the Arduino's serial port.

Primarily used for conecting to an RFID reader with 1-Wire Ouput, such as the Aceprox 712-52.

## Dependencies
Arduino.OneWire depends on the [OneWire](https://github.com/PaulStoffregen/OneWire) library from https://github.com/PaulStoffregen.

This library can be downloaded using the Arduino IDE.

## Wiring Diagram
To use the 712-52 Reader, 12V must be supplied to the Arduino, with the Readers Pos(+) power cable connected to the VIN pin on the arduino.

1-Wire data is connected to pin 10 on the Arduino. With a 4.7K pullup resistor going to 5V.
Red and Green LEDs are controlled by pins 7 and 8, respectively.
A buzzer can be controlled by pin 3.

![Wiring Diagram](https://raw.githubusercontent.com/rblackmore/arduino.onewire/master/.images/Wiring%20Diagram.png)
