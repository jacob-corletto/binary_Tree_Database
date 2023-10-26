#ifndef tree_H
#define tree_H

#include <stdlib.h>
#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>
#include "node.cpp"
template <typename T>

class tree{
    public:
    node<T>* root_;
    int size_;
    int balanceFactor_;

    tree(){root_ = nullptr; size_ = 0; balanceFactor_ = 0;}
    tree(node<T>* root){root_ = root; size_ = 0;balanceFactor_ = 0;}

    int getSize(){
        return this->size_;
    }
    node<T>* getRoot(){
        return root_;
    }
    void setRoot(node<T>* root){
        this->root_ = root;
    }
    void printRoot(){
        std::cout<<this->root_->getValue()<<std::endl;
    }
    //add with root_ and value
    node<T>* insert(T value) {
        if (root_ == nullptr) {
            root_ = new node<T>(value);
            size_++;
            return root_;
        } else {
            return insertRecursive(root_, value);
        }
    }
    node<T>* insertRecursive(node<T>*& current,T value){
        if (current == nullptr) { // First
            size_++;
            current = new node<T>(value);
            return current;
        } else if (value < current->value_) {
            return insertRecursive(current->left_, value);
        } else {
            return insertRecursive(current->right_, value);
        }
    }
    void printInOrder(){
        printInOrderRecursive(this->root_);
    }
    void printInOrderRecursive(node<T>* current){
        if (current != nullptr){
            printInOrderRecursive(current->left_);
            std::cout << current->getValue() <<" ";
            printInOrderRecursive(current->right_);
        }
    }
    node<T>* search(T value){
        return searchRecursive(this->root_, value);
    }

    node<T>* searchRecursive(node<T>* current, T value){
        if(current == nullptr){ //first
            return nullptr;
        }
        if (current->value_ == value){
            return current;
        }
        if (value < current->value_){
            return searchRecursive(current->left_,value);
        }
        
        return searchRecursive(current->right_, value);
    }

    T invert(T root_){
        if(root_ == nullptr){
            return NULL;
        }
        else{//right to left && left to right
            T temp = root_->left_;
            root_->left_ = root_->right_;
            root_->right_ = temp;

            invert(root_->left_);
            invert(root_->right_);
        }
        return root_;
    }
    bool exists(T root_, int value){
        if(this->root_ == nullptr){
            throw std::range_error("there is no root node");
        }
        else if(search(root_,value) == NULL){
            return false;
        }
        else{
            return true;
        }
    }
    void Remove(T root_, int value){
        if(exists(root_,value)== true){ //node exisits
            T toRemove = search(root_,value);

            if(toRemove->left_ == nullptr && toRemove->right_ == nullptr){ //leaf node
                size_--;
                delete search(root_,value);
            }
            if(toRemove->left_ != nullptr){ //left only
                
            }
        }
    }
};
#endif