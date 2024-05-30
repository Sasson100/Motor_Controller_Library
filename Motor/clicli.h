#ifndef CLICLI_H
#define CLICLI_H
#include "Motor.h"

 class clicli {

  public:
   clicli(Motor &motor) ;
   void begin();   //must be called from  void setup()
   void run();   //must be called from  void loop()

  private:
   Motor &mymotor;
   int number;

 };
#endif 