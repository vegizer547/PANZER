#include "config.h"
#include "line/line.h"
#include "motors/motors.h"
#include "sensor/encoders/encoders.h"

void setup()
{
  Serial.begin(9600);
  Serial2.setTX(20);
  Serial2.setRX(21);
  Serial2.begin(9600);
  delay(200);

  pinMode(29, INPUT);
  pinMode(0, OUTPUT);  //s0
  pinMode(1, OUTPUT);  //s1
  pinMode(2, OUTPUT);  //s2
  pinMode(3, OUTPUT);  //s3
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(XSHUTL, OUTPUT);
  pinMode(XSHUTR, OUTPUT);
  pinMode(XSHUTM, OUTPUT);
  pinMode(BUZ, OUTPUT);
  pinMode(BUT, INPUT_PULLUP);

  regulator.setDirection(NORMAL);
  regulator.setLimits(-255, 255);
  regulator.setpoint = 2500;

  motors.setDirection(REVERSE);
  motors.setLimits(-255, 255);
  
  attachInterrupt(digitalPinToInterrupt(ENC_PIN0), l_InterruptHandler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_PIN1), r_InterruptHandler, CHANGE);
  digitalWrite(BUZ, 1);
  delay(50);
  digitalWrite(BUZ, 0);
  //ManualCalib();
  digitalWrite(BUZ, 1);
  delay(50);
  digitalWrite(BUZ, 0);
  delay(500);

  forward(400);
  //delay(1000);
  //ml(0);
  //mr(0);
  //left(90);
  //right(90);
  //backward(50);
  //Serial.print(motor_sp);
}

void loop()
{
  //Serial.println(motor_sp);
}