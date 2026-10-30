#include "../config.h"
#include "encoders/encoders.h"

void ml(int s)
{
    if (s > 0)
    {
        setDir(0, 0);
        digitalWrite(PWMA, s);
        digitalWrite(AIN1, 1);
        digitalWrite(AIN2, 0);
    }
    else
    {
        setDir(0, 1);
        digitalWrite(PWMA, -s);
        digitalWrite(AIN1, 0);
        digitalWrite(AIN2, 1);
    }
}
void mr(int s)
{
    if (s > 0)
    {
        setDir(1, 0);
        digitalWrite(PWMB, s);
        digitalWrite(BIN1, 1);
        digitalWrite(BIN2, 0);
    }
    else
    {
        setDir(1, 1);
        digitalWrite(PWMB, -s);
        digitalWrite(BIN1, 0);
        digitalWrite(BIN2, 1);
    }
}