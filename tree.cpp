#ifndef tree_H
#define tree_H

#include <stdlib.h>
#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>
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
        if(this->head_ == nullptr){ //first
            // std::cout<<"added to top";
            head_ = head;
            size_++;
            return head;
        }
       else if(value < head->value_ ){ //go left
            if(head->left_ == nullptr){
                node* left = new node(value);
                head->left_ = left;
                size_++;
                // std::cout<<"went left"<<std::endl;
                // std::cout<< left->value_ << std::endl;
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

    node* add(node* head){
        return this->add(head,head->value_);
    }

    node* add(int value){
        if(head_ == nullptr){
            throw std::range_error("please enter head first");
        }
        return this->add(head_,value);
    }

    void printBST(node* head){
        if(head_ == nullptr){ //base case
            throw std::runtime_error("empty");
        }
        std::unordered_set<node*> visited;//setting up visited list
        std::list<node*> queue; //setting up queue
        
        queue.push_back(head);
        visited.insert(head);
        std::cout<<"The BST Tree is: ";
        std::cout << head->value_;
        std::cout << " ";

        while(!queue.empty()){
            node* s = queue.front();
            queue.pop_front();

            std::vector<node*> children;
            children.push_back(s->left_);
            children.push_back(s->right_);
            
            for(auto i = children.begin(); i != children.end(); i++){
                if(visited.find(*i) == visited.end() && *i != nullptr){
                    node* current = *i;
                    std::cout<< current->value_;
                    std::cout<<" ";
                    queue.push_back(*i);
                    visited.insert(*i);
                }
            }
        }
    }

    node* searchSubTree(node* head, int value){
        // std::cout<<"entered search ";
        node* current = head;
        while (current != nullptr){
            if(current->value_ == value){
                std::cout<<current->value_;
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
    node* search(node* head, int value){
        if(head->value_ == value){
            return head;
        }
        if(value < head->value_){
            search(head->left_, value);
        }
        else if(value > head->value_){
            search(head->right_, value);
        }
        else{
            return NULL;
        }
    }

    node* invert(node* head){
        if(head == nullptr){
            return NULL;
        }
        else{//right to left && left to right
            node* temp = head->left_;
            head->left_ = head->right_;
            head->right_ = temp;

            invert(head->left_);
            invert(head->right_);
        }
        return head;
    }
    bool exists(node* head, int value){
        if(this->head_ == nullptr){
            throw std::range_error("there is no root node");
        }
        else if(search(head,value) == NULL){
            return false;
        }
        else{
            return true;
        }
    }
    void Remove(node* head, int value){
        if(exists(head,value)== true){ //node exisits
            node* toRemove = search(head,value);

            if(toRemove->left_ == nullptr && toRemove->right_ == nullptr){ //leaf node
                size_--;
                delete search(head,value);
            }
            if(toRemove->left_ != nullptr){ //left only
                
            }
        }
    }
};
#endif