#ifndef VECTORARR_H_

#define VECTORARR_H_

#include "VectorBase.h"
#include <string>

template <typename T> class VectorBase;

template <typename T> 
class VectorArr : public VectorBase<T> {
    private:
        typedef T value_type;
        typedef T* ptr_type;
        typedef T& ref_type;
        typedef T const& const_ref_type;

    public:
        VectorArr(const int capacity = 10);
        ~VectorArr();

        bool isEmpty() const override;
        int getSize() const override;

        const_ref_type at(const int idx) const override;

        void setAt(const int idx, const_ref_type val) override;
        void insertAt(const int idx, const_ref_type val) override;
        void removeAt(const int idx) override;
        void clear() override;

        std::string toString() const override;

    private:
        void reserve();

    private:
        ptr_type array;
        int capacity;
        int size;
};

#include "VectorArr.tpp"

#endif