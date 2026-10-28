#include "line.h"

void ReadRawLine()
{
    for (int a = 0; a < 8; a++)
    {
        for (int i = 0; i <= 3; i++)
            digitalWrite(0 + i, bitRead(a, i));
        line[a].raw = analogRead(26);
    }
}

void ManualCalib()
{
    for (int n = 0; n < 100000; n++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (line[i].raw > line[i].max)
                line[i].max = line[i].raw;
            if (line[i].raw < line[i].min)
                line[i].min = line[i].raw;
        }
    }
}

void AutoCalib()
{
    Serial.println("Дописать когда будут готовы моторы");
}

void ReadCalibratedValue()
{
    ReadRawLine();
    for (int i = 0; i < 8; i++)
    {
        line[i].calib = map(line[i].raw, line[i].min, line[i].max, 0, 1000);
        line[i].calib = constrain(line[i].calib, 0, 1000);
        if (line[i].calib >= 600) line[i].state = 1;
        else line[i].state = 0;
    }
}

static uint16_t lastPosition = 2500;
uint16_t Line()
{
    ReadCalibratedValue();
    bool onLine = false;
    uint32_t avg = 0; // this is for the weighted total
    uint32_t sum = 0; // this is for the denominator, which is <= 64000

    for (uint8_t i = 0; i < 4; i++)
    {
        uint16_t value = line[i+2].calib;
        if (value > 800)
            onLine = true;
        if (value > 400)
        {
            avg += (uint32_t)value * ((i+1) * 1000);
            sum += value;
        }
    }
    if (!onLine)
        return lastPosition;
    lastPosition = avg / sum;
    return lastPosition;
}
