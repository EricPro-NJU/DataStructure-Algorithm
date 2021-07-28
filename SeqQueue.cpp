//
// Created by gerui on 2021/7/28.
//

#include "SeqQueue.h"

void QueueDemo(){
    SeqQueue queue;
    queue.enqueue(2);
    queue.enqueue(5);
    queue.enqueue(8);
    cout << queue <<endl;
    cout << queue.getFront() << endl;
    queue.dequeue();
    cout << queue << endl;
}


SeqQueue::SeqQueue(int size) {
    maxSize = size;
    front = rear = 0;
    queue = new T[size];
}

SeqQueue::SeqQueue(const SeqQueue &table) {
    this->maxSize = table.maxSize;
    this->front = table.front;
    this->rear = table.rear;
    this->queue = new T[this->maxSize];
    for(int i = front; i != rear; i = (i+1)%this->maxSize) {
        this->queue[i] = table.queue[i];
    }
}

SeqQueue::~SeqQueue() {
    delete[]queue;
}

bool SeqQueue::enqueue(T x) {
    if (full()) {
        cerr << "Queue is full. Enqueue failed." << endl;
        return false;
    }
    queue[rear] = x;
    rear = (rear + 1)%maxSize;
    return true;
}

bool SeqQueue::dequeue() {
    if (empty()) {
        cerr << "Queue is empty. Dequeue failed." <<endl;
        return false;
    }
    front = (front + 1)%maxSize;
    return true;
}

T SeqQueue::getFront() const {
    if (empty()) {
        cerr << "Queue is empty. getFront failed." <<endl;
        return false;
    }
    return queue[front];
}

ostream &operator<<(ostream &out, SeqQueue &table) {
    out << "QueueInfo: Length " << table.getLength();
    out << ". FRONT-> [";
    int i;
    for(i = table.front; i != table.rear; i = (i+1)%table.maxSize) {
        out << table.queue[i];
        if((i+1)%table.maxSize != table.rear) out << ", ";
    }
    out<< "] <-REAR";
    return out;
}






