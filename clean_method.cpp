#include "clean_method.h"

using namespace std;

int burtal(int pow_max, int str, int stc) {
    int clean = 0, pow_use = 0, r_id = str, c_id = stc;
    int dir;
    my_queue<int> rrow, rcol;

    while(pow_use < pow_max / 2) {
        #ifdef debug
            cout << r_id << " " << c_id << endl;
        #endif // debug
        if(visit[r_id][c_id] == '1') {
            visit[r_id][c_id] = '0';
            clean++;
        }
        dir = find_dir_nv(r_id, c_id, 1);
       
        if(dir == up) {
            rrow.push(r_id);
            rcol.push(c_id);
            r_id = r_id + 1;
            c_id = c_id;
        }
        else if(dir == down) {
             rrow.push(r_id);
             rcol.push(c_id);
            r_id = r_id - 1;
            c_id = c_id;
        }
        else if(dir == left) {
            rrow.push(r_id);
            rcol.push(c_id);
            r_id = r_id;
            c_id = c_id - 1;
        }
        else if(dir == right) {
            rrow.push(r_id);
            rcol.push(c_id);
            r_id = r_id;
            c_id = c_id + 1;
        }
        else {
            break;
        }
        pow_use++;
    }
    #ifdef debug
        cout << "going back to charge\n";
    #endif // debug
    while(pow_use <= pow_max) {
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
        dir = find_dir_nv(r_id, c_id, -1);
        
        if(dir == up) {
            r_id = r_id + 1;
            c_id = c_id;
        }
        else if(dir == down) {
            r_id = r_id - 1;
            c_id = c_id;
        }
        else if(dir == left) {
            r_id = r_id;
            c_id = c_id - 1;
        }
        else if(dir == right) {
            r_id = r_id;
            c_id = c_id + 1;
        }
        else {
            dir = find_dir_v(r_id, c_id, -1);
            if(dir == up) {
            r_id = r_id + 1;
            c_id = c_id;
            }
             else if(dir == down) {
            r_id = r_id - 1;
            c_id = c_id;
            }
             else if(dir == left) {
            r_id = r_id;
            c_id = c_id - 1;
            }
            else if(dir == right) {
            r_id = r_id;
            c_id = c_id + 1;
            }
        }
        pow_use++;
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



int burtal_r(int str, int stc, int idx_r, int idx_c) {
    int clean = 0, r_id = idx_r, c_id = idx_c;
    int min_e, dir;
    my_stack<int> drow, dcol;
    my_queue<int> rrow, rcol;

    #ifdef debug 
        cout << "Back tracing\n";
    #endif // debug
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
        dir = find_dir_nv(r_id, c_id, -1);
        
        if(dir == up) {
            r_id = r_id + 1;
            c_id = c_id;
        }
        else if(dir == down) {
            r_id = r_id - 1;
            c_id = c_id;
        }
        else if(dir == left) {
            r_id = r_id;
            c_id = c_id - 1;
        }
        else if(dir == right) {
            r_id = r_id;
            c_id = c_id + 1;
        }
        else {
            dir = find_dir_v(r_id, c_id, -1);
            if(dir == up) {
                r_id = r_id + 1;
                c_id = c_id;
            }
             else if(dir == down) {
                r_id = r_id - 1;
                c_id = c_id;
            }
             else if(dir == left) {
                r_id = r_id;
                c_id = c_id - 1;
            }
            else if(dir == right) {
                r_id = r_id;
                c_id = c_id + 1;
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

int find_dir_nv(int r_id, int c_id, int d) {
    int dir = unknown, min_e = 5;
    if(Map[r_id + 1][c_id] != '9' && visit[r_id + 1][c_id] == '1') {
            if(dis_to[r_id + 1][c_id] == dis_to[r_id][c_id] + d) {
                dir = up;
                min_e = Map[r_id + 1][c_id] - '0';
            }
        } 
    if(Map[r_id - 1][c_id] != '9' && visit[r_id - 1][c_id] == '1') {
        if(dis_to[r_id - 1][c_id] == dis_to[r_id][c_id] + d) {
           if(Map[r_id - 1][c_id] - '0' < min_e) {
                dir = down;
               min_e = Map[r_id - 1][c_id] - '0';
            }
        }
    } 
    if(Map[r_id][c_id - 1] != '9' && visit[r_id][c_id - 1] == '1') {
        if(dis_to[r_id][c_id - 1] == dis_to[r_id][c_id] + d) {
            if(Map[r_id][c_id - 1] - '0' < min_e) {
                dir = left;
                min_e = Map[r_id][c_id - 1] - '0';
            }
        }
    } 
    if(Map[r_id][c_id + 1] != '9' && visit[r_id][c_id + 1] == '1') {
        if(dis_to[r_id][c_id + 1] == dis_to[r_id][c_id] + d) {
            if(Map[r_id][c_id + 1] - '0' < min_e) {
                dir = right;
                min_e = Map[r_id][c_id + 1] - '0';
            }
        }
    }
    return dir;
}



int find_dir_v(int r_id, int c_id, int d) {
    int dir = unknown, max_e = 0;
    
    if(Map[r_id + 1][c_id] != '9') {
            if(dis_to[r_id + 1][c_id] == dis_to[r_id][c_id] + d) {
                dir = up;
                max_e = Map[r_id + 1][c_id] - '0';
                if(dis_to[r_id + 1][c_id] == 0) {
                    dir = up;
                    max_e = 5;
                }
            }
        } 
    if(Map[r_id - 1][c_id] != '9') {
        if(dis_to[r_id - 1][c_id] == dis_to[r_id][c_id] + d) {
            if(Map[r_id - 1][c_id] - '0' > max_e) {
                dir = down;
                max_e = Map[r_id - 1][c_id] - '0';
            }
            if(dis_to[r_id - 1][c_id] == 0) {
                dir = down;
                max_e = 5;
            }
        }
    } 
    if(Map[r_id][c_id - 1] != '9') {
       if(dis_to[r_id][c_id - 1] == dis_to[r_id][c_id] + d) {
           if(Map[r_id][c_id - 1] - '0' > max_e) {
                dir = left;
                max_e = Map[r_id][c_id - 1] - '0';
            }
            if(dis_to[r_id][c_id - 1] == 0) {
                dir = left;
                max_e = 5;
            }
        }
    } 
    if(Map[r_id][c_id + 1] != '9') {
        if(dis_to[r_id][c_id + 1] == dis_to[r_id][c_id] + d) {
            if(Map[r_id][c_id + 1] - '0' > max_e) {
                dir = right;
                max_e = Map[r_id][c_id + 1] - '0';
            }
           if(dis_to[r_id][c_id + 1] == 0) {
                dir = right;
                max_e = 5;
            }
        }
    }
    return dir;
}
