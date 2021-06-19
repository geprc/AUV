#ifndef AUV_H
#define AUV_H
// #include "motor.h"
#include "ESP32Servo.h"
/**
 * 34 35 36 39只能输出
 */

#define MOTOR_1_PIN 14
#define MOTOR_2_PIN 26
#define MOTOR_3_PIN 32
#define MOTOR_4_PIN 25
#define MOTOR_5_PIN 13
#define MOTOR_6_PIN 27
#define MOTOR_7_PIN 12
#define MOTOR_8_PIN 33

#define MOTOR_1_CHANNEL  8
#define MOTOR_2_CHANNEL  9
#define MOTOR_3_CHANNEL  10
#define MOTOR_4_CHANNEL  11
#define MOTOR_5_CHANNEL  12
#define MOTOR_6_CHANNEL  13
#define MOTOR_7_CHANNEL  14
#define MOTOR_8_CHANNEL  15

#define MOTOR_1_INVERSE 0
#define MOTOR_2_INVERSE 0
#define MOTOR_3_INVERSE 0
#define MOTOR_4_INVERSE 0
#define MOTOR_5_INVERSE 0
#define MOTOR_6_INVERSE 0
#define MOTOR_7_INVERSE 0
#define MOTOR_8_INVERSE 0

extern Servo motor1;
extern Servo motor2;
extern Servo motor3;
extern Servo motor4;
extern Servo motor5;
extern Servo motor6;
extern Servo motor7;
extern Servo motor8;


void motorInit(void);
// void forward(int speed);
// void backward(int speed);
// void floating(int speeed);
// void diving(int speed);
// void pitch(int speed);
// void roll(int speed);
// void yaw(int speed);

#endif