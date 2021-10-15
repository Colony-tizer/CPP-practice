#ifndef ASTACK_H_
#define ASTACK_H_
template <class T>
class AStack {
    protected:
        static const int DFLT_STACK_CAP = 128;

        typedef T val_type;
        typedef T* ptr_type;
        typedef T& ref_type;
        typedef T const& const_ref_type;
        
    public:
        AStack() {}
        virtual ~AStack() {}
        virtual int getSize() const { return curItemsNum; }
        virtual inline bool isEmpty() const { return getSize() <= 0; }
        virtual const_ref_type top() const = 0;
        virtual void pop() = 0;
        virtual void push(const_ref_type val) = 0;

    protected:
        int curItemsNum;
};
#endif