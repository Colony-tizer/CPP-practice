#include "DList.h"
/*
template <class T>
DList<T>::DList() : size(0), head(nullptr), tail(nullptr) {}
*/
template <class T>
DList<T>::DList(DList<T>::const_ref_type val) {
    head = new item_val(val);
    tail = nullptr;
    size = 1;
}
template <class T>
DList<T>::DList(DList<T>::const_item_ref obj) {
    head = obj;
    size = 1;
    ptr_type next = head;
    while (next->getNext()) { 
        ++size;
        next->setNext(next->getNext());
    }
    tail = next;
}

template <class T>
DList<T>::~DList() {
    while (!isEmpty()) popFront();
    tail = nullptr;
}

template <class T>
bool DList<T>::isEmpty() const {
    return !head;
}
template <class T>
int DList<T>::getSize() const {
    return size;
}

template <class T>
void DList<T>::popFront() {
    removeAt(0);
}
template <class T>
typename DList<T>::const_ref_type DList<T>::front() const {
    return at(0);
}
template <class T>
typename DList<T>::const_ref_type DList<T>::at(const int i) const {
    return getItemAt(i)->getValue();
}
template <class T>
typename DList<T>::item_ptr DList<T>::getItemAt(const int i) const {
    const bool isNearHead = getSize() > 1 ? ((double)i / ((double)getSize()-1)) <= 0.5 : true;
    int cnt = (isNearHead) ? 0 : getSize() - 1;
    item_ptr obj = (isNearHead) ? head : tail;
    while (obj && ((isNearHead && cnt < i) || (!isNearHead && cnt > 0))) {
        obj = (isNearHead) ? obj->getNext() : obj->getPrev();
        cnt = (isNearHead) ? cnt + 1 : cnt - 1;
    }
    if (cnt != i || !obj)
        obj = tail;
    
    return obj;
}
template <class T>
void DList<T>::addAt(const int i, DList<T>::const_ref_type val) {
    item_val added(val);
    addAt(i, added);
    //return obj->value;
}
template <class T>
void DList<T>::addAt(const int i, DList<T>::const_item_ref item) {
    if (isEmpty()) addFront(item);
    item_ptr obj = getItemAt(i);

    item_ptr added = new item_val(item);
    if (i < size) {
        added->setPrev(obj->getPrev());
        added->setNext(obj);
        if (obj->getPrev())
            obj->getPrev()->setNext(added);
        obj->setPrev(added);
    } else {
        added->setPrev(obj);
        obj->setNext(added);
        tail = added;
    }
    ++size;
}
template <class T>
void DList<T>::removeAt(const int i) {    
    if (isEmpty()) return;

    --size;

    item_ptr obj = getItemAt(i);
    bool isNextNull = !obj->getNext(), isPrevNull = !obj->getPrev();

    if (!isPrevNull)
        obj->getPrev()->setNext(obj->getNext());
    else head = obj->getNext();

    if (!isNextNull) 
        obj->getNext()->setPrev(obj->getPrev());
    else tail = obj->getPrev();

    delete obj;
}
template <class T>
void DList<T>::addFront(DList<T>::const_ref_type val) {
    item_val added(val);
    addFront(added);
}
template <class T>
void DList<T>::addFront(DList<T>::const_item_ref item) {
    ++size;

    item_ptr obj = new item_val(item);
    if (isEmpty()) {
        head = obj;
        tail = head;
    } else {
        head->setPrev(obj);
        obj->setNext(head);
        head = obj;
    }
}