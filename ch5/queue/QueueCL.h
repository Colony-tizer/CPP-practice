#ifndef QUEUECL_H_
#define QUEUECL_H_
#include "../../ch3/circular/CList.h"
#include <string>
template <class T> class CList;

template <class T>
class QueueCL {
    private:
        typedef CList<T> list_value_type;
        typedef list_value_type* list_ptr_type;
        typedef list_value_type& list_ref_type;
        typedef list_value_type const& list_const_ref_type;

        typedef T value_type;
        typedef T* ptr_type;
        typedef T& ref_type;
        typedef T const& const_ref_type;
    public:
        QueueCL();
        ~QueueCL();
        bool isEmpty() const;
        int getSize() const;
        const_ref_type front() const;
        const_ref_type last() const;
        void dequeue();
        void enqueue(const_ref_type val);
        std::string toString() const;
    private:
        list_ptr_type list;
};

#include "QueueCL.tpp"

#endif