//
// Created by RUIPENG on 2021/7/23.
// Basic Data Structure 03: DoubleLinkList
// Expand the Link List, making it able to iterate backward.
// Also can be iterated in a circular way.
//

#ifndef NJU_REVIEW_DOUBLELINKLIST_H
#define NJU_REVIEW_DOUBLELINKLIST_H




#include <iostream>
#include <cstdlib>
#include "commons.h"
using namespace std;


class DoubleLinkList {
protected:
    struct Node{
        T val;
        Node* last;
        Node* next;
        Node() {val = 0; last = NULL; next = NULL;}
        Node(T data) {val = data; last = NULL; next = NULL;}
    };
    Node* head;
    int length;
    Node* current;
    Node* locate(int i, int direction);
    void revoke();

public:
    DoubleLinkList();
    DoubleLinkList(DoubleLinkList& table);
    ~DoubleLinkList(){revoke();}
    int getLength() const{return length;}

    bool pushBack(T x);
    bool insertByLoc(int loc, T x, int direction);
    bool removeByLoc(int loc, int direction);
    int searchLoc(T x, int direction);
    T searchByLoc(int loc, int direction);
    bool removeByData(T x, int direction);
    bool empty();
    void clear();

    void init_iterator(int direction) {if(direction == FORWARD) current = head->next; else current = head->last;}
    bool has_next() {return current != head;}
    T get() {return current->val;}
    void next() {current = current -> next;}
    void last() {current = current -> last;}

    //LinkList& operator = (LinkList& table);
    //T operator [] (int loc) {if(loc>=0) return searchByLoc(loc, FORWARD); else return searchByLoc(-loc-1, BACKWARD);}
    //bool operator == (LinkList& table);
    //friend istream& operator >> (istream& in, LinkList& table);
    friend ostream& operator << (ostream& out, DoubleLinkList& table);
};

void DoubleLinkListDemo();

#endif //NJU_REVIEW_DOUBLELINKLIST_H
