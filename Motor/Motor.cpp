//cpp code for motor class
#include "Motor.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27,16,2);
Motor::Motor(int enA, int in1, int in2, int in3, int in4, int enB) {
  _enA = enA;
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
  _enB = enB;
}
void Motor::begin() {
  Serial.begin(115200);
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  pinMode(_enA, OUTPUT);
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_in3, OUTPUT);
  pinMode(_in4, OUTPUT);
  pinMode(_enB, OUTPUT);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, LOW);
}
void Motor::msPrint(int num1, int num2) { //Motor Speed Print Function, can only take numbers that are 3 digits long (not including a negative symbol)
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motor| R  | L ");
  lcd.setCursor(1,1);
  lcd.print("Spd");  
  lcd.setCursor(5,1);
  lcd.print("|"); 
  if (num1 < 0) {
    lcd.setCursor(6,1); //This is so that negative numbers will still be in the same spot
  } else{
    lcd.setCursor(7,1);
  }
  lcd.print(num1); 
  lcd.setCursor(10,1);
  lcd.print("|");
  if (num2 < 0){
    lcd.setCursor(11,1);
  } else{
    lcd.setCursor(12,1);
  }
  lcd.print(num2); 
}
void Motor::move(int speedR, int speedL, int delayTime) {
  int speedLMap = map(abs(speedL), 0, 100, 0, 255);
  int speedRMap = map(abs(speedR), 0, 100, 0, 255);
  analogWrite(_enA, speedRMap);
  analogWrite(_enB, speedLMap);
  if (speedR > 0) {
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
    //Clockwise
  } else if (speedR < 0) {
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
    //Counterclockwise
  } else if (speedR = 0) {
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, HIGH);
    //Brake
  }
  if (speedL > 0) {
   digitalWrite(_in3, LOW);
   digitalWrite(_in4, HIGH);
   //Clockwise
  } else if (speedL < 0) {
    digitalWrite(_in3, HIGH);
    digitalWrite(_in4, LOW);
    //Counterclockwise
  } else if (speedL = 0) {
    digitalWrite(_in3, HIGH);
    digitalWrite(_in4, HIGH);
    //Brake
  } 
  msPrint(speedR, speedL);
  delay(delayTime);
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, HIGH);
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, HIGH);
}
int Motor::guyadd(int x, int y) {
  return(x+y);
}