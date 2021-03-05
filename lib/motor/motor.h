#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_1_PIN 36
#define MOTOR_2_PIN 39
#define MOTOR_3_PIN 32
#define MOTOR_4_PIN 33
#define MOTOR_5_PIN 34
#define MOTOR_6_PIN 35
#define MOTOR_7_PIN 25
#define MOTOR_8_PIN 26

#define MOTOR_1_INVERSE 0
#define MOTOR_2_INVERSE 0
#define MOTOR_3_INVERSE 0
#define MOTOR_4_INVERSE 0
#define MOTOR_5_INVERSE 0
#define MOTOR_6_INVERSE 0
#define MOTOR_7_INVERSE 0
#define MOTOR_8_INVERSE 0


void motorInit(void);
int calculatePWM(int degree);
void motor1(int speed);
void motor2(int speed);
void motor3(int speed);
void motor4(int speed);
void motor5(int speed);
void motor6(int speed);
void motor7(int speed);
void motor8(int speed);
void forward(int speed);
void backward(int speed);
void floating(int speeed);
void diving(int speed);
void pitch(int speed);
void roll(int speed);
void yaw(int speed);

#endif