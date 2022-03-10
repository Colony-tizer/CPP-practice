#include "NodeList.h"

template <typename T>
NodeList<T>::NodeList() {
    size = 0;
    head = new Node_value_t();
    tail = new Node_value_t();
    
    head->next = tail;
    tail->prev = head;
}

template <typename T>
NodeList<T>::~NodeList() {
    while (!isEmpty()) removeFront();

    delete head, tail;
}

template <typename T>
int NodeList<T>::getSize() const{
    return size;
}

template <typename T>
bool NodeList<T>::isEmpty() const{
    return getSize() == 0;
}

template <typename T>
typename NodeList<T>::Iterator_t NodeList<T>::begin() const{
    return Iterator_t(head->next);
}

template <typename T>
typename NodeList<T>::Iterator_t NodeList<T>::end() const{
    return Iterator_t(tail);
}

template <typename T>
void NodeList<T>::insertFront(Ref_const_t val) {
    ++size;
    Node_ptr_t newObj = new Node_value_t(val);

    newObj->prev = head;
    newObj->next = head->next;

    head->next->prev = newObj;
    head->next = newObj;

    if (getSize() == 1) 
        tail->prev = head->next;
}

template <typename T>
void NodeList<T>::insertBack(Ref_const_t val) {
    ++size;
    Node_ptr_t newObj = new Node_value_t(val);

    newObj->next = tail;
    newObj->prev = tail->prev;

    tail->prev->next = newObj;
    tail->prev = newObj;

    if (getSize() == 1) 
        head->next = tail->prev;
}

template <typename T>
void NodeList<T>::insert(Iterator_const_ref it, Ref_const_t val) {
    ++size;
    Node_ptr_t newObj = new Node_value_t(val);
    Node_ptr_t prev = it.value->prev;

    newObj->next = it.value;
    newObj->prev = prev;

    prev->next = newObj;

    it.value->prev = newObj;
}

template <typename T>
void NodeList<T>::removeFront() {
    if (isEmpty()) throw "NodeListEmpty";

    --size;
    Node_ptr_t newHead = head->next->next;
    Node_ptr_t remNode = newHead->prev;

    newHead->prev = head;
    head->next = newHead;

    delete remNode;
}

template <typename T>
void NodeList<T>::removeBack() {
    if (isEmpty()) throw "NodeListEmpty";

    --size;
    Node_ptr_t newTail = *tail->prev->prev;
    Node_ptr_t remNode = newTail->next;

    newTail->next = tail;
    tail->prev = newTail;

    delete remNode;
}

template <typename T>
void NodeList<T>::remove(Iterator_const_ref it) {
    if (isEmpty()) throw "NodeListEmpty";

    --size;
    Node_ptr_t next = it.value->next;
    Node_ptr_t prev = it.value->prev;

    prev->next = next;
    next->prev = prev;

    delete it.value;
}