#include "color.h"

static col_sens color_sensor;

void normalize_col()
{
  float sum1 = color_sensor.left.r + color_sensor.left.g + color_sensor.left.b;
  float Gproc1 = color_sensor.left.g / sum1 * 100;
  float Rproc1 = color_sensor.left.r / sum1 * 100;
  if (Gproc1 >= 45) {
    //Зелёный
    color_sensor.left.curr_color = 1;
  }
  else if (Rproc1 >= 55) {
    //Красный
    color_sensor.left.curr_color = 2;
  }
  else color_sensor.left.curr_color = 0;

  float sum2 = color_sensor.right.r + color_sensor.right.g + color_sensor.right.b;
  float Gproc2 = color_sensor.right.g / sum2 * 100;
  float Rproc2 = color_sensor.right.r / sum2 * 100;
  if (Gproc2 >= 45) {
    //Зелёный
    color_sensor.right.curr_color = 1;
  }
  else if (Rproc2 >= 55) {
    //Красный
    color_sensor.right.curr_color = 2;
  }
  else color_sensor.right.curr_color = 0;
}

void readColor()
{
    uint16_t c;
    tcs.getRawData(&color_sensor.left.r, &color_sensor.left.g, &color_sensor.left.b, &c);
    tcs2.getRawData(&color_sensor.right.r, &color_sensor.right.r, &color_sensor.right.r, &c);
    normalize_col();
}

/*void getColorData(int r, int g, int b) {
  float sum1 = r + g + b;
  float Gproc = g / sum1 * 100;
  float Rproc = r / sum1 * 100;
  float Fproc = (r + g) / sum1 * 100;
  if (Gproc >= 45) {
    (!sens) ? color_sensor.left.curr_color = 1 : color_sensor.right.curr_color = 1;
  }
  if (Rproc >= 55) {
    //Serial.println("Красный");
    return (2);
  }
  /*if (Fproc >= 75.3 && Fproc <= 76) {
    //Serial.println("Фольга");
    return (3);
  }
  
  return (0);
}

void sfsdfsdfsdfsdfsdf(int r, int g, int b) {
  float sum1 = r + g + b;
  float Gproc = g / sum1 * 100;
  float Rproc = r / sum1 * 100;
  float Fproc = (r + g) / sum1 * 100;
  if (Gproc >= 45) {
    //Serial.println("Зелёный");
    return (1);
  }
  if (Rproc >= 55) {
    //Serial.println("Красный");
    return (2);
  }
  if (Fproc >= 75.3 && Fproc <= 76) {
    //Serial.println("Фольга");
    return (3);
  }
  return (0);
}*/

void ColorHandler()
{
  Serial.println("Цвет");
  readColor();

  if (color_sensor.left.curr_color == 2 || color_sensor.left.curr_color == 2) {
    for (int i = 0; i < 4; i++) {
        buz_pic(30);
        delay(970);
    }
    buz_pic(500);
    while (true) {}
  }

  if (color_sensor.left.curr_color == 1 || color_sensor.left.curr_color == 1)
    left(180);
  if (color_sensor.left.curr_color == 1 && color_sensor.left.curr_color == 0)
  {
    forward(40);
    left(90);
  }
  if (color_sensor.left.curr_color == 0 && color_sensor.left.curr_color == 1)
  {
    forward(40);
    right(90);
  }
}