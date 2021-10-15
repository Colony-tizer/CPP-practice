#ifndef VECTORBASE_H_
#define VECTORBASE_H_
#include <string>
template <class T>
class VectorBase {
    public:
        VectorBase() {}
        ~VectorBase() {}
        virtual bool isEmpty() const = 0;
        virtual int getSize() const = 0;
        virtual T const& at(const int i) const = 0;
        virtual void setAt(const int i, T const& val) = 0;
        virtual void insertAt(const int i, T const& val) = 0;
        virtual void erase(const int i) = 0;
        virtual std::string toString() const = 0;
};
#endif