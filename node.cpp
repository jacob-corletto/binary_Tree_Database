#ifndef node_H
#define node_H
// some declarations in
// the header file.

#include <stdlib.h>
#include <iostream>

template <class T>
class node{

    public:

    node* left_;
    node* right_;
    T value_;

    node(){left_ = nullptr; right_ = nullptr; value_ = 0;}
    node(T value){left_ = nullptr; right_ = nullptr; value_ = value;}
    node(T value, node* right, node* left){left_ = left; right_ = right; value_ = value;}

    T& getValue(){
        return value_;
    }

    void printValue(){
        std::cout << this->value_ << std::endl;
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

    void operator =(node* rhs){
        this->left_ = rhs->left_;
        this->right_ = rhs->right_;
        this->value_ = rhs->value_;
    }
    bool operator <(node* rhs){
        if (this->value_ < rhs->value_){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator >(node* rhs){
        if (this->value_ > rhs->value_){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator ==(node* rhs){
        if (this->value_ == rhs->value_){
            return true;
        }
        else{
            return false;
        }
    }
    int operator *(node* rhs){
        return rhs->getValue();
    }
    // friend std::ostream& operator<<(std::ostream& os, node* node) {
    //     os << node->getValue();
    //     return os;
    // }
};

#endif