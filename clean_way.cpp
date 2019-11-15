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

    //if(str < size_r / 2 && stc < size_c / 2)
     for(int i = 0; i < size_r; ++i) {
        for(int j = 0; j < size_c; ++j) {
            if(visit[i][j] == '1') {
                #ifdef debug
                    cout << "cleaning reverse " << i << j << endl;
                #endif
                clean = burtal_r(str, stc, i, j);
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
