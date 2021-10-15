#ifndef STACKSLIST_H_
#define STACKSLIST_H_
#include "AStack.h"
#include "../../ch3/single/SingleLinkedItem.h"
#include <ostream>

template <class T>
class StackSList : public AStack<T> {
    private:
        typedef AStack<T> baseClass;

        typedef SingleLinkedList<T> slistType;
        typedef SingleLinkedList<T>* ptr_slistType;

        typedef typename baseClass::val_type val_type;
        typedef typename  baseClass::ref_type ref_type;
        typedef typename  baseClass::ptr_type ptr_type;
        typedef typename  baseClass::const_ref_type const_ref_type;
    public:
        StackSList();
        ~StackSList();
        virtual inline bool isEmpty() const;
        virtual const_ref_type top() const;
        virtual void pop();
        virtual void push(const_ref_type val);
        void print(std::ostream& os) {
            os<<*list;
        }
    private:
        ptr_slistType list;
};
#include "StackSList.tpp"

#endif