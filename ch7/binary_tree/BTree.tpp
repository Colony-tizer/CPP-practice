#include "BTree.h"

template <class T>
BTree<T>::BTree() : _root(), _size(0) {}
template <class T>
int BTree<T>::getSize() const {
    return _size;
}
template <class T>
bool BTree<T>::isEmpty() const {
    return getSize() == 0;
}
template <class T>
typename BTree<T>::pos_value_type BTree<T>::getRoot() const {
    return pos_value_type(_root);
}
template <class T>
typename BTree<T>::pos_value_type::BTreePosList BTree<T>::getPositions() const {
    typename pos_value_type::BTreePosList pl;
    preorder(getRoot().node, pl);
    return typename pos_value_type::BTreePosList(pl);
}
template <class T>
void BTree<T>::addRoot() {
    _root = new node_value_type();
    _size = 1;
}
template <class T>
void BTree<T>::expandExternal(pos_const_ref_type pos) {
    if (!pos.isExternal()) return;
    node_ptr_type exNode = pos.node;
    exNode->setLeftChild(new node_value_type());
    exNode->setRightChild(new node_value_type());
    _size += 2;
}
template <class T>
typename  BTree<T>::pos_value_type BTree<T>::removeAboveExternal(pos_const_ref_type pos) {
    pos_value_type exNode = pos; 
    pos_value_type par = pos.getParent();
    pos_value_type sibl = par.getLeft() == exNode ? par.getRight() : par.getLeft();
    if (par == getRoot()) {
        _root = sibl.node;
        sibl.node->setParent(nullptr);
    } else {
        pos_value_type granp = par.getParent();
        if (granp.getLeft() == par) 
            granp.node->setLeftChild(sibl.node); 
        else granp.node->setRightChild(sibl.node);
    }
    delete exNode.node; delete par.node;
    _size -= 2;
    return sibl;
}

template <class T>
void BTree<T>::preorder(node_ptr_type node, typename pos_value_type::BTreePosList& pl) const {
    pl.push_back(node);
    if (node->getLeftChild())  preorder(node->getLeftChild(), pl);
    if (node->getRightChild()) preorder(node->getRightChild(), pl);
}