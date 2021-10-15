#include "NodeList.h"
template <class T>
NodeList<T>::NodeList() {
    size = 0; head = new node_type(); tail = new node_type();
    head->next = tail;
    tail->prev = head;
}
template <class T>
NodeList<T>::~NodeList() {
    while (!isEmpty()) removeFront();
    delete head, tail;
}
template <class T>
int NodeList<T>::getSize() const{
    return size;
}
template <class T>
bool NodeList<T>::isEmpty() const{
    return getSize() == 0;
}
template <class T>
typename NodeList<T>::iter_type NodeList<T>::begin() const{
    return iter_type(head->next);
}
template <class T>
typename NodeList<T>::iter_type NodeList<T>::end() const{
    return iter_type(tail);
}
template <class T>
void NodeList<T>::insertFront(const_ref_type val) {
    ++size;
    ptr_node_type newObj = new node_type(val);
    newObj->prev = head;
    newObj->next = head->next;
    head->next->prev = newObj;
    head->next = newObj;
    if (getSize() == 1) tail->prev = head->next;
}
template <class T>
void NodeList<T>::insertBack(const_ref_type val) {
    ++size;
    ptr_node_type newObj = new node_type(val);
    newObj->next = tail;
    newObj->prev = tail->prev;
    tail->prev->next = newObj;
    tail->prev = newObj;
    if (getSize() == 1) head->next = tail->prev;
}
template <class T>
void NodeList<T>::insert(const_ref_iter_type it, const_ref_type val) {
    ++size;
    ptr_node_type newObj = new node_type(val);
    ptr_node_type prev = it.value->prev;
    newObj->next = it.value;
    newObj->prev = prev;
    prev->next = newObj;
    it.value->prev = newObj;
}
template <class T>
void NodeList<T>::removeFront() {
    if (isEmpty()) throw "Empty";
    --size;
    ptr_node_type newHead = head->next->next;
    ptr_node_type delNode = newHead->prev;
    newHead->prev = head;
    head->next = newHead;
    delete delNode;
}
template <class T>
void NodeList<T>::removeBack() {
    if (isEmpty()) throw "Full";
    --size;
    ptr_node_type newTail = *tail->prev->prev;
    ptr_node_type delNode = newTail->next;
    newTail->next = tail;
    tail->prev = newTail;
}
template <class T>
void NodeList<T>::remove(const_ref_iter_type it) {
    if (isEmpty()) throw "Empty";
    --size;
    ptr_node_type next = it.value->next;
    ptr_node_type prev = it.value->prev;
    prev->next = next;
    next->prev = prev;
    delete it.value;
}