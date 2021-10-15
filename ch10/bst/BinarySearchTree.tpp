#include "BinarySearchTree.h"

template <class E>
BinarySearchTree<E>::BinarySearchTree() {
}
template <class E>
int BinarySearchTree<E>::size() const {
    return _size;
}
template <class E>
bool BinarySearchTree<E>::empty() const {
    return size() == 0;
}
template <class E>
Iterator BinarySearchTree<E>::find(const EntryKey& key) {
    return _tree
}
template <class E>
Iterator BinarySearchTree<E>::insert(const EntryKey& key, const EntryValue& value) {
}
template <class E>
void BinarySearchTree<E>::erase(const EntryKey& key) {
}
template <class E>
void BinarySearchTree<E>::erase(const Iterator& pointer) {
}
template <class E>
Iterator BinarySearchTree<E>::begin() {
}
template <class E>
Iterator BinarySearchTree<E>::end() {
}

// protected
template <class E>
BTreePosition BinarySearchTree<E>::root() const {
}
template <class E>
BTreePosition BinarySearchTree<E>::finder(const EntryKey& key, const BTreePosition& node) {
}
template <class E>
BTreePosition BinarySearchTree<E>::inserter(const EntryKey& key, const EntryValue& value) {
}
template <class E>
BTreePosition BinarySearchTree<E>::eraser(const BTreePosition& node) {
}
template <class E>
BTreePosition BinarySearchTree<E>::restructure(const BTreePosition& node) {
}