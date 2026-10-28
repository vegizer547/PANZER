#include "../config.h"

void ml(int s)
{
    if (s > 0)
    {
        digitalWrite(PWMA, s);
        digitalWrite(AIN1, 1);
        digitalWrite(AIN2, 0);
    }
    else
    {
        digitalWrite(PWMA, -s);
        digitalWrite(AIN1, 0);
        digitalWrite(AIN2, 1);
    }
}
void mr(int s)
{

}