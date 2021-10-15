#include "SList.h"

template <class T>
class SNode {
    public:
        SNode() : value(), next(nullptr) {}
        SNode(T& val) : value(val), next(nullptr) {}
        ~SNode() {}
    private:
        T value;
        SNode<T>* next;
        
        friend class SList<T>;
};