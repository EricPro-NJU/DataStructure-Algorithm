//
// Created by RUIPENG on 2021/8/18.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root = NULL;
}
/*
BinaryTree::BinaryTree(BinaryTree &tree) {
    root = NULL;
    copyTree(root, tree.root);
}*/

BinaryTree::~BinaryTree() {
    revoke(root);
}

BinaryTree::Node* BinaryTree::construct(BinaryTree::Node *root, istream& in) {
    //left
    T data;
    in >> data;
    if(data == INV){
        root->left = NULL;
    }
    else{
        root->left = new Node(data);
        construct(root->left, in);
    }
    //right
    in >> data;
    if(data == INV){
        root->right = NULL;
    }
    else{
        root->right = new Node(data);
        construct(root->right, in);
    }
    return root;
}
/*
BinaryTree::Node* BinaryTree::copyTree(BinaryTree::Node *root, BinaryTree::Node *tree) {
    if(tree == NULL){
        root = NULL;
        return root;
    }
    else{
        root = new Node(tree->data);
        copyTree(root->left, tree->left);
        copyTree(root->right, tree->right);
        return root;
    }
}*/

void BinaryTree::revoke(BinaryTree::Node *root) {
    if(root == NULL) return;
    revoke(root->left);
    revoke(root->right);
    delete root;
}

void BinaryTree::preOrder(BinaryTree::Node *root, ostream& out) {
    if(root==NULL) return;
    out << root->data;
    out << ", ";
    preOrder(root->left, out);
    preOrder(root->right, out);
}

void BinaryTree::inOrder(BinaryTree::Node *root, ostream &out) {
    if(root==NULL) return;
    inOrder(root->left, out);
    out << root->data;
    out << ", ";
    inOrder(root->right, out);
}

void BinaryTree::postOrder(BinaryTree::Node *root, ostream &out) {
    if(root==NULL) return;
    postOrder(root->left, out);
    postOrder(root->right, out);
    out << root->data;
    out << ", ";
}

void BinaryTree::levelOrder(ostream &out) {
    out << "levelOrder: ";
    if(root == NULL) return;
    queue<BinaryTree::Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        out << current->data <<", ";
        q.pop();
        if(current->left!=NULL) q.push(current->left);
        if(current->right!=NULL) q.push(current->right);
    }
    out<<endl;
}

void BinaryTree::input(istream &in) {
    T data;
    in>>data;
    if(data == INV){
        root = NULL;
        return;
    }
    else{
        root = new Node(data);
        construct(root, in);
    }
}

