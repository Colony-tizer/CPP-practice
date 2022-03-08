#include "StackSList.h"
template <typename T>
StackSList<T>::StackSList() {
    this->list = new SList_t();
    this->curItemsNum = 0;
}

template <typename T>
StackSList<T>::~StackSList() {
    delete this->list;
}

template <typename T>
inline bool StackSList<T>::isEmpty() const {
    return this->list->isEmpty();
}

template <typename T>
typename StackSList<T>::Ref_const_t StackSList<T>::top() const {
    return this->list->frontVal();
}

template <typename T>
void StackSList<T>::pop() {
    this->list->removeFront();
    --this->curItemsNum;
}

template <typename T>
void StackSList<T>::push(Ref_const_t val) {
    this->list->addFront(val);
    ++this->curItemsNum;
}