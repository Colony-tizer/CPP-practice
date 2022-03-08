#ifndef QUEUED_H_
#define QUEUED_H_
#include "../../ch3/double/DList.h"
#include <string>
template <typename T> class DList;

template <typename T>
class QueueD {
    private:
        typedef DList<T> DList_value_t;
        typedef DList_value_t* DList_ptr_t;

        typedef T Value_t;
        typedef T* Ptr_t;
        typedef T& Ref_t;
        typedef T const& Ref_const_t;

    public:
        QueueD();
        ~QueueD();

        bool isEmpty() const;
        uint16_t getSize() const;
        Ref_const_t front() const;
        Ref_const_t back() const;

        void insertFront(Ref_const_t val);
        void insertBack(Ref_const_t val);
        void removeFront();
        void removeBack();

        std::string toString();

    private:
        DList_ptr_t list;
};

#include "QueueD.tpp"

#endif