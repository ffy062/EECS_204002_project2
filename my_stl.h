#ifndef MY_STL_H
#define MY_STL_H

#include <iostream>
using namespace std;

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

#endif