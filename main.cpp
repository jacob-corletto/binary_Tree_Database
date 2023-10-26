#include <iostream>
#include "tree.cpp"

int main(){
    std::cout << "testing tree database \n";
    tree<int> t1;
    std::cout<<"inserted " << t1.insert(9)->getValue() <<std::endl;
    node<int>* root = t1.getRoot();
    std::cout<<"inserted " << t1.insert(8)->getValue() <<std::endl;
    std::cout<<"found " << t1.search(8)->getValue() <<std::endl;
    if (root != nullptr) {
        // Print the value of the root node
        std::cout << "The root value is: " << root->value_ << std::endl;
    } else {
        std::cout << "The tree is empty, so there is no root." << std::endl;
    }
    std::cout << "the size is: " << t1.getSize() << std::endl;
    
    return 0;
}