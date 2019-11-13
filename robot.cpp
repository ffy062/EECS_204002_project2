#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>
#include "my_stl.h"
#include "bfs.h"

#define debug

using namespace std;

// ver0 : construct my_queue, BFS, handling input
// ver0-1 : spilt function to different file 


// map for debug
extern char map[1005][1005], visit[1005][1005];
extern int dis_to[1005][1005];


int main() {
    ios_base::sync_with_stdio(false);
    
    int dis, m, n;
    ifstream floor;

    #ifdef debug
        cin >> m >> n >> dis;
        for(int i = 0, r = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> map[i][j];
                if(map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'R') {
                    cout << "invalid test case: floor data unexpected " << map[i][j] << endl;
                    return 1;
                }
                if(r == 2) {
                    cout << "invalid test case: there is only one start point\n";
                    return -1;
                }
                if(map[i][j] == 'R')
                    r += 1;
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << map[i][j];
            }
            cout << endl;
        }
        if(BFS(dis / 2, m, n) < 0) {
            cout << "invalid test case: not all point reachable\n";
            return -1;
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << "\t" << dis_to[i][j];
            }
            cout << endl;
        }
    #endif //debug

    #ifndef debug
        floor >> dis >> m >> n;
    #endif // runtime

    return 0;
}