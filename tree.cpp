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
        return this->root_;
    }
    void setRoot(node<T>* root){
        this->root_ = root;
    }
    void printRoot(){
        std::cout<<this->root_->getValue()<<std::endl;
    }
    //add with root_ and value
    void insert(T value){
        this->root_ = insertRecursive(root_,value);
    }
    node<T>* insertRecursive(node<T>* current,T value){
        if(current == nullptr){ //first
            size_++;
            return new node<T>(value);
        }
        if (value < current->value_){
            current->left_ = insertRecursive(current->left_,value);
        }
        else if (value > current->value_){
            current->right_ = insertRecursive(current->right_,value);
        }
        return current;
    }

    void printBST(T root_){
        if(root_ == nullptr){ //base case
            throw std::runtime_error("empty");
        }
        std::unordered_set<node<T>*> visited;//setting up visited list
        std::list<node<T>*> queue; //setting up queue
        
        queue.push_back(root_);
        visited.insert(root_);
        std::cout<<"The BST Tree is: ";
        std::cout << root_->value_;
        std::cout << " ";

        while(!queue.empty()){
            T s = queue.front();
            queue.pop_front();

            std::vector<T> children;
            children.push_back(s->left_);
            children.push_back(s->right_);
            
            for(auto i = children.begin(); i != children.end(); i++){
                if(visited.find(*i) == visited.end() && *i != nullptr){
                    T current = *i;
                    std::cout<< current->value_;
                    std::cout<<" ";
                    queue.push_back(*i);
                    visited.insert(*i);
                }
            }
        }
    }

    node<T>* searchInterative(node<T>* root_, int value){
        // std::cout<<"entered search ";
        node<T>* current = root_;
        while (current != nullptr){
            if(current->value_ == value){
                return current;
            }
            else if(value < current->value_){
                // std::cout<<"value is smaller "<< std::endl;
                current = current->left_;
            }
            else{
                // std::cout<<"value is bigger "<<std::endl;
                current = current->right_;
            }
        }
        return NULL;
    }
    node<T>* searchRecursive(node<T>* root_, int value){
        if(root_->value_ == value){
            return root_;
        }
        if(value < root_->value_){
            searchRecursive(root_->left_, value);
        }
        else if(value > root_->value_){
            searchRecursive(root_->right_, value);
        }
        else{
            return NULL;
        }
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