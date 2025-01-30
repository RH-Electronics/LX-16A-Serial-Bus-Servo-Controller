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

## Installation
Clone the repository:
```sh
git clone https://github.com/RH-Electronics/LX-16A-Serial-Bus-Servo-Controller.git
```
Include the library in your project:
```cpp
#include "LSCSerial.h"
```

## Wiring
- **TX (Teensy/Arduino) → RX (Hiwonder Controller)**
- **RX (Teensy/Arduino) → TX (Hiwonder Controller)**
- **GND → GND**
- **Servo Power via Controller (6.0V - 8.4V)**

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
- Ensure proper baud rate settings (default: 9600 baud).
- If multiple servos are connected, use external power (7.4V+).

## License
MIT License

## Author
**Library made by Airis**
Debugged and tested by Alex **RH Electronics**.




