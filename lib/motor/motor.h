#ifndef MOTOR_H
#define MOTOR_H

class Motor {
    static const int MIN_SPEED = -80;
    static const int MAX_SPEED =  80;
   private:
    int _pin;
    int _channel;
    int _speed;
    int _isInverse;

   public:
    Motor();
    ~Motor();
    void attach(int pin, int channel, int isInverse);
    void detach();
    void addSpeed(int value);
    void setSpeed(int speed);
    void move();
    int calculatePWM(int speed);
};


#endif