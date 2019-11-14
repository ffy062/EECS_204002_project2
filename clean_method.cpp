#include "clean_method.h"

using namespace std;

#define unknown 0
#define up 1
#define down 2
#define left 3
#define right 4

int burtal(int pow_max, int str, int stc) {
    int clean = 0, pow_use = 0, r_id = str, c_id = stc;
    int dir, min_e;
    my_queue<int> rrow, rcol;
    while(pow_use < pow_max / 2) {
        rrow.push(r_id);
        rcol.push(c_id);
        if(visit[r_id][c_id] == '1') {
            visit[r_id][c_id] = '0';
            clean++;
        }
        dir = unknown;
        min_e = 5;
        if(Map[r_id + 1][c_id] != '9' && visit[r_id + 1][c_id] == '1') {
            if(dis_to[r_id + 1][c_id] == dis_to[r_id][c_id] + 1) {
                dir = up;
                min_e = Map[r_id + 1][c_id] - '0';
            }
        } 
        if(Map[r_id - 1][c_id] != '9' && visit[r_id - 1][c_id] == '1') {
            if(dis_to[r_id - 1][c_id] == dis_to[r_id][c_id] + 1) {
                if(Map[r_id - 1][c_id] - '0' < min_e) {
                    dir = down;
                    min_e = Map[r_id - 1][c_id] - '0';
                }
            }
        } 
        if(Map[r_id][c_id - 1] != '9' && visit[r_id][c_id - 1] == '1') {
            if(dis_to[r_id][c_id - 1] == dis_to[r_id][c_id] + 1) {
                if(Map[r_id][c_id - 1] - '0' < min_e) {
                    dir = left;
                    min_e = Map[r_id][c_id - 1] - '0';
                }
            }
        } 
        if(Map[r_id][c_id + 1] != '9' && visit[r_id][c_id + 1] == '1') {
            if(dis_to[r_id][c_id + 1] == dis_to[r_id][c_id] + 1) {
                if(Map[r_id][c_id + 1] - '0' < min_e) {
                    dir = right;
                    min_e = Map[r_id][c_id + 1] - '0';
                }
            }
        }
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
            break;
        }
        pow_use++;
    }
    
    while(pow_use <= pow_max) {
        rrow.push(r_id);
        rcol.push(c_id);
        if(r_id == str && c_id == stc) {
            break;
        }
        if(visit[r_id][c_id] == '1') {
            visit[r_id][c_id] = '0';
            clean++;
        }
        dir = unknown;
        min_e = 5;
        if(Map[r_id + 1][c_id] != '9' && visit[r_id + 1][c_id] == '1') {
            if(dis_to[r_id + 1][c_id] == dis_to[r_id][c_id] - 1) {
                dir = up;
                min_e = Map[r_id + 1][c_id] - '0';
            }
        } 
        if(Map[r_id - 1][c_id] != '9' && visit[r_id - 1][c_id] == '1') {
            if(dis_to[r_id - 1][c_id] == dis_to[r_id][c_id] - 1) {
                if(Map[r_id - 1][c_id] - '0' < min_e) {
                    dir = down;
                    min_e = Map[r_id - 1][c_id] - '0';
                }
            }
        } 
        if(Map[r_id][c_id - 1] != '9' && visit[r_id][c_id - 1] == '1') {
            if(dis_to[r_id][c_id - 1] == dis_to[r_id][c_id] - 1) {
                if(Map[r_id][c_id - 1] - '0' < min_e) {
                    dir = left;
                    min_e = Map[r_id][c_id - 1] - '0';
                }
            }
        } 
        if(Map[r_id][c_id + 1] != '9' && visit[r_id][c_id + 1] == '1') {
            if(dis_to[r_id][c_id + 1] == dis_to[r_id][c_id] - 1) {
                if(Map[r_id][c_id + 1] - '0' < min_e) {
                    dir = right;
                    min_e = Map[r_id][c_id + 1] - '0';
                }
            }
        }
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
            if(Map[r_id + 1][c_id] != '9') {
                if(dis_to[r_id + 1][c_id] == dis_to[r_id][c_id] - 1) {
                    dir = up;
                    min_e = Map[r_id + 1][c_id] - '0';
                }
            } 
            if(Map[r_id - 1][c_id] != '9') {
                if(dis_to[r_id - 1][c_id] == dis_to[r_id][c_id] - 1) {
                    if(Map[r_id - 1][c_id] - '0' < min_e) {
                        dir = down;
                        min_e = Map[r_id - 1][c_id] - '0';
                    }
                }
            } 
            if(Map[r_id][c_id - 1] != '9') {
                if(dis_to[r_id][c_id - 1] == dis_to[r_id][c_id] - 1) {
                    if(Map[r_id][c_id - 1] - '0' < min_e) {
                        dir = left;
                        min_e = Map[r_id][c_id - 1] - '0';
                    }
                }
            } 
            if(Map[r_id][c_id + 1] != '9' && visit[r_id][c_id + 1] == '1') {
                if(dis_to[r_id][c_id + 1] == dis_to[r_id][c_id] - 1) {
                    if(Map[r_id][c_id + 1] - '0' < min_e) {
                        dir = right;
                        min_e = Map[r_id][c_id + 1] - '0';
                    }
                }
            }
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
            cout << rrow.front_data() << " " << rcol.front_data() << endl;
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
    while(r_id != str || c_id != stc) {
        drow.push(r_id);
        dcol.push(c_id);
        rrow.push(r_id);
        rcol.push(c_id);
        if(visit[r_id][c_id] == '1') {
            visit[r_id][c_id] = '0';
            clean++;
        }
         dir = unknown;
         min_e = 5;
        if(Map[r_id + 1][c_id] != '9' && visit[r_id + 1][c_id] == '1') {
            if(dis_to[r_id + 1][c_id] == dis_to[r_id][c_id] - 1) {
                dir = up;
                min_e = Map[r_id + 1][c_id] - '0';
            }
        } 
        if(Map[r_id - 1][c_id] != '9' && visit[r_id - 1][c_id] == '1') {
            if(dis_to[r_id - 1][c_id] == dis_to[r_id][c_id] - 1) {
                if(Map[r_id - 1][c_id] - '0' < min_e) {
                    dir = down;
                    min_e = Map[r_id - 1][c_id] - '0';
                }
            }
        } 
        if(Map[r_id][c_id - 1] != '9' && visit[r_id][c_id - 1] == '1') {
            if(dis_to[r_id][c_id - 1] == dis_to[r_id][c_id] - 1) {
                if(Map[r_id][c_id - 1] - '0' < min_e) {
                    dir = left;
                    min_e = Map[r_id][c_id - 1] - '0';
                }
            }
        } 
        if(Map[r_id][c_id + 1] != '9' && visit[r_id][c_id + 1] == '1') {
            if(dis_to[r_id][c_id + 1] == dis_to[r_id][c_id] - 1) {
                if(Map[r_id][c_id + 1] - '0' < min_e) {
                    dir = right;
                    min_e = Map[r_id][c_id + 1] - '0';
                }
            }
        }
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
            if(Map[r_id + 1][c_id] != '9') {
                if(dis_to[r_id + 1][c_id] == dis_to[r_id][c_id] - 1) {
                    dir = up;
                    min_e = Map[r_id + 1][c_id] - '0';
                }
            } 
            if(Map[r_id - 1][c_id] != '9') {
                if(dis_to[r_id - 1][c_id] == dis_to[r_id][c_id] - 1) {
                    if(Map[r_id - 1][c_id] - '0' < min_e) {
                        dir = down;
                        min_e = Map[r_id - 1][c_id] - '0';
                    }
                }
            } 
            if(Map[r_id][c_id - 1] != '9') {
                if(dis_to[r_id][c_id - 1] == dis_to[r_id][c_id] - 1) {
                    if(Map[r_id][c_id - 1] - '0' < min_e) {
                        dir = left;
                        min_e = Map[r_id][c_id - 1] - '0';
                    }
                }
            } 
            if(Map[r_id][c_id + 1] != '9') {
                if(dis_to[r_id][c_id + 1] == dis_to[r_id][c_id] - 1) {
                    if(Map[r_id][c_id + 1] - '0' < min_e) {
                        dir = right;
                        min_e = Map[r_id][c_id + 1] - '0';
                    }
                }
            }
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
    drow.push(r_id);
    dcol.push(c_id);
    rrow.pop();
    rcol.pop();
    while(!drow.check_empty()) {
        cout << drow.top_data() << " " << dcol.top_data() << endl;
        drow.pop();
        dcol.pop();
    }
    while(!rrow.check_empty()) {
        cout << rrow.front_data() << " " << rcol.front_data() << endl;
        rrow.pop();
        rcol.pop();
    }
    
    return clean;
}