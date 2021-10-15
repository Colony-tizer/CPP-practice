#include "SList.h"

template <class T>
SList<T>::SList() {
    head = nullptr;
}
template <class T>
bool SList<T>::isEmpty() const {
    return !head;
}
template <class T>
SList<T>::~SList() {
    while (!isEmpty()) popFront();
}
template <class T>
void SList<T>::addFront(const T& val) {
    SNode<T> *newObj = SNode<T>(val);
    newObj->next = head;
    head = newObj;
}
template <class T>
void SList<T>::popFront() {
    if (head->next) {
        SNode<T> *removed = head->next;
        head = head->next;
    }
    if (!isEmpty())
        delete head;
}
template <class T>
const T& SList<T>::front() const {
    return head->value;
}