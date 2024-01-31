#include <iostream>
#include "tree.cpp"

int main(){
    std::cout << "testing tree database \n";
    tree<int> t1;
    std::cout<<"inserted " << t1.insert(9)->getValue() << std::endl;
    std::cout<<"inserted " << t1.insert(8)->getValue() << std::endl;
    std::cout<<"inserted " << t1.insert(10)->getValue() << std::endl;
    std::cout<<"inserted " << t1.insert(11)->getValue() << std::endl;
    // std::cout<<"inserted " << t1.insert(12)->getValue() << std::endl;

    node<int>* root = t1.getRootNode();
    node<int>* searched_node = t1.search(8);

    if (root != nullptr) {
        std::cout << "The root value is: " << t1.getRoot() << std::endl;
    } else {
        std::cout << "The tree is empty, so there is no root." << std::endl;
    }

    if (searched_node != nullptr){
        std::cout<<"found " << searched_node->getValue() <<std::endl;
    } else {
        std::cout << "the node is not in the tree." << std::endl;
    }

    std::cout << "the balancing factor is: " << t1.getBalanceFactor() << std::endl;

    if (t1.isBalanced()){
        std::cout<<"this tree is balanced" << std::endl;
    } else {
        std::cout <<"This tree is not balanced" << std::endl;
    }

    std::cout << "the size is: " << t1.getSize() << std::endl;

    std::cout << "the height of the tree is: " << t1.height() << std::endl;

    std::cout << "the tree in order is " << std::endl;

    t1.printTree();

    std::cout << "\n";

    std::cout << "11 exists " << t1.exists(11) << std::endl;

    // std::cout << "inverting the tree" << std::endl;

    // t1.invert(root)->printTree();

    // std::cout << "\n";

    std::cout << "remove 10 " << std::endl;

    std::cout << "\n";

    std::cout << "the root is: " << t1.getRoot() << std::endl;

    t1.remove(999);

    std::cout << "\n";

    t1.printTree();

    std::cout << "\n";

    std::cout << t1.getSize() << std::endl;

    std::cout << "the root is: " << t1.getRoot() << std::endl;
    
    // tree<int> t2;
    // t2.insert(3);
    // t2.printTree();
    return 0;
}