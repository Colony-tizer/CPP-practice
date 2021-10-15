#ifndef BTREEPOSITION_H_
#define BTREEPOSITION_H_
#include "BTree.h"
#include "BTreeNode.h"
#include <list>
template <class T> class BTree;
template <class T> class BTreeNode;

template <class T>
class BTreePosition {
    private:
        typedef T value_type;
        typedef value_type* ptr_type;
        typedef value_type& ref_type;
        typedef value_type const& const_ref_type;

        typedef BTreeNode<T> node_value_type;
        typedef node_value_type* node_ptr_type;

        typedef BTreePosition<T> pos_value_type;
    public:
        BTreePosition(node_ptr_type node = nullptr) : node(node) {}
        bool operator==(const BTreePosition& pos) const { return pos.node == node; }
        bool operator!=(const BTreePosition& pos) const { return pos.node != node; }
        bool isRoot() const { return (!node->parent); }
        bool isExternal() const { return (!node->getLeftChild() && !node->getRightChild()); }
        ref_type operator*() { return node->value; }
        BTreePosition getLeft() const { return pos_value_type(node->getLeftChild()); }
        BTreePosition getRight() const { return pos_value_type(node->getRightChild()); }
        BTreePosition getParent() const { return pos_value_type(node->getParent()); }

        typedef std::list<pos_value_type> BTreePosList;
        friend class BTree<T>;
    private:
        node_ptr_type node;        
};
#endif