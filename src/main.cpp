#include <Arduino.h>
#include <HardwareSerial.h>

// #include "ESP32Servo.h"
#include "JY901.h"
#include "auv.h"
// #include "motor.h"
#define MOTOR_DEBUG
// #define IMU_DEBUG

int forwardSpeed = 0;

float initialDepth = 0;
float currentDepth = 0;
float targetDepth = 0.10;
float errorDepth = 0;

float initialAnglePitch = 0;
float initialAngleRoll = 0;
float initialAngleYaw = 0;
float currentAnglePitch = 0;
float currentAngleRoll = 0;
float currentAngleYaw = 0;
float errorAnglePitch = 0;
float errorAngleRoll = 0;
float errorAngleYaw = 0;

int pAnglePitch = 1;
int iAnglePitch = 0;
int dAnglePitch = 0;
int pAngleRoll = 1;
int iAngleRoll = 0;
int dAngleRoll = 0;
int pAngleYaw = 5;
int iAngleYaw = 0;
int dAngleYaw = 0;
int pDepth = 0;

int speedMotor1 = 0;
int speedMotor2 = 0;
int speedMotor3 = 0;
int speedMotor4 = 0;
int speedMotor5 = 0;
int speedMotor6 = 0;
int speedMotor7 = 0;
int speedMotor8 = 0;

HardwareSerial cam(1);
HardwareSerial prm(2);
// Servo myservo;
void setup() {
    Serial.begin(115200);
    delay(1000);
    JY901.StartIIC();
    cam.begin(115200, SERIAL_8N1, 34, 4);
    prm.begin(115200, SERIAL_8N1, 35, 0);
    delay(200);
    motorInit();
#ifdef MOTOR_DEBUG
    Serial.println("motor init");
#endif
    delay(500);
    for (size_t i = 0; i < 20; i++) {
        JY901.GetAngle();
        delay(10);
    }
    initialAnglePitch = (float)JY901.stcAngle.Angle[0] / 32768 * 180;
    initialAngleRoll = (float)JY901.stcAngle.Angle[1] / 32768 * 180;
    initialDepth = prm.readString().substring(9, 12).toFloat();
#ifdef IMU_DEBUG
    Serial.print("initialAngle Pitch/Roll:");
    Serial.print(initialAnglePitch);
    Serial.print(" ");
    Serial.println(initialAngleRoll);
    delay(1000);
#endif
}

void loop() {
    /**
     * 传感器数据处理，计算出误差,摄像头传过来kxb,如10°10cm为"10x10\n",5°8cm为"05x08\n"
     */
    JY901.GetAngle();
    currentAnglePitch = (float)JY901.stcAngle.Angle[0] / 32768 * 180;
    currentAngleRoll = (float)JY901.stcAngle.Angle[1] / 32768 * 180;
    // currentDepth = prm.readStringUntil('\n').substring(9,14).toFloat();
    // String depth = prm.readStringUntil('\n');
    // Serial.print(depth);

    // Serial.println(currentDepth);
    // errorAngleYaw = cam.readStringUntil('\n').substring(0, 2).toFloat();
    errorAnglePitch = constrain(currentAnglePitch - initialAnglePitch, -10, 10);
    errorAngleRoll = constrain(currentAngleRoll - initialAngleRoll, -10, 10);
    // errorDepth = constrain(currentDepth - targetDepth, -0.2, 0.2);
//     errorDepth = constrain(targetDepth - currentDepth, -0.2, 0.2);
#ifdef IMU_DEBUG
    Serial.print("errorAngle Pitch/Roll:");
    Serial.print(errorAnglePitch);
    Serial.print(" ");
    Serial.println(errorAngleRoll);
#endif

    /**
     * 电机控制
     */
    speedMotor1 =
        constrain(int(forwardSpeed + errorAngleYaw * pAngleYaw), -8, 8);
    speedMotor2 =
        constrain(int(forwardSpeed - errorAngleYaw * pAngleYaw), -8, 8);
    speedMotor3 =
        constrain(int(forwardSpeed + errorAngleYaw * pAngleYaw), -8, 8);
    speedMotor4 =
        constrain(int(forwardSpeed - errorAngleYaw * pAngleYaw), -8, 8);

    speedMotor5 = constrain(
        int(pAnglePitch * errorAnglePitch - pAngleRoll * errorAngleRoll +
            pDepth * errorDepth + pDepth * errorDepth),
        -8, 8);
    speedMotor6 = constrain(
        int(-pAnglePitch * errorAnglePitch - pAngleRoll * errorAngleRoll -
            pDepth * errorDepth - pDepth * errorDepth),
        -8, 8);
    speedMotor7 = constrain(
        int(pAnglePitch * errorAnglePitch + pAngleRoll * errorAngleRoll -
            pDepth * errorDepth - pDepth * errorDepth),
        -8, 8);
    speedMotor8 = constrain(
        int(-pAnglePitch * errorAnglePitch + pAngleRoll * errorAngleRoll +
            pDepth * errorDepth + pDepth * errorDepth),
        -8, 8);
    motor1.write(speedMotor1 + 95);
    motor2.write(speedMotor2 + 95);
    motor3.write(speedMotor3 + 95);
    motor4.write(speedMotor4 + 95);
    motor5.write(speedMotor5 + 95);
    motor6.write(speedMotor6 + 95);
    motor7.write(speedMotor7 + 95);
    motor8.write(speedMotor8 + 95);
#ifdef MOTOR_DEBUG
    Serial.print("1234 speed: ");
    Serial.print(speedMotor1);
    Serial.print(" ");
    Serial.print(speedMotor2);
    Serial.print(" ");
    Serial.print(speedMotor3);
    Serial.print(" ");
    Serial.print(speedMotor4);
    Serial.print("5678 speed: ");
    Serial.print(speedMotor5);
    Serial.print(" ");
    Serial.print(speedMotor6);
    Serial.print(" ");
    Serial.print(speedMotor7);
    Serial.print(" ");
    Serial.println(speedMotor8);
#endif
    //     delay(50);
}