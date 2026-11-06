#include "../config.h"

void buz_pic(int time)
{
    digitalWrite(BUZ, 1);
    delay(time);
    digitalWrite(BUZ, 0);
}