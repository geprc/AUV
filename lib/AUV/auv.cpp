#include "auv.h"

#include <Arduino.h>

#include "ESP32Servo.h"
// #include "motor.h"

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;
Servo motor7;
Servo motor8;

void motorInit() {
    motor1.attach(MOTOR_1_PIN);
    motor2.attach(MOTOR_2_PIN);
    motor3.attach(MOTOR_3_PIN);
    motor4.attach(MOTOR_4_PIN);
    motor5.attach(MOTOR_5_PIN);
    motor6.attach(MOTOR_6_PIN);
    motor7.attach(MOTOR_7_PIN);
    motor8.attach(MOTOR_8_PIN);
    delay(3000);
    motor1.write(95);
    motor2.write(95);
    motor3.write(95);
    motor4.write(95);
    motor5.write(95);
    motor6.write(95);
    motor7.write(95);
    motor8.write(95);
    for (int i = 85; i <= 100; i++) {
        motor1.write(i);
        motor2.write(i);
        motor3.write(i);
        motor4.write(i);
        delay(200);
    }
    motor1.write(95);
    motor2.write(95);
    motor3.write(95);
    motor4.write(95);
    delay(1000);

    for (int i = 93; i <= 100; i++) {
        motor5.write(i);
        motor6.write(i);
        motor7.write(i);
        motor8.write(i);
        delay(200);
    }
    motor5.write(95);
    motor6.write(95);
    motor7.write(95);
    motor8.write(95);
    delay(1000);
}

// speed -90 to +90
//绿电机顺时针转喷水
//蓝电机逆时针转喷水
//前进
// void forward(int speed) {
//     motor1.setSpeed(-speed);
//     motor2.setSpeed(-speed);
//     motor3.setSpeed(-speed);
//     motor4.setSpeed(-speed);
// }
// //后退
// void backward(int speed) {
//     motor1.setSpeed(speed);
//     motor2.setSpeed(speed);
//     motor3.setSpeed(speed);
//     motor4.setSpeed(speed);
// }

// //上浮
// void floating(int speed) {
//     motor5.setSpeed(-speed);
//     motor6.setSpeed(speed);
//     motor7.setSpeed(speed);
//     motor8.setSpeed(-speed);
// }

// //下潜
// void diving(int speed) {
//     motor5.setSpeed(speed);
//     motor6.setSpeed(-speed);
//     motor7.setSpeed(-speed);
//     motor8.setSpeed(speed);
// }

// //俯仰
// void pitch(int speed) {
//     motor5.setSpeed(speed);
//     motor6.setSpeed(-speed);
//     motor7.setSpeed(speed);
//     motor8.setSpeed(-speed);
// }

// //横滚
// void roll(int speed) {
//     motor5.setSpeed(-speed);
//     motor6.setSpeed(-speed);
//     motor7.setSpeed(speed);
//     motor8.setSpeed(speed);
// }

// //偏航
// void yaw(int speed) {
//     motor1.setSpeed(-speed);
//     motor2.setSpeed(speed);
//     motor3.setSpeed(-speed);
//     motor4.setSpeed(speed);
// }