//
// Created by RUIPENG on 2021/7/23.
//

#include "DoubleLinkList.h"

DoubleLinkList::Node *DoubleLinkList::locate(int i, int direction) {
    if(i<0 || i>=length) return NULL;
    if(direction != FORWARD && direction != BACKWARD) return NULL;
    Node* p = direction == FORWARD ? head -> next : head -> last;
    for(int j = 0; j < i; j++){
        p = direction == FORWARD ? p->next : p->last;
    }
    return p;
}

void DoubleLinkList::revoke() {
    Node* p = head->next;
    while(p!=head) {
        Node* to_delete = p;
        p = p->next;
        delete to_delete;
    }
}

DoubleLinkList::DoubleLinkList() {
    length = 0;
    head = new Node;
    head->last = head;
    head->next = head;
}

DoubleLinkList::DoubleLinkList(DoubleLinkList &table) {
    this->length = table.length;
    head = new Node;
    head->last = head;
    head->next = head;
    table.init_iterator(FORWARD);
    Node* p = this->head;
    while(table.has_next()) {
        Node* node = new Node(table.get());
        node->next = p->next;
        node->last = p;
        p->next = node;
        table.next();
    }
}

bool DoubleLinkList::pushBack(T x) {
    return insertByLoc(length, x, FORWARD);
}

bool DoubleLinkList::insertByLoc(int loc, T x, int direction) {
    if(loc < 0 || loc > length) return false;
    if(direction != FORWARD && direction != BACKWARD) return false;
    if(direction == FORWARD) {
        Node* pos = loc == 0 ? head : locate(loc-1, FORWARD);
        Node* newNode = new Node(x);
        newNode->next = pos->next;
        newNode->last = pos;
        pos->next = newNode;
        length ++;
        return true;
    }
    else {
        Node* pos = loc == 0 ? head : locate(loc-1, BACKWARD);
        Node* newNode = new Node(x);
        newNode->last = pos->last;
        newNode->next = pos;
        pos->last = newNode;
        length ++;
        return true;
    }
}

bool DoubleLinkList::removeByLoc(int loc, int direction) {
    return false;
}


