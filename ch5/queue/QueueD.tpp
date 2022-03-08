#include "QueueD.h"

template <typename T>
QueueD<T>::QueueD() {
    list = new DList_value_t();
}

template <typename T>
QueueD<T>::~QueueD() {
    delete list;
}

template <typename T>
bool QueueD<T>::isEmpty() const {
    return list->isEmpty();
}

template <typename T>
uint16_t QueueD<T>::getSize() const {
    return list->getSize();
}

template <typename T>
typename QueueD<T>::Ref_const_t QueueD<T>::front() const {
    return list->front();
}

template <typename T>
typename QueueD<T>::Ref_const_t QueueD<T>::back() const {
    return list->at(list->getSize()-1);
}

template <typename T>
void QueueD<T>::insertFront(Ref_const_t val) {
    list->addFront(val);
}

template <typename T>
void QueueD<T>::insertBack(Ref_const_t val) {
    list->addAt(list->getSize(), val);
}

template <typename T>
void QueueD<T>::removeFront() {
    list->popFront();
}

template <typename T>
void QueueD<T>::removeBack() {
    const int REMOVE_INDEX = std::max(0, list->getSize() - 1);
    list->removeAt(REMOVE_INDEX);
}

template <typename T>
std::string QueueD<T>::toString() {
    return list->toString();
}