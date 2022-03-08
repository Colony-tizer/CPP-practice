#ifndef QUEUECL_H_
#define QUEUECL_H_
#include "../../ch3/circular/CList.h"
#include <string>
template <typename T> class CList;

template <typename T>
class QueueCL {
    private:
        typedef CList<T> CList_value_t;
        typedef CList_value_t* CList_ptr_t;

        typedef T Value_t;
        typedef T* Ptr_t;
        typedef T& Ref_t;
        typedef T const& Ref_const_t;

    public:
        QueueCL();
        ~QueueCL();

        bool isEmpty() const;
        uint16_t getSize() const;
        Ref_const_t front() const;
        Ref_const_t last() const;

        void dequeue();
        void enqueue(Ref_const_t val);

        std::string toString() const;

    private:
        CList_ptr_t list;
};

#include "QueueCL.tpp"

#endif