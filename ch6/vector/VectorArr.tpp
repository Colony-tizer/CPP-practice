#include "VectorArr.h"
#include "Exceptions.h"

#include <type_traits>

template <typename T> 
VectorArr<T>::VectorArr(const int capacity) {
    this->capacity = capacity;
    array = new value_type[capacity];
    size = 0;
}

template <typename T>
VectorArr<T>::~VectorArr() {
    delete[] array;
}

template <typename T>
bool VectorArr<T>::isEmpty() const {
    return getSize() == 0;
}

template <typename T>
int VectorArr<T>::getSize() const {
    return size;
}

template <typename T>
typename VectorArr<T>::const_ref_type VectorArr<T>::at(const int idx) const {
    if (isEmpty()) throw EmptyVectorError();

    if (idx < 0 or idx >= size) throw OutOfRangeError();

    return array[idx];
}

template <typename T>
void VectorArr<T>::setAt(const int idx, const_ref_type val) {
    if (idx < 0 or idx > size) throw OutOfRangeError();

    array[idx] = val;
}

template <typename T>
void VectorArr<T>::insertAt(const int idx, const_ref_type val) {
    if (idx < 0 or idx > size) throw OutOfRangeError();

    ++size;
    if (size == capacity) reserve();

    for (size_t j = size; j != idx and j - 1 >= 0; --j)
        array[j] = array[j - 1];

    array[idx] = val;
}

template <typename T>
void VectorArr<T>::removeAt(const int idx) {
    if (size == 0) throw EmptyVectorError();

    if (idx < 0 or idx >= size) throw OutOfRangeError();

    for (size_t j = idx; j + 1 < size; ++j)
        array[j] = array[j + 1];

    --size;
}

template <typename T>
void VectorArr<T>::clear() {
    size = 0;
}

template <typename T>
std::string VectorArr<T>::toString() const {
    std::string vecStr = "";

    bool isArithmeticType = std::is_arithmetic<value_type>::value;
    for (int i = 0; i < size; ++i) {
        if (isArithmeticType)
            vecStr += std::to_string(array[i]);
        else vecStr += array[i];

        if (i != size - 1) vecStr += " >> "; 
    }

    vecStr += "\n";
    return vecStr;
}

template <typename T>
void VectorArr<T>::reserve() {
    capacity *= 2;

    ptr_type newArr = new value_type[capacity];
    for (int idx = 0; idx < size; ++idx)
        newArr[idx] = array[idx];
    
    delete[] array;
    array = newArr;
}