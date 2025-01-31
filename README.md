# LX-16A Serial Bus Servo Controller Library
https://www.hiwonder.com/products/serial-bus-servo-controller
###
https://www.hiwonder.com/products/lx-16a

## Overview
This library allows communication with LX-16A serial bus servos using Hiwonder Serial Bus Servo Controller and Arduino-compatible microcontroller like Teensy. It provides functions for controlling individual and multiple servos, reading servo positions, checking battery voltage, and unloading servos.

Tested with 3 servos on a serial bus.

## Features
- Move a single servo with custom speed and position.
- Move multiple servos simultaneously.
- Read the current position of a servo.
- Get battery voltage from the controller.
- Unload servos (disable holding torque).

## Hardware Requirements
- Arduino-compatible board (e.g., Teensy 4.1)
- LX-16A servos
- Hiwonder Serial Bus Servo Controller
- UART connection (TX/RX)

## Controller
<img src="https://github.com/RH-Electronics/LX-16A-Serial-Bus-Servo-Controller/blob/main/hiwonder-serial-bus-controller.jpg" alt="Hiwonder Serial Bus Controller">

## Installation
Include the library in your project:
```cpp
#include "LSCSerial.h"
```

## Wiring
- **TX (Teensy/Arduino) → RX (Hiwonder Controller)**
- **RX (Teensy/Arduino) → TX (Hiwonder Controller)**
- **GND → GND**
- **Servo Power via Controller (6.0V - 8.4V)**

Hiwonder controller RX/TX is 3.3V level. LX-16A servo has 3.3V level UART. The board has UART connector GND-TX-RX-5V, where 5V is an optional output pin to power Arduino board.
LX16-A Servos uses half-duplex UART asynchronous serial interface where SIG pin is the same pin for TX and RX on 5264-3P connector. Controller board includes 74HC126 and a micro to manage 115200 communication with the servo bus according to the LX-16A protocol.

## Usage
### Initialize the Controller
```cpp
#include "LSCSerial.h"
LSCSerial servoController(Serial1);
void setup() {
    Serial.begin(115200);
    servoController.begin(9600);
}
```

### Move a Single Servo
```cpp
servoController.moveServo(1, 700, 1000); // Move servo ID 1 to position 700 in 1000ms
```

### Move Multiple Servos
```cpp
uint8_t ids[] = {1, 2};
int16_t positions[] = {700, 500};
servoController.moveMultipleServos(2, ids, positions, 1000);
```

### Read Servo Position
```cpp
uint16_t pos = servoController.readServoPosition(1);
Serial.print("Servo 1 Position: ");
Serial.println(pos);
```

### Get Battery Voltage
```cpp
uint16_t voltage = servoController.getBatteryVoltage();
Serial.print("Battery Voltage: ");
Serial.print(voltage);
Serial.println(" mV");
```

### Unload Servos (Disable Holding Torque)
```cpp
uint8_t ids[] = {1, 2};
servoController.unloadServos(2, ids);
```

## Notes
- The servo ID must be set before use.
- Ensure proper baud rate settings for Teensy UART (default: 9600 baud).
- If multiple servos are connected, check the power supply current output is sufficient.

## Author
**Library made by Airis**
Debugged and tested by Alex **RH Electronics**.




