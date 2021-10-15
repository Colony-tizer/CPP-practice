#ifndef QUEUED_H_
#define QUEUED_H_
#include "../../ch3/double/DList.h"
#include <string>
template <class T> class DList;

template <class T>
class QueueD {
    private:
        typedef DList<T> list_value_type;
        typedef list_value_type* list_ptr_type;
        typedef list_value_type& list_ref_type;
        typedef list_value_type const& list_const_ref_type;

        typedef T value_type;
        typedef T* ptr_type;
        typedef T& ref_type;
        typedef T const& const_ref_type;
    public:
        QueueD();
        ~QueueD();
        bool isEmpty() const;
        int getSize() const;
        const_ref_type front() const;
        const_ref_type back() const;
        void insertFront(const_ref_type val);
        void insertBack(const_ref_type val);
        void removeFront();
        void removeBack();
        std::string toString();
    private:
        list_ptr_type list;
};

#include "QueueD.tpp"

#endif