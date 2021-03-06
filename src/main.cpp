#include <Arduino.h>
#include <HardwareSerial.h>

#include "JY901.h"
#include "motor.h"
#include "auv.h"

#define MOTOR_DEBUG

HardwareSerial cam1(1);
HardwareSerial cam2(2);

void setup() {
    Serial.begin(115200);
    JY901.StartIIC();
    Serial.print("Time:20");
    // cam1.begin(115200, SERIAL_8N1, 27, 14);
    // cam2.begin(115200, SERIAL_8N1, 12, 13);
    pinMode(5, OUTPUT);
    ledcSetup(2, 50, 10);
    ledcAttachPin(5, 2);
    motorInit();
#ifdef MOTOR_DEBUG
    Serial.println("motor init");
#endif
    delay(500);
}

void loop() {
    JY901.GetAcc();
    Serial.print("Acc:");
    Serial.print((float)JY901.stcAcc.a[0] / 32768 * 16);
    Serial.print(" ");
    Serial.print((float)JY901.stcAcc.a[1] / 32768 * 16);
    Serial.print(" ");
    Serial.print((float)JY901.stcAcc.a[2] / 32768 * 16);

    JY901.GetGyro();
    Serial.print("Gyro:");
    Serial.print((float)JY901.stcGyro.w[0] / 32768 * 2000);
    Serial.print(" ");
    Serial.print((float)JY901.stcGyro.w[1] / 32768 * 2000);
    Serial.print(" ");
    Serial.print((float)JY901.stcGyro.w[2] / 32768 * 2000);

    JY901.GetAngle();
    Serial.print("Angle:");
    Serial.print((float)JY901.stcAngle.Angle[0] / 32768 * 180);
    Serial.print(" ");
    Serial.print((float)JY901.stcAngle.Angle[1] / 32768 * 180);
    Serial.print(" ");
    Serial.println((float)JY901.stcAngle.Angle[2] / 32768 * 180);

    delay(50);
}