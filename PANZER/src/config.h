#pragma once
#include <Arduino.h>
#include <GyverPID.h>
#include <Wire.h>

#define CONTAKT_PIN -1

#define PWMA 14
#define PWMB 8
#define AIN1 13
#define AIN2 12
#define BIN1 10
#define BIN2 9
#define STBY 11
#define ENC_PIN0 16
#define ENC_PIN1 17
#define BTN_DEB 2
#define XSHUTL 18
#define XSHUTR 19
#define XSHUTM 15
#define BUZ 22
#define BUT 21
#define NINETY 35

//                              диаметр  кол.прорезей
const float DIST_PER_TICK = (PI * 30.) / (24. * 2.); 

struct line_data {
    int raw;
    int calib;
    int min = 1024;
    int max = 0;
    bool state = 0;
};

inline int speed = 26; //Скорость в процентах
inline int motor_sp = map(speed, 0, 100, 0, 255); // при sp = 26: msp = 66
inline line_data line[8];
