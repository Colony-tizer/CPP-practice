#include "HeapQueue.h"
#include <iostream>
template <class T, class C>
HeapQueue<T,C>::HeapQueue() {
    tree = comp_btree();
}
template <class T, class C>
HeapQueue<T,C>::~HeapQueue() {
}
template <class T, class C>
int HeapQueue<T,C>::getSize() const {
    return tree.getSize();
}
template <class T, class C>
bool HeapQueue<T,C>::isEmpty() const {
    return tree.isEmpty();
}
template <class T, class C>
typename HeapQueue<T,C>::const_ref_type HeapQueue<T,C>::getMin() {
    return *(tree.getRoot());
}
template <class T, class C>
std::string HeapQueue<T,C>::toString() {
    std::string queueStr = "";
    auto node = tree.getRoot();
    queueStr += *node + ", ";
    return tree.toString();
}
template <class T, class C>
void HeapQueue<T,C>::insert(const_ref_type val) {
    tree.add(val);
    auto newNode = tree.getLast();
    if (tree.isRoot(newNode)) return;
    auto parent = tree.getParent(newNode);
    std::cout<<*newNode<<" par: "<<*parent<<std::endl;
    while (!tree.isRoot(newNode) && *parent > *newNode) {
        tree.swap(parent, newNode);
        std::cout<<"after swap ";
        std::cout<<*newNode<<" par: "<<*parent<<std::endl;
        newNode = parent;
        if (!tree.isRoot(newNode)) parent = tree.getParent(newNode);
    }
    
}
template <class T, class C>
void HeapQueue<T,C>::removeMin() {
    if (tree.isEmpty()) throw "EmptyTreeError";
    if (tree.getSize() == 1) tree.removeLast();
    else {
        auto node = tree.getRoot();
        tree.swap(node, tree.getLast());
        tree.removeLast();
        while (tree.hasLeft(node)) {
            auto nextNode = tree.getLeft(node);
            if (tree.hasRight(node) && isLess(*(tree.getRight(node)), *nextNode))
                nextNode = tree.getRight(node);
            if (isLess(*nextNode, *node)) {
                tree.swap(nextNode, node);
                node = nextNode;
            }
            else break;
        }
    }
}
template <class T, class C>
typename HeapQueue<T,C>::const_ref_type HeapQueue<T,C>::getNextValue(const_ref_type val) const {
    auto node = tree.getRoot();
}