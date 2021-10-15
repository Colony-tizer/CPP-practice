#include "Stack.h"
template <class T>
Stack<T>::Stack(const int capacity) {
    arraySize = capacity;
    array = new val_type[arraySize];
    this->curItemsNum = 0;
}
template <class T>
Stack<T>::~Stack() {
    delete[] array;
}/*
template <class T>
int Stack<T>::getSize() const {
    return this->curItemsNum + 1;
}
template <class T>
bool Stack<T>::isEmpty() const {
    return this->curItemsNum < 0;
}*/
template <class T>
typename Stack<T>::const_ref_type Stack<T>::top() const {
    if (this->isEmpty()) throw StackEmptyException();
    return array[this->curItemsNum-1];
}
template <class T>
void Stack<T>::pop() {
    if (this->isEmpty()) throw StackEmptyException();
    --this->curItemsNum;
}
template <class T>
void Stack<T>::push(const_ref_type val) {
    if (this->getSize() == arraySize) throw StackFullException();
    array[this->curItemsNum] = val;
    ++this->curItemsNum;
}