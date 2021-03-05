#include "motor.h"

#include <Arduino.h>

void motorInit() {
    ledcSetup(0, 50, 10);
    for (int i = 0; i < 8; i++) {
        ledcSetup(i, 50, 10);
    }
    ledcAttachPin(MOTOR_1_PIN, 0);
    ledcAttachPin(MOTOR_2_PIN, 1);
    ledcAttachPin(MOTOR_3_PIN, 2);
    ledcAttachPin(MOTOR_4_PIN, 3);
    ledcAttachPin(MOTOR_5_PIN, 4);
    ledcAttachPin(MOTOR_6_PIN, 5);
    ledcAttachPin(MOTOR_7_PIN, 6);
    ledcAttachPin(MOTOR_8_PIN, 7);
    ledcWrite(0, calculatePWM(90));
    for (int i = 0; i < 8; i++) {
        ledcWrite(i, calculatePWM(90));
    }
}

//舵机角度运算
int calculatePWM(int degree) {  // 0-180度
                                // 20ms周期，高电平0.5-2.5ms，对应0-180度角度
    const float min = 25.6;  //对应0.5ms（0.5ms/(20ms/1024）)
    const float max = 128;   //对应2.5ms
    if (degree < 0) degree = 0;
    if (degree > 180) degree = 180;
    return (int)(((max - min) / 180) * degree + min);
}

void motor1(int speed) {
    if (speed<-90) speed = -90;
    if (speed> 90) speed =  90;
    ledcWrite(0, calculatePWM(speed+90));
}
void motor2(int speed) {
    if (speed<-90) speed = -90;
    if (speed> 90) speed =  90;
    ledcWrite(1, calculatePWM(speed+90));
}
void motor3(int speed) {
    if (speed<-90) speed = -90;
    if (speed> 90) speed =  90;
    ledcWrite(2, calculatePWM(speed+90));
}
void motor4(int speed) {
    if (speed<-90) speed = -90;
    if (speed> 90) speed =  90;
    ledcWrite(3, calculatePWM(speed+90));
}
void motor5(int speed) {
    if (speed<-90) speed = -90;
    if (speed> 90) speed =  90;
    ledcWrite(4, calculatePWM(speed+90));
}
void motor6(int speed) {
    if (speed<-90) speed = -90;
    if (speed> 90) speed =  90;
    ledcWrite(5, calculatePWM(speed+90));
}
void motor7(int speed) {
    if (speed<-90) speed = -90;
    if (speed> 90) speed =  90;
    ledcWrite(6, calculatePWM(speed+90));
}
void motor8(int speed) {
    if (speed<-90) speed = -90;
    if (speed> 90) speed =  90;
    ledcWrite(7, calculatePWM(speed+90));
}
// speed -90 to +90
//绿电机顺时针转喷水
//蓝电机逆时针转喷水
//前进
void forward(int speed) {
    motor1(-speed);
    motor2(-speed);
    motor3(-speed);
    motor4(-speed);
}
//后退
void backward(int speed) {
    motor1(speed);
    motor2(speed);
    motor3(speed);
    motor4(speed);
}

//上浮
void floating(int speed) {
    motor5(-speed);
    motor6( speed);
    motor7( speed);
    motor8(-speed);
}

//下潜
void diving(int speed) {
    motor5( speed);
    motor6(-speed);
    motor7(-speed);
    motor8( speed);
}

//俯仰
void pitch(int speed) {
    motor5( speed);
    motor6(-speed);
    motor7( speed);
    motor8(-speed);
}

//横滚
void roll(int speed) {
    motor5(-speed);
    motor6(-speed);
    motor7( speed);
    motor8( speed);
}

//偏航
void yaw(int speed) {
    motor1(-speed);
    motor2( speed);
    motor3(-speed);
    motor4( speed);
}