//
// Created by RUIPENG on 2021/7/28.
// Basic Data Structure 05: Queue
// Queue is a linear data structure, that data enter from rear but exit from front
// A simple way of implementation is circular array.
//

#ifndef NJU_REVIEW_SEQQUEUE_H
#define NJU_REVIEW_SEQQUEUE_H

#include "commons.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class SeqQueue {
protected:
    T* queue;
    int rear, front;
    int maxSize;
public:
    SeqQueue(int size = defaultSize);
    SeqQueue(const SeqQueue& table);
    ~SeqQueue();
    int getLength() const {return (rear - front + maxSize) % maxSize;}
    int getSize() const {return maxSize;}
    bool empty() const {return rear == front;}
    bool full() const {return (rear+1)%maxSize == front;}

    bool enqueue(T x);
    bool dequeue();
    T getFront() const ;

    friend ostream& operator << (ostream& out, SeqQueue& table);
};

void QueueDemo();


#endif //NJU_REVIEW_SEQQUEUE_H
