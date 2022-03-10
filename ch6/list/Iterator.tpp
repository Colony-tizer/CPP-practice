#include "Iterator.h"

template <typename T>
Iterator<T>::Iterator(Node_ptr_t node) {
    value = node;
}

template <typename T>
typename Iterator<T>::Ref_t Iterator<T>::operator*() {
    return value->value;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& iter) {
    return value == iter.value;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& iter) {
    return !this->operator==(iter);
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    value = value->next;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++(int) {
    return this->operator++();
}

template <typename T>
Iterator<T>& Iterator<T>::operator--() {
    value = value->prev;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--(int) {
    return this->operator--();
}

template <typename T>
Iterator<T>& Iterator<T>::operator+(int num) {
    for (int i = 0; i < num; ++i) 
        this->operator++();

    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator-(int num) {
    for (int i = 0; i < num; ++i) 
        this->operator--();

    return *this;
}