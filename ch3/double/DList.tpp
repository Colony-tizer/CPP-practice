#include "DList.h"

template <typename T>
DList<T>::DList(DList<T>::Ref_const_t val) {
    head = new DItem_t(val);
    tail = nullptr;
    size = 1;
}

template <typename T>
DList<T>::DList(DList<T>::DItem_ref_const_t obj) {
    head = obj;
    size = 1;
    Ptr_t next = head;
    while (next->getNext()) { 
        ++size;
        next->setNext(next->getNext());
    }
    tail = next;
}

template <typename T>
DList<T>::~DList() {
    while (!isEmpty()) popFront();
    tail = nullptr;
}

template <typename T>
bool DList<T>::isEmpty() const {
    return !head;
}

template <typename T>
int DList<T>::getSize() const {
    return size;
}

template <typename T>
typename DList<T>::Ref_const_t DList<T>::front() const {
    return at(0);
}

template <typename T>
typename DList<T>::Ref_const_t DList<T>::at(const int i) const {
    return getItemAt(i)->getValue();
}

template <typename T>
void DList<T>::addAt(const int i, DList<T>::Ref_const_t val) {
    DItem_t added(val);
    addAt(i, added);
}

template <typename T>
void DList<T>::addAt(const int i, DList<T>::DItem_ref_const_t item) {
    if (isEmpty()) addFront(item);
    DItem_ptr_t obj = getItemAt(i);

    DItem_ptr_t added = new DItem_t(item);
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

template <typename T>
void DList<T>::addFront(DList<T>::Ref_const_t val) {
    DItem_t added(val);
    addFront(added);
}
template <typename T>
void DList<T>::addFront(DList<T>::DItem_ref_const_t item) {
    ++size;

    DItem_ptr_t obj = new DItem_t(item);
    if (isEmpty()) {
        head = obj;
        tail = head;
    } else {
        head->setPrev(obj);
        obj->setNext(head);
        head = obj;
    }
}

template <typename T>
void DList<T>::removeAt(const int i) {    
    if (isEmpty()) return;

    --size;

    DItem_ptr_t obj = getItemAt(i);
    bool isNextNull = !obj->getNext(), isPrevNull = !obj->getPrev();

    if (!isPrevNull)
        obj->getPrev()->setNext(obj->getNext());
    else head = obj->getNext();

    if (!isNextNull) 
        obj->getNext()->setPrev(obj->getPrev());
    else tail = obj->getPrev();

    delete obj;
}

template <typename T>
void DList<T>::popFront() {
    removeAt(0);
}

template <typename T>
typename DList<T>::DItem_ptr_t DList<T>::getItemAt(const int i) const {
    const bool isNearHead = getSize() > 1 ? ((double)i / ((double)getSize()-1)) <= 0.5 : true;
    int cnt = (isNearHead) ? 0 : getSize() - 1;
    DItem_ptr_t obj = (isNearHead) ? head : tail;
    while (obj && ((isNearHead && cnt < i) || (!isNearHead && cnt > 0))) {
        obj = (isNearHead) ? obj->getNext() : obj->getPrev();
        cnt = (isNearHead) ? cnt + 1 : cnt - 1;
    }
    if (cnt != i || !obj)
        obj = tail;
    
    return obj;
}