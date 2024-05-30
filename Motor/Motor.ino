#include "Motor.h"
#include "LiquidCrystal_I2C.h"
#include "clicli.h"

Motor mymotor(
  3, //enA
  4, //in1
  5, //in2
  7, //in3
  8, //in4
  9  //enB
  );
clicli mycli(mymotor);

void setup() {
  mymotor.begin();
  mycli.begin();
}

void loop() {
  mycli.run();
}