#include "Stack.h"

template <typename T>
Stack<T>::Stack(const int capacity /* = Stack::DFLT_STACK_CAP */) {
    this->capacity = capacity;
    array = new Value_t[capacity];
    this->curItemsNum = 0;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] array;
}

template <typename T>
typename Stack<T>::Ref_const_t Stack<T>::top() const {
    if (this->isEmpty()) throw StackEmptyException();

    return array[this->curItemsNum-1];
}

template <typename T>
void Stack<T>::pop() {
    if (this->isEmpty()) throw StackEmptyException();

    --this->curItemsNum;
}

template <typename T>
void Stack<T>::push(Ref_const_t val) {
    if (this->getSize() == capacity) throw StackFullException();

    array[this->curItemsNum] = val;
    ++this->curItemsNum;
}