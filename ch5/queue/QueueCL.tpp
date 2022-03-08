#include "QueueCL.h"


template <typename T>
QueueCL<T>::QueueCL() {
    list = new CList_value_t();
}

template <typename T>
QueueCL<T>::~QueueCL() {
    delete list;
}

template <typename T>
bool QueueCL<T>::isEmpty() const {
    return list->isEmpty();
}

template <typename T>
uint16_t QueueCL<T>::getSize() const {
    return list->getSize();
}

template <typename T>
typename QueueCL<T>::Ref_const_t QueueCL<T>::front() const {
    return list->front();
}

template <typename T>
typename QueueCL<T>::Ref_const_t QueueCL<T>::last() const {
    return list->back();
}

template <typename T>
void QueueCL<T>::dequeue() {
    list->remove();
}

template <typename T>
void QueueCL<T>::enqueue(Ref_const_t val) {
    list->add(val);
    list->advance();
}

template <typename T>
std::string QueueCL<T>::toString() const {
    return !isEmpty() ? list->toString() : "NULL\n";
}