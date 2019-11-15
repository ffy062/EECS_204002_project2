#ifndef CLEAN_WAY_H
#define CLEAN_WAY_H
#include "my_stl.h"
#include "clean_method.h"
#include <fstream>

//#define debug

extern char Map[1005][1005], visit[1005][1005];
extern int dis_to[1005][1005];
extern int dirty, c_step;

int clean_fs(int max_pow, int str, int stc);
int clean_r(int str, int stc, int size_r, int size_c);


#endif