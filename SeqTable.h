//
// Created by Ruipeng Ge on 2021/7/10.
// Basic data structure 01: Sequential Table
// Sequential Table is a kind of linear table that save the data by their linear logical order
// Data is saved in a consecutive linear memory space
// Sequential Table can be implemented in either static or dynamic way. The example shows the dynamic one.
//

#ifndef NJU_REVIEW_SEQTABLE_H
#define NJU_REVIEW_SEQTABLE_H

// Configurations
#define defaultSize 100
typedef int T;

#include <iostream>
#include <cstdlib>
using namespace std;


class SeqTable {
protected:
    T* data;        //the linear list
    int maxSize;    //max size of the table
    int length;     //number of element of the current stage

    bool resize(int size);

public:
    SeqTable();
    SeqTable(int size);
    SeqTable(SeqTable& table);
    ~SeqTable(){delete[]data;}
    int getSize() const{return maxSize;}
    int getLength() const{return length;}

    bool pushBack(T x);
    bool insertByLoc(int loc, T x);
    bool removeByLoc(int loc);
    int searchLoc(T x);
    T searchByLoc(int loc);
    bool removeByData(T x);
    bool empty();
    void clear();

    SeqTable& operator = (SeqTable& table);
    T operator [] (int loc);
    bool operator == (SeqTable& table);
    friend istream& operator >> (istream& in, SeqTable& table);
    friend ostream& operator << (ostream& out, SeqTable& table);

};
void SeqTableDemo();

#endif //NJU_REVIEW_SEQTABLE_H
