#ifndef node_H
#define node_H
// some declarations in
// the header file.

#include <stdlib.h>
#include <iostream>

// template <class T>
class node{

    public:

    node* left_;
    node* right_;
    int value_;

    node(){left_ = nullptr; right_ = nullptr; value_ = 0;}
    node(int value){left_ = nullptr; right_ = nullptr; value = value;}
    node(int value, node* right, node* left){left_ = left; right_ = right; value_ = value;}

    int& getValue(){
        return value_;
    }

    void setValue(int value){
        value_ = value;
    }

    node* getLeft(){
        return left_;
    }

    void setLeft(node* left){
        left_ = left;
    }

    node* getRight(){
        return right_;
    }

    void setRight(node* right){
        right_ = right;
    }

    // operator *(node* node){
    //     return node->value_;
    // }
};

#endif