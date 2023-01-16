#include <iostream>
#include "node.cpp"
#include "tree.cpp"

int main(){

    int value;
    // std::cout<<"please enter number"<< std::endl;
    // std::cin>>value;
    // std::cout<< value;
    std::cout << "hello" << std::endl; 
    node* n1 = new node(5);
    tree t1;
    std::cout << n1->getValue() << std::endl;
    t1.add(n1,4);

    std::cout << t1.getSize() << std::endl;

    return 0;
}