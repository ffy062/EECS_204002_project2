#ifndef CLEAN_METHOD_H
#define CLEAN_METHOD_H
#include "my_stl.h"
#include "iostream" 
#include <fstream>

extern char Map[1005][1005], visit[1005][1005];
extern int dis_to[1005][1005];
extern int dirty, c_step;
extern ofstream tmpout;

int burtal(int pow_max, int str, int stc);
int burtal_r(int str, int stc, int idx_r, int idx_c);


#endif