#ifndef STACKSLIST_H_

#define STACKSLIST_H_

#include "AStack.h"
#include "../../ch3/single/SingleLinkedList.h"
#include <ostream>

template <typename T>
class StackSList : public AStack<T> {
    private:
        typedef AStack<T> AStack_t;

        typedef SingleLinkedList<T>  SList_t;
        typedef SingleLinkedList<T>* SList_ptr_t;

        typedef typename AStack_t::Value_t Value_t;
        typedef typename AStack_t::Ptr_t Ptr_t;
        typedef typename AStack_t::Ref_t Ref_t;
        typedef typename AStack_t::Ref_const_t Ref_const_t;

    public:
        StackSList();
        ~StackSList();

        virtual inline bool isEmpty() const;
        virtual Ref_const_t top() const;
        virtual void pop();
        virtual void push(Ref_const_t val);
        void inline print(std::ostream& os) {
            os<<(*list);
        }

    private:
        SList_ptr_t list;
};
#include "StackSList.tpp"

#endif