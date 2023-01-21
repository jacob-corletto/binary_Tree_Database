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
    t1.add(n1);
    t1.add(n1,4);
    t1.add(6);
    t1.add(n1,3);
    // t1.search(n1,3);
    // t1.invert(n1);
    t1.print(n1);

    std::cout<<" "<< std::endl;
    std::cout<<"the size is: ";
    std::cout << t1.getSize() << std::endl;

    return 0;
}