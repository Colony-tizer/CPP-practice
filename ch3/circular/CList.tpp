#include "CList.h"
#include "Exceptions.h"

template <typename T>
CList<T>::CList() {
    cursor = nullptr;
    size = 0;
}

template <typename T>
CList<T>::~CList() {
    while (!isEmpty()) remove();
}

template <typename T>
inline bool CList<T>::isEmpty() const {
    return getSize() == 0;
}

template <typename T>
inline int CList<T>::getSize() const {
    return size;
}

template <typename T>
typename CList<T>::Ref_const_t CList<T>::front() const {
    if (!cursor) throw ListEmptyError();
    
    return cursor->getNext()->getValue();
}

template <typename T>
typename CList<T>::Ref_const_t CList<T>::back() const {
    if (!cursor) throw ListEmptyError();

    return cursor->getValue();
}

template <typename T>
void CList<T>::advance() {
    cursor = cursor->getNext();
}

template <typename T>
void CList<T>::add(Ref_const_t val) {
    Single_link_item_ptr_t newObj = new Single_link_item_t(val);
    
    if (isEmpty()) {
        cursor = newObj;
        cursor->setNext(cursor);
    }
    else {
        Single_link_item_ptr_t nextItem = cursor->getNext();
        cursor->setNext(newObj);
        newObj->setNext(nextItem);
    }
    ++size;
}

template <typename T>
void CList<T>::remove() {
    if (isEmpty()) throw ListEmptyError();
    
    Single_link_item_ptr_t nextItem = cursor->getNext()->getNext();
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

template <typename T>
std::string CList<T>::toString() {
    std::string listStr = "HEAD: ";
    for (int i = 0; i < size; ++i) {
        listStr += std::to_string(front()) + " >> ";
        advance();
    }
    listStr += "HEAD: " + std::to_string(front()) + "\n";
    return listStr;
}

template <>
std::string CList<std::string>::toString() {
    std::string listStr = "HEAD: ";
    for (int i = 0; i < size; ++i) {
        listStr += front() + " >> ";
        advance();
    }
    listStr += "HEAD: " + front() + "\n";
    return listStr;
}
