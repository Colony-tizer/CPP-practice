#include "Iterator.h"

template <class T>
Iterator<T>::Iterator(ptr_node_type node) {
    value = node;
}
template <class T>
typename Iterator<T>::ref_type Iterator<T>::operator*() {
    return value->value;
}
template <class T>
bool Iterator<T>::operator==(const Iterator& iter) {
    return value == iter.value;
}
template <class T>
bool Iterator<T>::operator!=(const Iterator& iter) {
    return !this->operator==(iter);
}
template <class T>
Iterator<T>& Iterator<T>::operator++() {
    value = value->next;
    return *this;
}
template <class T>
Iterator<T>& Iterator<T>::operator++(int) {
    return this->operator++();
}
template <class T>
Iterator<T>& Iterator<T>::operator--() {
    value = value->prev;
    return *this;
}
template <class T>
Iterator<T>& Iterator<T>::operator--(int) {
    return this->operator--();
}
template <class T>
Iterator<T>& Iterator<T>::operator+(int num) {
    for (int i = 0; i < num; ++i) this->operator++();
    return *this;
}
template <class T>
Iterator<T>& Iterator<T>::operator-(int num) {
    for (int i = 0; i < num; ++i) this->operator--();
    return *this;
}