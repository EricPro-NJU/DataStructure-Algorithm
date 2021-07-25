//
// Created by RUIPENG on 2021/7/17.
// Basic data structure 02: linked list
// Another way to store linear data, way more flexible at modifying but expensive at random visit.
// Data is not stored consecutively
// An additional head link is implemented to make coding more convenient
//

#ifndef NJU_REVIEW_LINKLIST_H
#define NJU_REVIEW_LINKLIST_H

// Configurations
typedef int T;

#include <iostream>
#include <cstdlib>
using namespace std;

class LinkList {
protected:
    struct Node{
        T val;
        Node* next;
        Node() {val = 0; next = NULL;}
        Node(T data) {val = data; next = NULL;}
    };
    Node* head;
    int length;
    Node* current;
    Node* locate(int i);
    void revoke();
public:
    LinkList();
    LinkList(LinkList& list);
    ~LinkList(){revoke();}
    int getLength() const{return length;}

    bool pushBack(T x);
    bool insertByLoc(int loc, T x);
    bool removeByLoc(int loc);
    int searchLoc(T x);
    T searchByLoc(int loc);
    bool removeByData(T x);
    bool empty();
    void clear();

    void init_iterator() {current = head->next;}
    bool has_next() {return current != NULL;}
    T get() {return current->val;}
    void next() {current = current -> next;}

    //LinkList& operator = (LinkList& table);
    //T operator [] (int loc) {return searchByLoc(loc);}
    //bool operator == (LinkList& table);
    //friend istream& operator >> (istream& in, LinkList& table);
    friend ostream& operator << (ostream& out, LinkList& table);
};

void linkListDemo();


#endif //NJU_REVIEW_LINKLIST_H
