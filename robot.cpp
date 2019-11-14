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
// ver0-2 : add dirty, change way to store floor data, revise BFS


// map for debug
char Map[1005][1005], visit[1005][1005];
int dis_to[1005][1005];
int dirty;


int main() {
    ios_base::sync_with_stdio(false);
    
    int dis, m, n;
    ifstream floor;
    #ifdef debug
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
    #endif //debug

    #ifndef debug
        floor >> dis >> m >> n;
    #endif // runtime

    return 0;
}