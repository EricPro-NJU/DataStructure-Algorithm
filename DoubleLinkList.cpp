//
// Created by RUIPENG on 2021/7/23.
//

#include "DoubleLinkList.h"

void DoubleLinkListDemo (){
    DoubleLinkList table;
    for(int i = 0; i < 5; i++){
        table.pushBack(i);
    }
    for(table.init_iterator(FORWARD); table.has_next(); table.next()) {
        cout << table.get() << " ";
    }
    cout << endl;
    for(table.init_iterator(BACKWARD); table.has_next(); table.last()) {
        cout << table.get() << " ";
    }
    cout << endl;
    DoubleLinkList newTable(table);
    cout << newTable << endl;
    newTable.insertByLoc(0, 9, FORWARD);
    newTable.insertByLoc(3, 8, BACKWARD);
    cout << newTable << endl;
    newTable.removeByLoc(4, FORWARD);
    cout << newTable << endl;
    cout << newTable.searchLoc(4, BACKWARD) << endl;
    newTable.removeByData(0, BACKWARD);
    cout << newTable << endl;
}

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
        p->next->last = node;
        p->next = node;
        table.next();
        p=p->next;
    }
}

bool DoubleLinkList::pushBack(T x) {
    return insertByLoc(length, x, FORWARD);
}

bool DoubleLinkList::insertByLoc(int loc, T x, int direction) {
    if(loc < 0 || loc > length) return false;
    if(direction != FORWARD && direction != BACKWARD) return false;
    if(direction == FORWARD) {
        Node* pos = loc == length? head : locate(loc, FORWARD);
        Node* newNode = new Node(x);
        newNode->next = pos;
        newNode->last = pos->last;
        pos->last->next = newNode;
        pos->last = newNode;
        length ++;
        return true;
    }
    else {
        Node* pos = loc == length? head : locate(loc, BACKWARD);
        Node* newNode = new Node(x);
        newNode->last = pos;
        newNode->next = pos->next;
        pos->next->last = newNode;
        pos->next = newNode;
        length ++;
        return true;
    }
}

bool DoubleLinkList::removeByLoc(int loc, int direction) {
    if(loc < 0 || loc >= length) return false;
    if(direction != FORWARD && direction != BACKWARD) return false;

    Node* pos = loc == 0 ? head : locate(loc, direction);
    pos->last->next = pos->next;
    pos->next->last = pos->last;
    delete pos;
    length --;
    return true;

}

int DoubleLinkList::searchLoc(T x, int direction) {
    int i = 0;
    Node* p;
    for(p = direction==FORWARD?head->next:head->last; p!=NULL; p=direction==FORWARD?p->next:p->last) {
        if(p->val == x) return i;
        i++;
    }
    return -1;
}

T DoubleLinkList::searchByLoc(int loc, int direction) {
    if(loc < 0 || loc >= length) {
        cerr << "Error! searching invalid location.\n";
        return 0;
    }
    return locate(loc, direction)->val;
}

bool DoubleLinkList::removeByData(T x, int direction) {
    Node* p;
    for(p = direction==FORWARD?head->next:head->last; p!=NULL; p=direction==FORWARD?p->next:p->last) {
        if(p->val == x) {
            p->last->next = p->next;
            p->next->last = p->last;
            delete p;
            length --;
            return true;
        }
    }
    return false;
}

bool DoubleLinkList::empty() {
    return length == 0;
}

void DoubleLinkList::clear() {
    revoke();
    length = 0;
}

ostream &operator<<(ostream &out, DoubleLinkList &table) {
    out << "LinkListInfo: Length " << table.length;
    out << ". [";
    DoubleLinkList::Node* p = table.head->next;
    for(; p!=table.head; p=p->next) {
        out << p->val;
        if (p->next != table.head) out << ", ";
    }
    out<< "]";
    return out;
}


