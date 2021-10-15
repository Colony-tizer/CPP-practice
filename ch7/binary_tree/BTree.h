#ifndef BTREE_H_
#define BTREE_H_
#include "BTreePosition.h"
template <class T> class BTreePosition;
template <class T> class BTreeNode;
template <class T>
class BTree {
    public:
        class BTreePosition<T>;
    protected:
        typedef BTreeNode<T> node_value_type;
        typedef node_value_type* node_ptr_type;

        typedef BTreePosition<T> pos_value_type;
        typedef pos_value_type* pos_ptr_type;
        typedef pos_value_type& pos_ref_type;
        typedef pos_value_type const& pos_const_ref_type;
    public:
        BTree();
        int getSize() const;
        bool isEmpty() const;
        pos_value_type getRoot() const;
        typename pos_value_type::BTreePosList getPositions() const;
        void addRoot();
        void expandExternal(pos_const_ref_type pos);
        pos_value_type removeAboveExternal(pos_const_ref_type pos);
    protected:
        void preorder(node_ptr_type node, typename pos_value_type::BTreePosList& pl) const;
    private:
        node_ptr_type _root;
        int _size;
};
#include "BTree.tpp"
#endif