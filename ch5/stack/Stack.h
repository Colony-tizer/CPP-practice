#ifndef STACK_H_

#define STACK_H_

#include "Exceptions.h"
#include "AStack.h"

template <typename T>
class Stack : public AStack<T> {        
    private:
        typedef AStack<T> AStack_t;

        typedef typename AStack_t::Value_t Value_t;
        typedef typename AStack_t::Ptr_t Ptr_t;
        typedef typename AStack_t::Ref_t Ref_t;
        typedef typename AStack_t::Ref_const_t Ref_const_t;

    public:
        Stack(const int capacity = Stack::DFLT_STACK_CAP);
        ~Stack();

        virtual Ref_const_t top() const;
        virtual void pop();
        virtual void push(Ref_const_t val);

    private:
        Ptr_t array;
        int capacity;
};

#include "Stack.tpp"

#endif