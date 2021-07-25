//
// Created by RUIPENG on 2021/7/25.
// Basic Data Structure 04: Stack
// Stack is a very interesting structure, with only one entrance/exit of data
// Data can only be pushed on top or pulled from top.
// Implemented by linklist is the most convenient.
//

#ifndef NJU_REVIEW_LINKSTACK_H
#define NJU_REVIEW_LINKSTACK_H

#include <iostream>
#include <cstdlib>
#include "commons.h"
using namespace std;

class LinkStack {
protected:
    struct Node{
        T val;
        Node* next;
        Node(){val = 0; next = NULL;}
        Node(T data){val = data; next = NULL;}
    };
    Node* head;
    int length;
    void revoke();
public:
    LinkStack(){head = NULL; length = 0;}
    ~LinkStack(){revoke();}
    bool push(T data);
    bool pop();
    T top();
    int getLength(){return length;}
    void clear(){revoke(); length = 0;}
    bool empty(){return length==0;}

    friend ostream& operator << (ostream& out, LinkStack& table);

};

void LinkStackDemo();

#endif //NJU_REVIEW_LINKSTACK_H
