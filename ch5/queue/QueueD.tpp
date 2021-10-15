#include "QueueD.h"

template <class T>
QueueD<T>::QueueD() {
    list = new list_value_type();
}
template <class T>
QueueD<T>::~QueueD() {
    delete list;
}
template <class T>
bool QueueD<T>::isEmpty() const {
    return list->isEmpty();
}
template <class T>
int QueueD<T>::getSize() const {
    return list->getSize();
}
template <class T>
typename QueueD<T>::const_ref_type QueueD<T>::front() const {
    return list->front();
}
template <class T>
typename QueueD<T>::const_ref_type QueueD<T>::back() const {
    return list->at(list->getSize()-1);
}
template <class T>
void QueueD<T>::insertFront(const_ref_type val) {
    list->addFront(val);
}
template <class T>
void QueueD<T>::insertBack(const_ref_type val) {
    list->addAt(list->getSize(), val);
}
template <class T>
void QueueD<T>::removeFront() {
    list->popFront();
}
template <class T>
void QueueD<T>::removeBack() {
    list->removeAt(list->getSize()-1);
}

template <class T>
std::string QueueD<T>::toString() {
    return list->toString();
}