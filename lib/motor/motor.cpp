#include "motor.h"

#include "Arduino.h"

Motor::Motor(){

};

Motor::~Motor() { detach(); }

void Motor::attach(int pin, int channel, int isInverse) {
    _pin = pin;
    _channel = channel;
    _isInverse = isInverse;
    ledcSetup(_channel, 50, 10);
    ledcAttachPin(_pin, _channel);
    ledcWrite(_channel, 511);  //电机速度为0
}

void Motor::detach() {}

void Motor::addSpeed(int value) {
    _speed += value;
    if (_speed > MAX_SPEED) {
        _speed = MAX_SPEED;
    }
    if (_speed < MIN_SPEED) {
        _speed = MIN_SPEED;
    }
}
void Motor::move() {
    if (_isInverse) {
        ledcWrite(_channel, calculatePWM(-_speed));
    } else {
        ledcWrite(_channel, calculatePWM( _speed));
    }
}

int Motor::calculatePWM(int speed) {  // -80~80
    // 20ms周期，高电平0.5-2.5ms，对应0-180度角度
    speed += 90;
    const float min = 25.6;  //对应0.5ms（0.5ms/(20ms/1024）)
    const float max = 128;   //对应2.5ms
    if (speed < 0) speed = 0;
    if (speed > 180) speed = 180;
    return (int)(((max - min) / 180) * speed + min);
}
