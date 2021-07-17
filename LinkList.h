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
    Node* search(T data);
    void revoke();
public:
    LinkList();
    LinkList(LinkList& list);
    ~LinkList();
    int getLength() const{return length;}

    bool pushBack(T x);
    bool insertByLoc(int loc, T x);
    bool removeByLoc(int loc);
    int searchLoc(T x);
    T searchByLoc(int loc);
    bool removeByData(T x);
    bool empty();
    void clear();

    void init_iterator();
    bool has_next();
    T get();
    void next();

    LinkList& operator = (LinkList& table);
    T operator [] (int loc);
    bool operator == (LinkList& table);
    friend istream& operator >> (istream& in, LinkList& table);
    friend ostream& operator << (ostream& out, LinkList& table);
};


#endif //NJU_REVIEW_LINKLIST_H
