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
    node<T>* getRootNode(){
        return root_;
    }
    T getRoot(){
        return this->root_->value_;
    }
    void setRoot(node<T>* root){
        this->root_ = root;
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
    void printTree(){
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

    tree<T>* invert(node<T>* current){
        if(current == nullptr){
            return this;
        }
        else{//right to left && left to right
            node<T>* temp = current->left_;
            current->left_ = current->right_;
            current->right_ = temp;

            invert(current->left_);
            invert(current->right_);
        }
        return this;
    }
    bool exists(int value){
        if(this->root_ == nullptr){
            throw std::range_error("there is no root node");
        }
        else if(search(value) == nullptr){
            return false;
        }

        return true;
    }
    T height(){
        if (this->root_ == nullptr){
            return 0;
        }

        return height(root_);
        
    }

    T height(node<T>* current){
        // base case tree is empty
        if (current == nullptr)
            return 0;
 
        // If tree is not empty then
        // height = 1 + max of left height
        // and right heights
        return 1 + std::max(height(current->left_), height(current->right_));
    }
    int getBalanceFactor(){
        if (root_ == nullptr){
            return balanceFactor_;
        } else {
            return getBalanceFactor(root_);
        }
    }
    
    int getBalanceFactor(node<T>* current) {
        if (current == nullptr) {
            return 0;
        }
        int leftHeight = height(current->left_);
        int rightHeight = height(current->right_);

        balanceFactor_ = leftHeight - rightHeight;

        return balanceFactor_;
    }
    // Returns true if binary tree
    // with root as root is height-balanced
    bool isBalanced(){
        if(root_ == nullptr){
            return true;
        } else {
            return isBalanced(root_);
        }
    }
    bool isBalanced(node<T>* current){
        // for height of left subtree
        int lh;
    
        // for height of right subtree
        int rh;
    
        // If tree is empty then return true
        if (current == nullptr)
            return 1;
    
        // Get the height of left and right sub trees
        lh = height(current->left_);
        rh = height(current->right_);
    
        if (abs(lh - rh) <= 1 && isBalanced(current->left_)
            && isBalanced(current->right_))
            return 1;
    
        // If we reach here then tree is not height-balanced
        return 0;
    }
    void remove(T value){
        if (root_ == nullptr){
            std::cout << "the tree is empty \n"; 
        }else if (exists(value) == false){
            std::cout << "value does not exist";
        }else{
            remove(root_,value);
        }
    }

    node<T>* remove(node<T>* current, T value){
        if(current->getValue() > value){
            current->left_ = remove(current->left_,value);
        }
        else if(current->getValue() < value){ 
            current->right_ = remove(current->right_,value);
        }
        else{
            if (current->left_ == nullptr){
                node<T>* temp = current->right_;
                delete current;
                this->size_ -= 1;
                return temp;
            }
            else if (current->right_ == nullptr){
                node<T>* temp = current->left_;
                delete current;
                this->size_ -= 1;
                return temp;
            }
            else {
                node<T>* successor = findMin(current->right_);
                current->setValue(successor->getValue());
                current->right_ = remove(current->right_,successor->getValue());
            }
        }
        return current;
    }

    node<T>* findMin(node<T>* current) {
        while (current->left_ != nullptr) {
            current = current->left_;
        }

        return current;
    }
};
#endif