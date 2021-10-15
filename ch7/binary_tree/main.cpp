#include "BTree.h"
#include <iostream>
int main() {
    BTree<int> tree;
    tree.addRoot();
    tree.expandExternal(tree.getRoot());
    std::cout<<tree.getSize()<<std::endl;
    BTreePosition<int>::BTreePosList l = tree.getPositions();
    int count = 0;
    for (auto it = l.begin(); it != l.end(); ++it, ++count) {
        if (it == l.begin()) std::cout<<"ROOT!_"<<count<<std::endl;
        else std::cout<<"node!_"<<count<<std::endl;
    }
    tree.removeAboveExternal(tree.getRoot().getLeft());
    std::cout<<tree.getSize()<<std::endl;
}