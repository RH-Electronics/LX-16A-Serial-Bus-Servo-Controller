#include "LSCSerial.h"

// Используем Serial1 для связи с контроллером (на Teensy 4.1, например, Serial1 = пины 0 (RX) и 1 (TX))
LSCSerial servoController(Serial1);

void setup() {
    Serial.begin(115200); // Для вывода информации в монитор порта
    servoController.begin(9600); // Инициализация связи с контроллером на 9600 бод

    Serial.println("Servo controller initialized!");

    // Читаем напряжение батареи контроллера
    Serial.println("Reading battery voltage...");
    uint16_t voltage = servoController.getBatteryVoltage();
    Serial.print("Battery voltage: ");
    Serial.print(voltage);
    Serial.println(" mV");
    delay(500);
}

void loop() {
    // Двигаем серво в позицию 300 за 1 секунду
    Serial.println("Moving Servo's to 300...");
    servoController.moveServo(1, 300, 1000);
    servoController.moveServo(2, 300, 1000);
    servoController.moveServo(3, 300, 1000);
    delay(1100);

    // Читаем текущие позиции нескольких сервоприводов
    uint8_t servoID = 1; // ID сервопривода, который мы хотим проверить
    uint16_t position = servoController.readServoPosition(servoID);
    Serial.print("Servo ");
    Serial.print(servoID);
    Serial.print(" position: ");
    Serial.println(position);
    servoID = 2; // ID сервопривода, который мы хотим проверить
    position = servoController.readServoPosition(servoID);
    Serial.print("Servo ");
    Serial.print(servoID);
    Serial.print(" position: ");
    Serial.println(position);
    servoID = 3; // ID сервопривода, который мы хотим проверить
    position = servoController.readServoPosition(servoID);
    Serial.print("Servo ");
    Serial.print(servoID);
    Serial.print(" position: ");
    Serial.println(position);
    delay(1000);


    // Управляем сервоприводами одновременно
    Serial.println("Moving All together to 500...");
    uint8_t servoIDs[] = {1, 2, 3};
    int16_t positions[] = {500, 500, 500};
    servoController.moveMultipleServos(3, servoIDs, positions, 1000);
    delay(1100);
    
    // Читаем текущие позиции нескольких сервоприводов
    servoID = 1; // ID сервопривода, который мы хотим проверить
    position = servoController.readServoPosition(servoID);
    Serial.print("Servo ");
    Serial.print(servoID);
    Serial.print(" position: ");
    Serial.println(position);
    servoID = 2; // ID сервопривода, который мы хотим проверить
    position = servoController.readServoPosition(servoID);
    Serial.print("Servo ");
    Serial.print(servoID);
    Serial.print(" position: ");
    Serial.println(position);
    servoID = 3; // ID сервопривода, который мы хотим проверить
    position = servoController.readServoPosition(servoID);
    Serial.print("Servo ");
    Serial.print(servoID);
    Serial.print(" position: ");
    Serial.println(position);
    delay(1000);

    Serial.println("Moving Servo's to 700...");
    servoController.moveServo(1, 700, 1000);
    servoController.moveServo(2, 700, 1000);
    servoController.moveServo(3, 700, 1000);
    delay(1100);

        // Читаем текущие позиции нескольких сервоприводов 
    servoID = 1; // ID сервопривода, который мы хотим проверить
    position = servoController.readServoPosition(servoID);
    Serial.print("Servo ");
    Serial.print(servoID);
    Serial.print(" position: ");
    Serial.println(position);
    servoID = 2; // ID сервопривода, который мы хотим проверить
    position = servoController.readServoPosition(servoID);
    Serial.print("Servo ");
    Serial.print(servoID);
    Serial.print(" position: ");
    Serial.println(position);
    servoID = 3; // ID сервопривода, который мы хотим проверить
    position = servoController.readServoPosition(servoID);
    Serial.print("Servo ");
    Serial.print(servoID);
    Serial.print(" position: ");
    Serial.println(position);
    delay(1000);

    // Отключаем сервоприводы 1 и 2 (делает их свободными для ручного поворота)
//    Serial.println("Unloading Servo 1, 2 and 3...");
//    servoController.unloadServos(3, servoIDs);
//    delay(10000);
}
