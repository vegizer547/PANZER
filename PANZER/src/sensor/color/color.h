#include "../../config.h"

struct color {
    uint16_t r, g, b;
    byte curr_color;
};

struct col_sens {
    color left, right;
};

void readColor(); // 0 - левый; 1 - правый