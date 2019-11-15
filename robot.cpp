#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>
#include "my_stl.h"
#include "bfs.h"
#include "clean_method.h"
#include "clean_method.cpp"

#define debug
//#define typeinput

using namespace std;

// ver0-0 : construct my_queue, BFS, handling input
// ver0-1 : spilt function to different file 
// ver0-2 : add dirty, change way to store floor data, revise BFS
// ver1-0 : brutal force with no optimization, handling input file
// ver1-1 : handling output and TA's testcase
// ver1-2 : fix some bugs (output file and cleaning area calculation)
// ver1-3 : add function find_dir_nv / find_dir_v


// map for debug
char Map[1005][1005], visit[1005][1005];
int dis_to[1005][1005];
int dirty, c_step;
ofstream tmpout;


int main() {
    ios_base::sync_with_stdio(false);
    
    int dis, m, n, str, stc;
    ifstream floor, tmpfile;
    ofstream outstep;
    floor.open("floor.data");
    tmpout.open("tmp.path");
    #ifdef typeinput
        cin >> m >> n >> dis;
        for(int i = 0, r = 0; i < m; ++i) {
            char ch;
            for(int j = 0; j < n; ++j) {
                cin >> ch;
                if(ch != '1' && ch != '0' && ch != 'R') {
                    cout << "invalid test case: floor data unexpected " << Map[i][j] << endl;
                    return 1;
                }
                if(r == 2) {
                    cout << "invalid test case: there is only one start point\n";
                    return -1;
                }
                if(ch == '1') {
                    Map[i][j] = '9';
                }
                else{
                    Map[i][j] = ch;
                }
                if(ch == 'R'){
                    str = i;
                    stc = j;
                    r += 1;
                }
            }
        }
        if(BFS(dis / 2, m, n) < 0) {
            cout << "invalid test case: not all point reachable\n";
            return -1;
        }
         for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << Map[i][j];
            }
            cout << endl;
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << "\t" << dis_to[i][j];
            }
            cout << endl;
        }
        cout << dirty;
    #endif //typeinput

    #ifndef typeinput
        floor >> m >> n >> dis;
         for(int i = 0, r = 0; i < m; ++i) {
            char ch;
            for(int j = 0; j < n; ++j) {
                floor >> ch;
                if(ch != '1' && ch != '0' && ch != 'R') {
                    cout << "invalid test case: floor data unexpected " << Map[i][j] << endl;
                    return 1;
                }
                if(r == 2) {
                    cout << "invalid test case: there is only one start point\n";
                    return -1;
                }
                if(ch == '1') {
                    Map[i][j] = '9';
                }
                else{
                    Map[i][j] = ch;
                }
                if(ch == 'R'){
                    str = i;
                    stc = j;
                    r += 1;
                }
            }
        }
        if(BFS(dis / 2, m, n) < 0) {
            cout << "invalid test case: not all point reachable\n";
            return -1;
        }
        #ifdef debug
            ofstream visitfile;
            visitfile.open("visit.data");
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    visitfile << visit[i][j];
                }
                visitfile << endl;
            }
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    cout << Map[i][j];
                }
                cout << endl;
            }
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    cout << "\t" << dis_to[i][j];
                }
                cout << endl;
            }
            cout << dirty << endl;
        #endif // debug
    #endif // fileinput
    
    // start cleaning
    int clean;
    c_step = 0;
    visit[str][stc] = '0';
    #ifdef debug
        cout << "start cleaning\n";
    #endif
    while(dirty > 0) {
        #ifdef debug
            cout << "cleaning " << endl;
        #endif
        clean = burtal(dis, str, stc);
        if(clean == 0)
            break;
        dirty -= clean;
         #ifdef debug
            cout << "Clean: " << clean << "Left: " << dirty << endl;
        #endif
    }
    #ifdef debug
        cout << "start cleaning reverse: Left: " << dirty << endl;
    #endif
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
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
    tmpout.close();
    #ifdef debug
    cout << c_step + 1 << endl;
    for(int i = 0; i < m; ++i) {
       visitfile << endl;
       for(int j = 0; j < n; ++j) {
            visitfile << visit[i][j];
        }
    }
    visitfile.close();
    #endif // debug
    outstep.open("final.path");
    tmpfile.open("tmp.path");
    outstep << c_step + 1 << endl;
    char cc;
    while(tmpfile >> cc) {
        outstep << cc << " ";
        tmpfile >> cc;
        outstep << cc << endl;     
    }
    outstep << str << " " << stc << endl;
    tmpfile.close();
    outstep.close();
    return 0;
}