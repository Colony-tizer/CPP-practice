#include "QueueCL.h"


template <class T>
QueueCL<T>::QueueCL() {
    list = new list_value_type();
}
template <class T>
QueueCL<T>::~QueueCL() {
    delete list;
}
template <class T>
bool QueueCL<T>::isEmpty() const {
    return list->isEmpty();
}
template <class T>
int QueueCL<T>::getSize() const {
    return list->getSize();
}
template <class T>
typename QueueCL<T>::const_ref_type QueueCL<T>::front() const {
    return list->front();
}
template <class T>
typename QueueCL<T>::const_ref_type QueueCL<T>::last() const {
    return list->back();
}
template <class T>
void QueueCL<T>::dequeue() {
    list->remove();
}
template <class T>
void QueueCL<T>::enqueue(const_ref_type val) {
    list->add(val);
    list->advance();
}

template <class T>
std::string QueueCL<T>::toString() const {
    return !isEmpty() ? list->toString() : "NULL\n";
}