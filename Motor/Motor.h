#ifndef MOTOR_H
#define MOTOR_H

#include "stdint.h"
#include "Arduino.h"


class Motor {
      
  public:
    Motor(int enA, int in1, int in2, int in3, int in4, int enB);
    void begin();
    void msPrint(int num1, int num2);
    void move(int speedR, int speedL, int delayTime);
    int guyadd(int x, int y);
  
  private:
    int _enA;
    int _in1;
    int _in2;
    int _in3;
    int _in4;
    int _enB;
  


};
#endif