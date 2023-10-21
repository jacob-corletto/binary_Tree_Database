#include <iostream>
#include "node.cpp"
#include "tree.cpp"

int main(){
    std::cout << "Testing Tree capabilities" << std::endl; 
    tree<int> t1;
    t1.insert(5);
    t1.insert(6);
    t1.insert(3);
    node<int>* found = t1.search(3);
    std::cout<<"the inorder tree is: ";
    t1.printInOrder();
    std::cout<<" "<< std::endl;
    std::cout<<"the root is: "<<t1.getRoot()<<std::endl;
    std::cout<<"the value is: "<<found<<std::endl;
    // t1.invert(n1);

    std::cout<<"the size is: "<< t1.getSize()<<std::endl;
    return 0;
}