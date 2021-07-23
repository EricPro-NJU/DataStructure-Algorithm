//
// Created by RUIPENG on 2021/7/17.
//

#include "LinkList.h"

void linkListDemo() {
    LinkList table;
    for(int i = 0; i < 5; i++){
        table.pushBack(i);
    }
    for(table.init_iterator(); table.has_next(); table.next()) {
        cout << table.get() << " ";
    }
    cout << endl;
    LinkList newTable(table);
    newTable.insertByLoc(0, 9);
    newTable.insertByLoc(3, 8);
    cout << newTable << endl;
    newTable.removeByLoc(4);
    cout << newTable << endl;
    cout << newTable.searchLoc(4) << endl;
    newTable.removeByData(0);
    cout << newTable << endl;
}

LinkList::Node *LinkList::locate(int i) {
    if(i<0 || i>=length) return NULL;
    Node* p = head->next;
    for(int j = 0; j < i;j++){
        p = p->next;
    }
    return p;
}

void LinkList::revoke() {
    Node* p = head->next;
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

bool LinkList::pushBack(T x) {
    return insertByLoc(length, x);
}

bool LinkList::insertByLoc(int loc, T x) {
    if(loc < 0 || loc > length) return false;
    Node* locNode = loc == 0? head : locate(loc-1);
    Node* dataNode = new Node(x);
    dataNode->next = locNode->next;
    locNode->next = dataNode;
    length ++;
    return true;
}

bool LinkList::removeByLoc(int loc) {
    if(loc < 0 || loc >= length) return false;
    Node* locNode = loc == 0? head : locate(loc-1);
    Node* dataNode = locNode->next;
    locNode->next = dataNode->next;
    delete dataNode;
    length --;
    return true;
}

int LinkList::searchLoc(T x) {
    int i = 0;
    for(Node* p = head->next; p != NULL; p=p->next) {
        if(p->val == x) return i;
        i++;
    }
    return -1;
}

T LinkList::searchByLoc(int loc) {
    if(loc < 0 || loc >= length) {
        cerr << "Error! searching invalid location.\n";
        return 0;
    }
    return locate(loc)->val;
}

bool LinkList::removeByData(T x) {
    Node* p = head;
    for(;p->next!=NULL;p=p->next) {
        if(p->next->val==x) {
            Node* to_delete = p->next;
            p->next = p->next->next;
            delete to_delete;
            length --;
            return true;
        }
    }
    return false;
}

bool LinkList::empty() {
    return length == 0;
}

void LinkList::clear() {
    revoke();
    length = 0;
}

ostream &operator<<(ostream &out, LinkList &table) {
    out << "LinkListInfo: Length " << table.length;
    out << ". [";
    LinkList::Node* p = table.head->next;
    for(; p!=NULL; p=p->next) {
        out << p->val;
        if (p->next != NULL) out << ", ";
    }
    out<< "]";
    return out;
}






