#include "clean_method.h"

using namespace std;

int burtal(int pow_max, int str, int stc) {
    int clean = 0, pow_use = 0, r_id = str, c_id = stc;
    int dir, pri = up;
    my_queue<int> rrow, rcol;

    while(dis_to[r_id][c_id] < pow_max - pow_use) {
        #ifdef debug
            cout << r_id << " " << c_id << endl;
        #endif // debug
        if(visit[r_id][c_id] == '1') {
            visit[r_id][c_id] = '0';
            clean++;
        }
        dir = find_dir_nv(r_id, c_id, 1, pri);
        if(dir == up) {
            rrow.push(r_id);
            rcol.push(c_id);
            r_id = r_id + 1;
            c_id = c_id;
            pri = up;
        }
        else if(dir == down) {
             rrow.push(r_id);
             rcol.push(c_id);
            r_id = r_id - 1;
            c_id = c_id;
            pri = down;
        }
        else if(dir == left) {
            rrow.push(r_id);
            rcol.push(c_id);
            r_id = r_id;
            c_id = c_id - 1;
            pri = left;
        }
        else if(dir == right) {
            rrow.push(r_id);
            rcol.push(c_id);
            r_id = r_id;
            c_id = c_id + 1;
            pri = right;
        }
        else {
            dir = find_dir_nv(r_id, c_id, -1, pri);
            if(dir == unknown) {
                dir = find_dir_v(r_id, c_id, 1, pri);
                //dir = find_dir_d(r_id, c_id, dir, (pow_max/5 - pow_use) - 2);
                if(dir == unknown) {
                    dir = find_dir_v(r_id, c_id, -1, pri);
                    rrow.push(r_id);
                    rcol.push(c_id);
                    if(dir == up) {
                        r_id = r_id + 1;
                        c_id = c_id;
                        pri = up;
                    }
                    else if(dir == down) {
                        r_id = r_id - 1;
                        c_id = c_id;
                        pri = down;
                    }
                    else if(dir == left) {
                        r_id = r_id;
                        c_id = c_id - 1;
                        pri = left;
                    }
                    else if(dir == right) {
                        r_id = r_id;
                        c_id = c_id + 1;
                        pri = right;
                    }
                }
                else {
                    rrow.push(r_id);
                    rcol.push(c_id);
                    if(dir == up) {
                        r_id = r_id + 1;
                        c_id = c_id;
                        pri = up;
                    }
                    else if(dir == down) {
                        r_id = r_id - 1;
                        c_id = c_id;
                        pri = down;
                    }
                    else if(dir == left) {
                        r_id = r_id;
                        c_id = c_id - 1;
                        pri = left;
                    }
                    else if(dir == right) {
                        r_id = r_id;
                        c_id = c_id + 1;
                        pri = right;
                    }
                }
            }
            else {
                rrow.push(r_id);
                rcol.push(c_id);
                if(dir == up) {
                    r_id = r_id + 1;
                    c_id = c_id;
                    pri = up;
                }
                else if(dir == down) {
                    r_id = r_id - 1;
                    c_id = c_id;
                    pri = down;
                }
                else if(dir == left) {
                    r_id = r_id;
                    c_id = c_id - 1;
                    pri = left;
                }
                else if(dir == right) {
                    r_id = r_id;
                    c_id = c_id + 1;
                    pri = right;
                }
            }
        }
        pow_use++;
    }
    #ifdef debug
        cout << "going back to charge\n";
    #endif // debug
    while(pow_use < pow_max) {
        if(r_id == str && c_id == stc) {
            break;
        }
        rrow.push(r_id);
        rcol.push(c_id);
        #ifdef debug 
            cout << r_id << " " << c_id << endl;
        #endif // debug 
        if(visit[r_id][c_id] == '1') {
            visit[r_id][c_id] = '0';
            clean++;
        }
        dir = find_dir_nv(r_id, c_id, -1, pri);
        
        if(dir == up) {
            r_id = r_id + 1;
            c_id = c_id;
            pri = up;
        }
        else if(dir == down) {
            r_id = r_id - 1;
            c_id = c_id;
            pri = down;
        }
        else if(dir == left) {
            r_id = r_id;
            c_id = c_id - 1;
            pri = left;
        }
        else if(dir == right) {
            r_id = r_id;
            c_id = c_id + 1;
            pri = right;
        }
        else {
            dir = find_dir_v(r_id, c_id, -1, pri);
            if(dir == up) {
            r_id = r_id + 1;
            c_id = c_id;
            pri = up;
            }
             else if(dir == down) {
            r_id = r_id - 1;
            c_id = c_id;
            pri = down;
            }
             else if(dir == left) {
            r_id = r_id;
            c_id = c_id - 1;
            pri = left;
            }
            else if(dir == right) {
            r_id = r_id;
            c_id = c_id + 1;
            pri = right;
            }
        }
        pow_use++;
    }
    if(r_id != str || c_id != stc) {
        cout << "out of battery\n";
        exit(1);
    }
    if(clean != 0) {
        while(!rrow.check_empty()) {
            tmpout << rrow.front_data() << " " << rcol.front_data() << endl;
            c_step++;
            rrow.pop();
            rcol.pop();
        }
    }
    return clean;
}



int burtal_r(int str, int stc, int idx_r, int idx_c, int pow_max) {
    int clean = 0, r_id = idx_r, c_id = idx_c;
    int min_e, dir, pri = up, more_s;
    my_stack<int> drow, dcol, tdrow, tdcol;
    my_queue<int> rrow, rcol, trrow, trcol;

    #ifdef debug 
        cout << "Back tracing\n";
    #endif // debug
    more_s = pow_max / 2 - dis_to[idx_r][idx_c] - 1;
    /*for(int i = 0; i < more_s; ++i) {
        if(visit[r_id][c_id] == '1') {
            visit[r_id][c_id] = '0';
            clean++;
        }
        dir = find_dir_nv(r_id, c_id, 1, pri);
        if(dir == unknown) {
            dir = find_dir_nv(r_id, c_id, -1, pri);
            if(dir == unknown) {
                break;
            }
            else {
                tdrow.push(r_id);
                tdcol.push(c_id);
                trrow.push(r_id);
                trcol.push(c_id);
                if(dir == up) {
                r_id = r_id + 1;
                c_id = c_id;
                pri = up;
                }
                else if(dir == down) {
                r_id = r_id - 1;
                c_id = c_id;
                pri = down;
                }
                else if(dir == left) {
                r_id = r_id;
                c_id = c_id - 1;
                pri = left;
                }
                else if(dir == right) {
                r_id = r_id;
                c_id = c_id + 1;
                pri = right;
                }
            }
        }
        else {
        tdrow.push(r_id);
        tdcol.push(c_id);
        trrow.push(r_id);
        trcol.push(c_id);
        if(dir == up) {
            r_id = r_id + 1;
            c_id = c_id;
            pri = up;
        }
        else if(dir == down) {
            r_id = r_id - 1;
            c_id = c_id;
            pri = down;
        }
        else if(dir == left) {
            r_id = r_id;
            c_id = c_id - 1;
            pri = left;
        }
        else if(dir == right) {
            r_id = r_id;
            c_id = c_id + 1;
            pri = right;
        }
        }
    }*/
    while(r_id != str || c_id != stc) {
        drow.push(r_id);
        dcol.push(c_id);
        rrow.push(r_id);
        rcol.push(c_id);
        #ifdef debug
            cout << r_id << " " << c_id << endl;
        #endif // debug
        if(visit[r_id][c_id] == '1') {
            visit[r_id][c_id] = '0';
            clean++;
        }
        dir = find_dir_nv(r_id, c_id, -1, pri);
        
        if(dir == up) {
            r_id = r_id + 1;
            c_id = c_id;
            pri = up;

        }
        else if(dir == down) {
            r_id = r_id - 1;
            c_id = c_id;
            pri = down;
        }
        else if(dir == left) {
            r_id = r_id;
            c_id = c_id - 1;
            pri = left;
        }
        else if(dir == right) {
            r_id = r_id;
            c_id = c_id + 1;
            pri = right;
        }
        else {
            dir = find_dir_v(r_id, c_id, -1, pri);
            if(dir == up) {
                r_id = r_id + 1;
                c_id = c_id;
                pri = up;
            }
             else if(dir == down) {
                r_id = r_id - 1;
                c_id = c_id;
                pri = down;
            }
             else if(dir == left) {
                r_id = r_id;
                c_id = c_id - 1;
                pri = left;
            }
            else if(dir == right) {
                r_id = r_id;
                c_id = c_id + 1;
                pri = right;
            }
        }
    }
    #ifdef debug
        cout << "End back tracing\n";
    #endif // debug
    drow.push(r_id);
    dcol.push(c_id);
    rrow.pop();
    rcol.pop();
    while(!drow.check_empty()) {
        #ifdef debug
            cout << drow.top_data() << " " << dcol.top_data() << endl;
        #endif // debug
        tmpout << drow.top_data() << " " << dcol.top_data() << endl;
        c_step++;
        drow.pop();
        dcol.pop();
    }
    while(!rrow.check_empty()) {
        #ifdef debug
            cout << rrow.front_data() << " " << rcol.front_data() << endl;
        #endif // debug
        tmpout << rrow.front_data() << " " << rcol.front_data() << endl;
        c_step++;
        rrow.pop();
        rcol.pop();
    }
    return clean;
}

int find_dir_nv(int r_id, int c_id, int d, int pri) {
    int dir = unknown, min_e = 5, min_ed[4];
    min_ed[0] = visit[r_id+2][c_id] - '0' + visit[r_id][c_id] - '0' + visit[r_id+1][c_id-1] - '0' + visit[r_id+1][c_id+1] - '0'; // up
    min_ed[1] = visit[r_id][c_id] - '0' + visit[r_id-2][c_id] - '0' + visit[r_id-1][c_id-1] - '0' + visit[r_id-1][c_id+1] - '0'; // down
    min_ed[2] = visit[r_id+1][c_id-1] - '0' + visit[r_id-1][c_id-1] - '0' + visit[r_id][c_id-2] - '0' + visit[r_id][c_id] - '0'; // left
    min_ed[3] = visit[r_id+1][c_id+1] - '0' + visit[r_id-1][c_id+1] - '0' + visit[r_id][c_id] - '0' + visit[r_id][c_id+2] - '0'; // right
    int tmp[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    for(int i = 0; i < 4; ++i) {
        int idx = (i + pri - 1) % 4;
        if(Map[r_id + tmp[idx][0]][c_id + tmp[idx][1]] != '9' && visit[r_id + tmp[idx][0]][c_id + tmp[idx][1]] == '1') {
                if(dis_to[r_id + tmp[idx][0]][c_id + tmp[idx][1]] == dis_to[r_id][c_id] + d) {
                    if(min_ed[idx] < min_e) {
                        dir = idx + 1;
                        min_e = min_ed[idx];
                    }
                    if(dis_to[r_id + tmp[idx][0]][c_id + tmp[idx][1]] == 0) {
                        dir = idx + 1;
                        min_e = min_ed[idx];
                        break;
                    }
                }
        } 
    }
    return dir;
}



int find_dir_v(int r_id, int c_id, int d, int pri) {
    int dir = unknown, max_e = -1, max_ed[4];
    max_ed[0] = visit[r_id+2][c_id] - '0' + visit[r_id][c_id] - '0' + visit[r_id+1][c_id-1] - '0' + visit[r_id+1][c_id+1] - '0';
    max_ed[1] = visit[r_id][c_id] - '0' + visit[r_id-2][c_id] - '0' + visit[r_id-1][c_id-1] - '0' + visit[r_id-1][c_id+1] - '0';
    max_ed[2] = visit[r_id+1][c_id-1] - '0' + visit[r_id-1][c_id-1] - '0' + visit[r_id][c_id-2] - '0' + visit[r_id][c_id] - '0';
    max_ed[3] = visit[r_id+1][c_id+1] - '0' + visit[r_id-1][c_id+1] - '0' + visit[r_id][c_id] - '0' + visit[r_id][c_id+2] - '0';
    int tmp[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    if(pri == unknown) {
        pri = up;
    }
    
    for(int i = 0; i < 4; ++i) {
        int idx = (i + pri - 1) % 4;
        if(Map[r_id + tmp[idx][0]][c_id + tmp[idx][1]] != '9') {
                if(dis_to[r_id + tmp[idx][0]][c_id + tmp[idx][1]] == dis_to[r_id][c_id] + d) {
                    if(max_ed[idx] > max_e) {
                        dir = idx + 1;
                        max_e = max_ed[idx];
                    }
                    if(dis_to[r_id + tmp[idx][0]][c_id + tmp[idx][1]] == 0) {
                        dir = idx + 1;
                        max_e = max_ed[idx];
                        break;
                    }
                }
        } 
    }
    return dir;
}



int find_dir_r(int r_id, int c_id, int pri) {
    int search, dir, max_pt[4], cur_max;
     int tmp[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    search = dis_to[r_id][c_id] / 3 + 1;
    cur_max = -1;

   for(int i = 0; i < 4; ++i) {
        int idx = (i + pri - 1) % 4;
        if(dis_to[r_id + tmp[idx][0]][c_id + tmp[idx][1]] == dis_to[r_id][c_id] - 1) {
            if(dis_to[r_id + tmp[idx][0]][c_id + tmp[idx][1]] == 0) {
                dir = idx + 1;
                break;
            }
            max_pt[idx] = BFS_lim(dis_to[r_id][c_id] / 15 + 2, r_id + tmp[idx][0], c_id + tmp[idx][1], 1);
            if(max_pt[idx] > cur_max) {
                dir = idx + 1;
                cur_max = max_pt[idx];
            }
        }
    }
    return dir;
}

int find_dir_d(int r_id, int c_id, int pri, int dis) {
    int dir = unknown, max_pt[4], cur_max;
    int tmp[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    cur_max = 0;

   for(int i = 0; i < 4; ++i) {
        int idx = i;
        if(dis_to[r_id + tmp[idx][0]][c_id + tmp[idx][1]] == dis_to[r_id][c_id] + 1) {
            max_pt[idx] = BFS_unlim(dis, r_id + tmp[idx][0], c_id + tmp[idx][1]);
            if(max_pt[idx] > cur_max) {
                dir = idx + 1;
                cur_max = max_pt[idx];
            }
        }
    }

    return dir;
}



int BFS_lim(int dis, int r_id, int c_id, int d) {
    // pair to store the point's row and column
    pair<int, int> pt, st;
    int col, row, cnt;
    // queue to store point
    my_queue<pair<int, int>> next_pt;
    //initialize
    for(int i = 0; i < m + 2; ++i) {
        memset(isv[i], '0', n + 2);
    }
    
    pt.first = r_id;
    pt.second = c_id;
    cnt = 0;

    // start BFS
    next_pt.push(pt);
    #ifdef debug
        cout << "starting point: " << pt.first << " " << pt.second << endl;
    #endif
    //cout << dis << endl;
    while(!next_pt.check_empty()) {
        pt = next_pt.front_data();
        next_pt.pop();
        row = pt.first;
        col = pt.second;
        if(isv[row][col] == '1') {
            continue;
        }
        isv[row][col] = '1';
        #ifdef debug
            cout << "now traversing " << row << " " << col << endl; 
        #endif
        if(dis_to[row][col] - dis_to[row][col + 1] == d && (dis_to[r_id][c_id] - dis_to[row][col + 1])*d < dis) {
            pt.second += 1;
            next_pt.push(pt);
            if(visit[row][col + 1] == '1') {
                cnt++;
            }
            pt.second -= 1;
        }
        if(dis_to[row][col] - dis_to[row][col - 1] == d && (dis_to[r_id][c_id] - dis_to[row][col - 1])*d < dis) {
            pt.second -= 1;
            next_pt.push(pt);
            if(visit[row][col - 1] == '1') {
                cnt++;
            }
            pt.second += 1;
        }
        if(dis_to[row][col] - dis_to[row + 1][col] == d && (dis_to[r_id][c_id] - dis_to[row + 1][col])*d < dis) {
            pt.first += 1;
            next_pt.push(pt);
            if(visit[row + 1][col] == '1') {
                cnt++;
            }
            pt.first -= 1;
        }
        if(dis_to[row][col] - dis_to[row - 1][col] == d && (dis_to[r_id][c_id] - dis_to[row - 1][col])*d < dis) {
            pt.first -= 1;
            next_pt.push(pt);
            if(visit[row - 1][col] == '1') {
                cnt++;
            }
        }
    }

    return cnt;
}


int BFS_unlim(int dis, int r_id, int c_id) {
    // pair to store the point's row and column
    pair<int, int> pt, st;
    int col, row, cnt;
    // queue to store point
    my_queue<pair<int, int>> next_pt;
    //initialize
    for(int i = 0; i < m + 2; ++i) {
        memset(isv[i], '0', n + 2);
    }

    pt.first = r_id;
    pt.second = c_id;
    cnt = 0;

    // start BFS
    next_pt.push(pt);
    #ifdef debug
        cout << "starting point: " << pt.first << " " << pt.second << endl;
    #endif
    //cout << dis << endl;
    int i = 0;

    while(!next_pt.check_empty()) {
        i++;
        pt = next_pt.front_data();
        next_pt.pop();
        row = pt.first;
        col = pt.second;
        if(isv[row][col] == '1') {
            continue;
        }
        if(visit[row][col] == '1') {
            cnt++;
        }
        isv[row][col] = '1';
        #ifdef debug
                cout << "now traversing " << row << " " << col << endl;
        #endif
        if(col + 1 < n && Map[row][col + 1] != '9' && abs(dis_to[r_id][c_id] - dis_to[row][col + 1]) < dis) {
            pt.second += 1;
            next_pt.push(pt);
            pt.second -= 1;
        }
        if(col - 1 > -1 && Map[row][col - 1] != '9' && abs(dis_to[r_id][c_id] - dis_to[row][col - 1]) < dis) {
            pt.second -= 1;
            next_pt.push(pt);
            pt.second += 1;
        }
        if(row + 1 < m && Map[row + 1][col] != '9' && abs(dis_to[r_id][c_id] - dis_to[row + 1][col]) < dis) {
            pt.first += 1;
            next_pt.push(pt);
            pt.first -= 1;
        }
        if(row - 1 > -1 && Map[row - 1][col] != '9' && abs(dis_to[r_id][c_id] - dis_to[row - 1][col]) < dis) {
            pt.first -= 1;
            next_pt.push(pt);
            pt.first += 1;
        }
    }

    return cnt;
}



