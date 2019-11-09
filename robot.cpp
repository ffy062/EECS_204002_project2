#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>

#define debug

using namespace std;

// ver0 : construct my_queue, BFS, handling input


// map for debug
char map[1005][1005], visit[1005][1005];
int dis_to[1005][1005];

// node for  my queue
template <class T>
class node{
public:
    T data;
    node* next;
    node(): next(nullptr) {}
    node(T data):data(data), next(nullptr){}
};

// my queue
template <class T>
class my_queue{
private:
    node<T>* head;
    node<T>* tail;
    int size;
public:
    my_queue() {
        head = 0;
        tail = 0;
        size = 0;
    }
    void push(T val) {
        size++;
        node<T>* tmp = new node<T>(val);
        if(head != 0) {
            tail->next = tmp;
            tail = tmp;
            return;
        }
        head = tmp;
        tail = tmp;
        return;
    }
    void pop() {
        if(size != 0) {
            size--;
            if(head != tail) {
                node<T>* tmp = head;
                head = head->next;
                delete tmp;
                return;
            }
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        return;
    }
    T front_data() {
        if(size != 0) {
            return head->data;
        }
    }
    bool check_empty() {
        return (size == 0)? true : false;
    }
    void clear() {
        while(head != nullptr) {
            node<T>* tmp = head->next;
            delete head;
            head = tmp;
        }
        size = 0;
        head = 0;
        tail = 0;
        return;
    }
};


template<class T, class U>
class my_pair{
public:
    T first;
    U second;
    my_pair(){}
    my_pair(T first_d, U second_d){
        first = first_d;
        second = second_d;
    }
};



pair<int, int> find_start(int m, int n) {
    pair<int, int> pt;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(map[i][j] == 'R') {
                pt.first = i;
                pt.second = j;
                return pt;
            }
        }
    }
}

int BFS(int dis, int m, int n) {
    // pair to store the point's row and column
    pair<int, int> pt = find_start(m, n);
    int col, row;
    // queue to store point
    my_queue<pair<int, int>> next_pt;
    // queue to store minimum distance
    my_queue<int> min_dis;
    int cur_dis;
    for(int i = 0; i < m; ++i) {
        memset(visit[i], '0', n);
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            dis_to[i][j] = -1;
        }
    }
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
        if(map[row][col] == '1' || visit[row][col] == '1') {
            continue;
        }
        #ifdef debug
            cout << "now traversing " << row << " " << col << endl; 
        #endif
        if(cur_dis > dis) {
            cout << cur_dis << endl;
            return -1;
        }
        visit[row][col] = '1';
        dis_to[row][col] = cur_dis;
        if(col + 1 < n) {
            pt.second += 1;
            next_pt.push(pt);
            min_dis.push(cur_dis + 1);
            pt.second -= 1;
        }
        if(col - 1 > -1) {
            pt.second -= 1;
            next_pt.push(pt);
            min_dis.push(cur_dis + 1);
            pt.second += 1;
        }
        if(row + 1 < m) {
            pt.first += 1;
            next_pt.push(pt);
            min_dis.push(cur_dis + 1);
            pt.first -= 1;
        }
        if(row - 1 > -1) {
            pt.first -= 1;
            next_pt.push(pt);
            min_dis.push(cur_dis + 1);
        }
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(visit[i][j] == '0' && map[i][j] == '0') {
                #ifdef debug
                    cout << "not reachable point: " << i << " " <<  j << endl;
                #endif
                return -1;
            }
        }
    }
    return 1;
}






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