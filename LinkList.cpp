//
// Created by RUIPENG on 2021/7/17.
//

#include "LinkList.h"

LinkList::Node *LinkList::locate(int i) {
    if(i<0 || i>=length) return NULL;
    Node* p = head->next;
    for(int j = 0; j < i;j++){
        p = p->next;
    }
    return p;
}

LinkList::Node *LinkList::search(T data) {
    for(Node* p = head->next; p != NULL; p = p->next) {
        if(p->val == data) return p;
    }
    return NULL;
}

void LinkList::revoke() {
    Node* p;
    while(p!=NULL) {
        Node* link = p;
        p = p->next;
        delete link;
    }
}

LinkList::LinkList() {
    length = 0;
    head = new Node;
}

LinkList::LinkList(LinkList &list) {
    this->length = list.length;
    this->head = new Node;
    Node* p = this->head;
    list.init_iterator();
    while(list.has_next()) {
        Node* node = new Node(list.get());
        p->next = node;
        p = p->next;
        list.next();
    }
}


