#include "CList.h"
#include "Exceptions.h"

template <class T>
CList<T>::CList() {
    cursor = nullptr;
    size = 0;
}
template <class T>
CList<T>::~CList() {
    while (!isEmpty()) remove();
}
template <class T>
inline int CList<T>::getSize() const {
    return size;
}
template <class T>
inline bool CList<T>::isEmpty() const {
    return getSize() == 0;
}
template <class T>
void CList<T>::advance() {
    cursor = cursor->getNext();
}
template <class T>
typename CList<T>::const_ref_type CList<T>::front() const {
    if (!cursor) throw ListEmptyError();
    return cursor->getNext()->getValue();
}
template <class T>
typename CList<T>::const_ref_type CList<T>::back() const {
    if (!cursor) throw ListEmptyError();
    return cursor->getValue();
}

template <class T>
std::string CList<T>::toString() {
    std::string listStr = "| HEAD: |";
    for (int i = 0; i < size; ++i) {
        listStr += front() + " >> ";
        advance();
    }
    listStr += "| HEAD: |" + front() + " \n";
    return listStr;
}
template <class T>
void CList<T>::add(const_ref_type val) {
    item_ptr newObj = new item_val(val);
    if (isEmpty()) {
        cursor = newObj;
        cursor->setNext(cursor);
    }
    else {
        item_ptr nextItem = cursor->getNext();
        cursor->setNext(newObj);
        newObj->setNext(nextItem);
    }
    ++size;
}
template <class T>
void CList<T>::remove() {
    if (isEmpty()) throw ListEmptyError();
    item_ptr nextItem = cursor->getNext()->getNext();
    if (getSize() == 1) {
        delete cursor;
        cursor = nullptr;
    }
    else {
        delete cursor->getNext();
        cursor->setNext(nextItem);
    }
    --size;
}