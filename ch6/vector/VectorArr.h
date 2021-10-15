#ifndef VECTORARR_H_
#define VECTORARR_H_
#include "VectorBase.h"
#include <string>
template <class T> class VectorBase;

template <class T> 
class VectorArr : public VectorBase<T> {
    private:
        typedef T value_type;
        typedef T* ptr_type;
        typedef T& ref_type;
        typedef T const& const_ref_type;
    public:
        VectorArr(const int capacity = 10);
        ~VectorArr();
        virtual bool isEmpty() const;
        virtual int getSize() const;
        virtual const_ref_type at(const int i) const;
        virtual void setAt(const int i, value_type const& val);
        virtual void insertAt(const int i, T const& val);
        virtual void erase(const int i);
        virtual std::string toString() const;
    private:
        void reserve();
    private:
        ptr_type array;
        int capacity;
        int size;
};
#include "VectorArr.tpp"
#endif