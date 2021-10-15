#include "Tree.h"

template <class T>
Tree<T>::Tree() {
    root = nullptr;
    size = 0;
}
template <class T>
Tree<T>::Tree(const_ref_pos_type pos) {
    root = new value_pos_type(pos);
    size = pos.getSize();
}
template <class T>
Tree<T>::~Tree() {
}
template <class T>
int Tree<T>::getSize() {
    return root->getSize();
}
template <class T>
bool Tree<T>::isEmpty() {
    return getSize() == 0;
}
template <class T>
typename Tree<T>::ref_pos_type Tree<T>::getRoot() {
    return *root;
}
template <class T>
typename Tree<T>::value_list_type Tree<T>::positions() {
    value_list_type nodes = root->getChildren();
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        // implement returning list of nodes
    }
}