#ifndef tree_H
#define tree_H

#include <stdlib.h>
#include <iostream>
#include "node.cpp"

class tree{
    public:
    node* head_;
    int size_;
    int balanceFactor_;

    tree(){head_ = nullptr; size_ = 0; balanceFactor_ = 0;}
    tree(node* head){head_ = head; size_ = 0;balanceFactor_ = 0;}

    int getSize(){
        return size_;
    }

    node* add(node* head,int value){
        if(head_ == nullptr){ //first
            head_ = head;
            size_++;
            return head;
        }
       else if(value < head->value_ ){ //go left
            if(head->left_ == nullptr){
                node* left = new node(value);
                head->left_ = left;
                size_++;
                return left;
            }
            else{
                add(head->left_, value);
            }
        }
        else if(value > head->value_){ // go right
            if(head->right_ == nullptr){
                node* right = new node(value);
                head->right_ = right;
                size_++;
                return right;
            }
            else{
                add(head->right_,value);
            }
        }
        return head;
    }
};
#endif