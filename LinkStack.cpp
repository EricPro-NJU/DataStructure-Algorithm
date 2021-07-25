//
// Created by RUIPENG on 2021/7/25.
//

#include "LinkStack.h"
void LinkStackDemo(){
    LinkStack st;
    st.push(5);
    st.push(3);
    st.push(99);
    st.push(108);
    cout << st << endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<< st <<endl;
}

void LinkStack::revoke() {
    Node* p = head;
    while(p!=NULL) {
        Node* to_delete = p;
        p=p->next;
        delete to_delete;
    }
}

bool LinkStack::push(T data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
    length++;
    return true;
}

bool LinkStack::pop() {
    if(length == 0) return false;
    Node* node = head;
    head = head->next;
    delete node;
    length --;
    return false;
}

T LinkStack::top() {
    if(length == 0){
        cerr<<"Error! Empty Stack!"<<endl;
        return 0;
    }
    return head->val;
}

ostream &operator<<(ostream &out, LinkStack &table) {
    out << "StackInfo: Length " << table.length;
    out << ". TOP->[";
    LinkStack::Node* p = table.head;
    for(; p!=NULL; p=p->next) {
        out << p->val;
        if (p->next != NULL) out << ", ";
    }
    out<< "]";
    return out;
}



