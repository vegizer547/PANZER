#pragma once
#include "../config.h"
#include "../motors/motors.h"
#include "../sensor/color/color.h"

struct line_data {
    int raw;
    int calib;
    int min = 1024;
    int max = 0;
    bool state = 0;
};

void ReadRawLine();
void CalibrateLine();
void ManualCalib();
void AutoCalib();
uint16_t GetLinePos();
void goLine();