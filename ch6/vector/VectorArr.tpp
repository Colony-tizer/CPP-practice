#include "VectorArr.h"
#include "Exceptions.h"
#include <type_traits>
template <class T> 
VectorArr<T>::VectorArr(const int capacity) {
    this->capacity = capacity;
    array = new value_type[capacity];
    size = 0;
}
template <class T>
VectorArr<T>::~VectorArr() {
    delete[] array;
}
template <class T>
bool VectorArr<T>::isEmpty() const {
    return getSize() == 0;
}
template <class T>
int VectorArr<T>::getSize() const {
    return size;
}
template <class T>
typename VectorArr<T>::const_ref_type VectorArr<T>::at(const int i) const {
    if (isEmpty()) throw EmptyVectorError();
    if (i < 0 || i >= capacity) throw OutOfRangeError();
    return array[i];
}
template <class T>
void VectorArr<T>::setAt(const int i, value_type const& val) {
    if (i < 0 || i >= size) throw OutOfRangeError();
    array[i] = val;
}
template <class T>
void VectorArr<T>::insertAt(const int i, T const& val) {
    if (i < 0 || i > size) throw OutOfRangeError();
    if (i == size && size == capacity) reserve();
    for (int j = size-1; j > i; --j)
        array[j+1] = array[j];
    array[i] = val;
    ++size;
}
template <class T>
void VectorArr<T>::erase(const int i) {
    if (isEmpty()) throw EmptyVectorError();
    if (i < 0 || i >= size) throw OutOfRangeError();
    for (int j = size-1; j > i; --j)
        array[j-1] = array[j];
    --size;
}
template <class T>
std::string VectorArr<T>::toString() const {
    std::string vecStr = "";
    bool isArithm = std::is_arithmetic<value_type>::value;
    for (int i = 0; i < size; ++i) {
        if (isArithm)
            vecStr += std::to_string(array[i]);
        else vecStr += array[i];
        if (i != size - 1) vecStr += " >> "; 
    }
    vecStr += "\n";
    return vecStr;
}
template <class T>
void VectorArr<T>::reserve() {
    capacity *= 2;
    ptr_type newArr = new value_type[capacity]; 
    for (int i = 0; i < size; ++i) 
        newArr[i] = array[i];
    delete[] array;
    array = newArr;
}