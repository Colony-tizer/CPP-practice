#include "Tree.h"
#include <iostream>
typedef Tree<int> int_tree;
typedef Position<int> int_pos;
typedef PositionList<int> int_pos_list;
int main() {
    int_tree t;
    int_pos root(0);
    t = int_tree(root);
    int_pos_list list;
    list.insertBack(int_pos(1));
    list.insertBack(int_pos(2));
    t.getRoot().setChildren(list);
    int_pos_list list1;
    list1.insertBack(int_pos(3));
    list.end().operator*().setChildren(list1);
    std::cout<<t.getSize()<<std::endl;
}