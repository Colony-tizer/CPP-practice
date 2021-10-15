#include "StackSList.h"
template <class T>
StackSList<T>::StackSList() {
    this->list = new slistType();
    this->curItemsNum = 0;
}

template <class T>
StackSList<T>::~StackSList() {
    delete this->list;
}

template <class T>
inline bool StackSList<T>::isEmpty() const {
    return this->list->isEmpty();
}
template <class T>
typename StackSList<T>::const_ref_type StackSList<T>::top() const {
    return this->list->frontVal();
}
template <class T>
void StackSList<T>::pop() {
    this->list->removeFront();
    --this->curItemsNum;
}
template <class T>
void StackSList<T>::push(const_ref_type val) {
    this->list->addFront(val);
    ++this->curItemsNum;
}