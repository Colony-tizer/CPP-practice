#ifndef TREE_H_
#define TREE_H_
#include "Position.h"

template <class T> class Position;
template <class T> class PositionList;

template <class T>
class Tree {
    private:
        typedef Position<T> value_pos_type;
        typedef value_pos_type* ptr_pos_type;
        typedef value_pos_type& ref_pos_type;
        typedef value_pos_type const& const_ref_pos_type;


        typedef PositionList<T> value_list_type;
    public:
        Tree();
        Tree(const_ref_pos_type pos);
        ~Tree();
        int getSize();
        bool isEmpty();
        ref_pos_type getRoot();
        value_list_type positions();
    private:
        ptr_pos_type root;
        int size;
};
#include "Tree.tpp"
#endif