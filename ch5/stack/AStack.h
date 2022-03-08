#ifndef ASTACK_H_

#define ASTACK_H_

template <typename T>
class AStack {
    protected:
        static const int DFLT_STACK_CAP = 128;

        typedef T  Value_t;
        typedef T* Ptr_t;
        typedef T& Ref_t;
        typedef T const& Ref_const_t;
        
    public:
        AStack() {}
        virtual ~AStack() {}
        
        int getSize() const { return curItemsNum; }
        inline bool isEmpty() const { return getSize() <= 0; }
        
        virtual Ref_const_t top() const = 0;
        virtual void pop() = 0;
        virtual void push(Ref_const_t val) = 0;

    protected:
        int curItemsNum;
};
#endif