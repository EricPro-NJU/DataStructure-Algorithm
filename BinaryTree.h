//
// Created by RUIPENG on 2021/8/18.
//

#ifndef NJU_REVIEW_BINARYTREE_H
#define NJU_REVIEW_BINARYTREE_H

#include <iostream>
#include <cstdlib>
#include "commons.h"
#include "LinkList.h"
#include <queue>
using namespace std;


class BinaryTree {
protected:
    struct Node{
        T data;
        Node* left;
        Node* right;
        Node(T data):data(data),left(NULL),right(NULL){}
    };
    Node* root;
    void preOrder(Node* root, ostream& out);
    void inOrder(Node* root, ostream& out);
    void postOrder(Node* root, ostream& out);
    Node* construct(Node* root, istream& in);
    //Node* copyTree(Node* root, Node* tree);
    void revoke(Node* root);
public:
    BinaryTree();
    //BinaryTree(BinaryTree& tree);
    ~BinaryTree();
    void input(istream& in) ;
    void preOrder(ostream& out){out<<"preOrder: "; preOrder(root, out); out<<endl;}
    void inOrder(ostream& out){out<<"inOrder: "; inOrder(root, out); out<<endl;}
    void postOrder(ostream& out){out<<"postOrder: "; postOrder(root, out); out<<endl;}
    void levelOrder(ostream& out);
};


#endif //NJU_REVIEW_BINARYTREE_H
