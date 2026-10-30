#include "encoders.h"

static uint64_t l_enc = 0;
static uint64_t r_enc = 0;
volatile static bool state_l = 0;
volatile static bool state_r = 0;
static bool dir_l = 0; // 0 - вперёд: 1 - назад
static bool dir_r = 0; // 0 - вперёд: 1 - назад
static double l_mill_rast = 0;
static double r_mill_rast = 0;



int64_t getEncDist(bool mtr)
{
    if (!mtr) return l_enc;
    else return r_enc;
}

void setDir(bool mtr, bool dir)
{
    if (!mtr) dir_l = dir;
    else dir_l = dir;
}

void setEncDist(bool mtr)
{
    if (!mtr) (!dir_l) ? l_enc++ : l_enc--;
    else (!dir_r) ? r_enc++ : r_enc--;
}

void __time_critical_func(r_InterruptHandler())
{
    bool temp = !digitalRead(ENC_PIN1);
    if(state_r != temp)
    {
        state_r = temp;
        setEncDist(1);
    }
}

void __time_critical_func(l_InterruptHandler())
{
    bool temp = !digitalRead(ENC_PIN0);
    if(state_l != temp)
    {
        state_l = temp;
        setEncDist(0);
    }
}

double getRasst(bool mtr)
{
    l_mill_rast = DIST_PER_TICK * l_enc;
    r_mill_rast = DIST_PER_TICK * r_enc;
    return (!mtr) ? l_mill_rast : r_mill_rast;
}


