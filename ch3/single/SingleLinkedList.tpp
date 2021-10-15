#include "SingleLinkedList.h"
template <class T>
SingleLinkedList<T>::SingleLinkedList() {
    head = nullptr;
}
template <class T>
SingleLinkedList<T>::~SingleLinkedList() {
    while (!isEmpty())
        removeFront();
    
}
template <class T>
bool SingleLinkedList<T>::isEmpty() {
    return !head;
}

template <class T>
typename SingleLinkedList<T>::item_const_ref SingleLinkedList<T>::front() const {
    return *head;
}
template <class T>
typename SingleLinkedList<T>::const_ref_type SingleLinkedList<T>::frontVal() const {
    return head->getValue();
}

template <class T>
void SingleLinkedList<T>::addFront(item_const_ref obj) {
    item_ptr newObj = new item_type(obj);
    newObj->setNext(head);
    //newObj->next = head;
    head = newObj;
}

template <class T>
void SingleLinkedList<T>::addFront(const_ref_type val) {
    item_ptr newObj = new item_type(val);
    this->addFront(*newObj);
    delete newObj;
}


template <class T>
void SingleLinkedList<T>::removeFront() {
    if (head) {
        item_ptr remObj = head;
        head = head->getNext();
        delete remObj;
    }
}