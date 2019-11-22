#ifndef CLEAN_METHOD_H
#define CLEAN_METHOD_H
#include "my_stl.h"
#include "iostream" 
#include "math.h"
#include <fstream>

//#define debug

#define unknown 0
#define up 1
#define down 2
#define left 3
#define right 4

extern char Map[1005][1005], visit[1005][1005];
extern int dis_to[1005][1005];
extern int dirty, c_step, m, n;
extern ofstream tmpout, ttt;
char isv[1005][1005];

int burtal(int pow_max, int str, int stc);
int burtal_r(int str, int stc, int idx_r, int idx_c, int pow_max);
int find_dir_nv(int r_id, int c_id, int d, int pri); 
int find_dir_v(int r_id, int c_id, int d, int pri);

int find_dir_r(int r_id, int c_id, int pri);
int find_dir_d(int r_id, int c_id, int pri, int dis);
int BFS_lim(int dis, int r_id, int c_id, int d);
int BFS_unlim(int dis, int r_id, int c_id);

#endif