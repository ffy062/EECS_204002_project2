#include "clean_way.h"

int clean_fs(int max_pow, int str, int stc) {
     int clean;
     while(dirty > 0) {
        #ifdef debug
            cout << "cleaning " << endl;
        #endif
        clean = burtal(max_pow, str, stc);
        if(clean == 0)
            break;
        dirty -= clean;
        #ifdef debug
            cout << "Clean: " << clean << "Left: " << dirty << endl;
        #endif
    }
    return dirty;
}
int clean_r(int str, int stc, int size_r, int size_c) {
    int clean;
    int sr, sc, dr, dc;

    if(str < size_r / 2 && stc < size_c / 2) {
        sr = size_r - 1;
        sc = size_c - 1;
        dr = -1;
        dc = -1;
    }
    else if(str < size_r / 2 && stc >= size_c / 2) {
        sr = size_r - 1;
        sc = 0;
        dr = -1;
        dc = 1;
    }
    else if(str >= size_r / 2 && stc < size_c / 2) {
        sr = 0;
        sc = size_c - 1;
        dr = 1;
        dc = -1;
    }
    else {
        sr = 0;
        sc = 0;
        dr = 1;
        dc = 1;
    }
     for(int i = 0; i < size_r; ++i) {
        for(int j = 0; j < size_c; ++j) {
            #ifdef debug 
                //cout << sr + dr*i << " " << sc + dc*j << endl;
            #endif // debug
            if(visit[sr + dr*i][sc + dc*j] == '1') {
                #ifdef debug
                    cout << "cleaning reverse " << sr + dr*i << sc + dc*j << endl;
                #endif
                clean = burtal_r(str, stc, sr + dr*i, sc + dc*j);
                dirty -= clean;
                if(dirty == 0) {
                    break;
                }
                #ifdef debug
                    cout << "Clean: " << clean << "Left: " << dirty << endl;
                #endif
            }
        }
    }
}
