#include "config.h"
#include "line/line.h"
#include "motors/motors.h"
#include "motors/encoders/encoders.h"

GyverPID regulator(0.5, 0, 0, 2); // настроить 
GyverPID motors(5, 0, 0.2, 10);

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

  regulator.setDirection(REVERSE);
  regulator.setLimits(-255, 255);
  regulator.setpoint = 2500;

  motors.setDirection(NORMAL);
  motors.setLimits(-255, 255);
  
  
}

void loop()
{
  digitalWrite(STBY, 1);
    uint16_t position = Line();
    regulator.input = position;
    int out = regulator.getResultTimer();
    //ml(constrain(motor_sp - out, -255, 255));
    //mr(constrain(motor_sp + out, -255, 255));
}