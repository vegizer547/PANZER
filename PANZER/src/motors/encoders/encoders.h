#include "../../config.h"

int64_t getEncDist(bool mtr); // 0 - левый; 1 - правый  
void setDir(bool mtr, bool dir);
void setEncDist(bool mtr);
void __time_critical_func(r_InterruptHandler());
void __time_critical_func(l_InterruptHandler());
double getRasst(bool mtr);
