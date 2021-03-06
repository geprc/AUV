#ifndef AUV_H
#define AUV_H
#include "motor.h"

#define MOTOR_1_PIN 36
#define MOTOR_2_PIN 39
#define MOTOR_3_PIN 32
#define MOTOR_4_PIN 33
#define MOTOR_5_PIN 34
#define MOTOR_6_PIN 35
#define MOTOR_7_PIN 25
#define MOTOR_8_PIN 26

#define MOTOR_1_CHANNEL 0
#define MOTOR_2_CHANNEL 1
#define MOTOR_3_CHANNEL 2
#define MOTOR_4_CHANNEL 3
#define MOTOR_5_CHANNEL 4
#define MOTOR_6_CHANNEL 5
#define MOTOR_7_CHANNEL 6
#define MOTOR_8_CHANNEL 7

#define MOTOR_1_INVERSE 0
#define MOTOR_2_INVERSE 0
#define MOTOR_3_INVERSE 0
#define MOTOR_4_INVERSE 0
#define MOTOR_5_INVERSE 0
#define MOTOR_6_INVERSE 0
#define MOTOR_7_INVERSE 0
#define MOTOR_8_INVERSE 0

extern Motor motor1;
extern Motor motor2;
extern Motor motor3;
extern Motor motor4;
extern Motor motor5;
extern Motor motor6;
extern Motor motor7;
extern Motor motor8;


void motorInit(void);
void forward(int speed);
void backward(int speed);
void floating(int speeed);
void diving(int speed);
void pitch(int speed);
void roll(int speed);
void yaw(int speed);

#endif