#ifndef STACK_H_
#define STACK_H_

#include "Exceptions.h"
#include "AStack.h"

template <class T>
class Stack : public AStack<T> {        
    private:
        typedef AStack<T> baseClass;

        typedef typename baseClass::val_type val_type;
        typedef typename  baseClass::ref_type ref_type;
        typedef typename  baseClass::ptr_type ptr_type;
        typedef typename  baseClass::const_ref_type const_ref_type;
    public:
        Stack(const int capacity = Stack::DFLT_STACK_CAP);
        ~Stack();
        virtual const_ref_type top() const;
        virtual void pop();
        virtual void push(const_ref_type val);

    private:
        ptr_type array;
        int arraySize;
};

#include "Stack.tpp"

#endif