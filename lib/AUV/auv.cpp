#include <Arduino.h>
#include "motor.h"
#include "auv.h"

Motor motor1;
Motor motor2;
Motor motor3;
Motor motor4;
Motor motor5;
Motor motor6;
Motor motor7;
Motor motor8;

void motorInit() {
    motor1.attach(MOTOR_1_PIN, MOTOR_1_CHANNEL, MOTOR_1_INVERSE);
    motor2.attach(MOTOR_2_PIN, MOTOR_2_CHANNEL, MOTOR_2_INVERSE);
    motor3.attach(MOTOR_3_PIN, MOTOR_3_CHANNEL, MOTOR_3_INVERSE);
    motor4.attach(MOTOR_4_PIN, MOTOR_4_CHANNEL, MOTOR_4_INVERSE);
    motor5.attach(MOTOR_5_PIN, MOTOR_5_CHANNEL, MOTOR_5_INVERSE);
    motor6.attach(MOTOR_6_PIN, MOTOR_6_CHANNEL, MOTOR_6_INVERSE);
    motor7.attach(MOTOR_7_PIN, MOTOR_7_CHANNEL, MOTOR_7_INVERSE);
    motor8.attach(MOTOR_8_PIN, MOTOR_8_CHANNEL, MOTOR_8_INVERSE);
}
// speed -90 to +90
//绿电机顺时针转喷水
//蓝电机逆时针转喷水
//前进
void forward(int speed) {
    motor1.setSpeed(-speed);
    motor2.setSpeed(-speed);
    motor3.setSpeed(-speed);
    motor4.setSpeed(-speed);
}
//后退
void backward(int speed) {
    motor1.setSpeed(speed);
    motor2.setSpeed(speed);
    motor3.setSpeed(speed);
    motor4.setSpeed(speed);
}

//上浮
void floating(int speed) {
    motor5.setSpeed(-speed);
    motor6.setSpeed(speed);
    motor7.setSpeed(speed);
    motor8.setSpeed(-speed);
}

//下潜
void diving(int speed) {
    motor5.setSpeed(speed);
    motor6.setSpeed(-speed);
    motor7.setSpeed(-speed);
    motor8.setSpeed(speed);
}

//俯仰
void pitch(int speed) {
    motor5.setSpeed(speed);
    motor6.setSpeed(-speed);
    motor7.setSpeed(speed);
    motor8.setSpeed(-speed);
}

//横滚
void roll(int speed) {
    motor5.setSpeed(-speed);
    motor6.setSpeed(-speed);
    motor7.setSpeed(speed);
    motor8.setSpeed(speed);
}

//偏航
void yaw(int speed) {
    motor1.setSpeed(-speed);
    motor2.setSpeed(speed);
    motor3.setSpeed(-speed);
    motor4.setSpeed(speed);
}