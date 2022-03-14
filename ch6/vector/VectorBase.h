#ifndef VECTORBASE_H_

#define VECTORBASE_H_

#include <string>

template <typename T>
class VectorBase {
    public:
        VectorBase() {}
        virtual ~VectorBase() {}

        virtual bool isEmpty() const = 0;
        virtual int getSize() const = 0;

        virtual T const& at(const int idx) const = 0;

        virtual void setAt(const int idx, T const& val) = 0;
        virtual void insertAt(const int idx, T const& val) = 0;
        virtual void removeAt(const int idx) = 0;
        virtual void clear() = 0;

        virtual std::string toString() const = 0;
};

#endif