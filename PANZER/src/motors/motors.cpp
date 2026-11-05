#include "motors.h"

void ml(int s)
{
    if (s > 0)
    {
        setDir(0, 0);
        analogWrite(PWMA, s);
        digitalWrite(AIN1, 1);
        digitalWrite(AIN2, 0);
    }
    else
    {
        setDir(0, 1);
        analogWrite(PWMA, -s);
        digitalWrite(AIN1, 0);
        digitalWrite(AIN2, 1);
    }
}
void mr(int s)
{
    if (s > 0)
    {
        setDir(1, 0);
        analogWrite(PWMB, s);
        digitalWrite(BIN1, 1);
        digitalWrite(BIN2, 0);
    }
    else
    {
        setDir(1, 1);
        analogWrite(PWMB, -s);
        digitalWrite(BIN1, 0);
        digitalWrite(BIN2, 1);
    }
}

void forward(uint64_t r)
{
    digitalWrite(STBY, is_drive);
    double start_l = getRasst(0);
    double start_r = getRasst(1);

    double traveled_l = 0;
    double traveled_r = 0;

    motors.setpoint = -2;

    motors.setLimits(-20, 20);

    while(r > (traveled_l + traveled_r) /2)
    {
        traveled_l = getRasst(0) - start_l;
        traveled_r = getRasst(1) - start_r;

        double err = traveled_l - traveled_r;
        motors.input = err;

        double out = motors.getResultTimer();

        ml(constrain((motor_sp - out), 0, 255));
        mr(constrain((motor_sp + out), 0, 255));
    }
    ml(0);
    mr(0);
}

void backward(uint64_t r)
{
    digitalWrite(STBY, is_drive);
    double start_l = getRasst(0);
    double start_r = getRasst(1);

    double traveled_l = 0;
    double traveled_r = 0;

    motors.setpoint = -2;

    motors.setLimits(-20, 20);

    while(r > (traveled_l + traveled_r) /2)
    {
        traveled_l = getRasst(0) - start_l;
        traveled_r = getRasst(1) - start_r;

        double err = traveled_l - traveled_r;
        motors.input = err;

        double out = motors.getResultTimer();

        ml(-1 * constrain((motor_sp - out), 0, 255));
        mr(-1 * constrain((motor_sp + out), 0, 255));
    }
    ml(0);
    mr(0);
}

void right(int angle)
{
    digitalWrite(STBY, is_drive);
    double start_l = getRasst(0);
    double start_r = getRasst(1);

    double traveled_l = 0;
    double traveled_r = 0;

    double rad = (double)angle / 57.2958;

    double target = rad * (KOLEYA / 2);
    
    motors.setpoint = 0;

    motors.setLimits(-255, 255);

    while(true)
    {
        traveled_l = getRasst(0) - start_l;
        traveled_r = start_r - getRasst(1);

        double err = traveled_l - traveled_r;
        motors.input = err;

        double out = motors.getResultTimer();

        ml(constrain((motor_sp - out), 0, 255));
        mr(-1* constrain((motor_sp + out), 0, 255));

        if (abs(traveled_l) >= target || abs(traveled_r) >= target)
            break;
    }
    ml(0);
    mr(0);
}

void left(int angle)
{
    digitalWrite(STBY, is_drive);
    double start_l = getRasst(0);
    double start_r = getRasst(1);

    double traveled_l = 0;
    double traveled_r = 0;

    double rad = (double)angle / 57.2958;

    double target = rad * (KOLEYA / 2);
    
    motors.setpoint = 0;

    motors.setLimits(-255, 255);

    while(true)
    {
        traveled_l = start_l - getRasst(0);
        traveled_r = getRasst(1) - start_r;

        double err = traveled_l - traveled_r;
        motors.input = err;

        double out = motors.getResultTimer();

        ml(-1* constrain((motor_sp - out), 0, 255));
        mr(constrain((motor_sp + out), 0, 255));

        if (abs(traveled_l) >= target || abs(traveled_r) >= target)
            break;
    }
    ml(0);
    mr(0);
}
