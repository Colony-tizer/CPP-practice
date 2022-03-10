#include "SingleLinkedList.h"

template <typename T>
SingleLinkedList<T>::SingleLinkedList() {
    head = nullptr;
}
template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
    while (!isEmpty())
        removeFront();
    
}
template <typename T>
bool SingleLinkedList<T>::isEmpty() {
    return !head;
}

template <typename T>
typename SingleLinkedList<T>::Single_link_item_ref_const_t SingleLinkedList<T>::front() const {
    return *head;
}
template <typename T>
typename SingleLinkedList<T>::Single_link_item_t::Ref_const_t SingleLinkedList<T>::frontVal() const {
    return head->getValue();
}

template <typename T>
void SingleLinkedList<T>::addFront(Single_link_item_ref_const_t obj) {
    Single_link_item_ptr_t newObj = new Single_link_item_t(obj);
    newObj->setNext(head);
    head = newObj;
}

template <typename T>
void SingleLinkedList<T>::addFront(typename Single_link_item_t::Ref_t val) {
    Single_link_item_ptr_t newObj = new Single_link_item_t(val);
    this->addFront(*newObj);
    delete newObj;
}

template <typename T>
void SingleLinkedList<T>::removeFront() {
    if (head) {
        Single_link_item_ptr_t remObj = head;
        head = head->getNext();
        delete remObj;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const SingleLinkedList<T>& obj) {
    typename SingleLinkedList<T>::Single_link_item_ptr_t printObj = obj.head;
    const std::string NULL_STR = "NULL";

    if (printObj)
        os << (*printObj);
    else 
        os << NULL_STR;

    return os;
}