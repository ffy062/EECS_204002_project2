#ifndef BFS_H
#define BFS_H
#include "my_stl.h"
#include <memory.h>

//#define debug

using namespace std;

extern char Map[1005][1005], visit[1005][1005];
extern int dis_to[1005][1005];
extern int dirty;


pair<int, int> find_start(int m, int n) {
    pair<int, int> pt;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(Map[i][j] == 'R') {
                pt.first = i;
                pt.second = j;
                return pt;
            }
        }
    }
}

int BFS(int dis, int m, int n) {
    // pair to store the point's row and column
    pair<int, int> pt = find_start(m, n), st;
    int col, row;
    // queue to store point
    my_queue<pair<int, int>> next_pt;
    // queue to store minimum distance
    my_queue<int> min_dis;
    int cur_dis;
    
    //initialize
    for(int i = 0; i < m + 2; ++i) {
        memset(visit[i], '0', n + 2);
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            dis_to[i][j] = -1;
        }
    }
    dirty = 0;
    st = pt;
    // start BFS
    next_pt.push(pt);
    min_dis.push(0);
    #ifdef debug
        cout << "starting point: " << pt.first << " " << pt.second << endl;
    #endif
    while(!next_pt.check_empty()) {
        pt = next_pt.front_data();
        cur_dis = min_dis.front_data();
        next_pt.pop();
        min_dis.pop();
        row = pt.first;
        col = pt.second;
        if(visit[row][col] != '0') {
            continue;
        }
        #ifdef debug
            cout << "now traversing " << row << " " << col << endl; 
        #endif
        if(cur_dis > dis) {
            cout << cur_dis << endl;
            return -1;
        }
        dis_to[row][col] = cur_dis;
        visit[row][col] = '1';
        dirty++;
        if(col + 1 < n && Map[row][col + 1] != '9') {
            Map[row][col] += 1;
            pt.second += 1;
            next_pt.push(pt);
            min_dis.push(cur_dis + 1);
            pt.second -= 1;
        }
        if(col - 1 > -1 && Map[row][col - 1] != '9') {
            Map[row][col] += 1;
            pt.second -= 1;
            next_pt.push(pt);
            min_dis.push(cur_dis + 1);
            pt.second += 1;
        }
        if(row + 1 < m && Map[row + 1][col] != '9') {
            Map[row][col] += 1;
            pt.first += 1;
            next_pt.push(pt);
            min_dis.push(cur_dis + 1);
            pt.first -= 1;
        }
        if(row - 1 > -1 && Map[row - 1][col] != '9') {
            Map[row][col] += 1;
            pt.first -= 1;
            next_pt.push(pt);
            min_dis.push(cur_dis + 1);
        }
    }
    dirty--;
    Map[st.first][st.second] = 'R';
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(visit[i][j] == '0' && Map[i][j] == '0') {
                #ifdef debug
                    cout << "not reachable point: " << i << " " <<  j << endl;
                #endif
                return -1;
            }
        }
    }
    return 1;
}

#endif