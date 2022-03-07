#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

#pragma region Ruler

void drawOneTick(int length, int label = -1) {
    for (int i = 0; i < length; ++i) {
        std::cout<<"-";
    }
    if (label >= 0) std::cout<<" "<<std::to_string(label);
    std::cout<<std::endl;
}
void drawTicks(int tickLen) {
    if (tickLen > 0) {
        drawTicks(tickLen - 1);
        drawOneTick(tickLen);
        drawTicks(tickLen - 1);
    }
}
void drawRuler(int nCentimetres, int majorLength) {
    for (int i = 0; i <= nCentimetres; ++i) {
        if (i > 0)
            drawTicks(majorLength - 1);
        drawOneTick(majorLength, i);
    }
}

#pragma endregion Ruler

#pragma region Array Manipulations

template <typename T>
void recursiveReverseArray(T* arr, const unsigned int firstIdx, const unsigned int lastIdx) {
    if (firstIdx != lastIdx) {
        std::swap(arr[firstIdx], arr[lastIdx]);
        recursiveReverseArray(arr, firstIdx + 1, lastIdx - 1);
    }
}
template <typename T>
void iterativeReverseArray(T* arr, const unsigned int firstIdx, const unsigned int lastIdx) {
    int start = firstIdx, end = lastIdx;
    while (start != end) {
        std::swap(arr[start], arr[end]);
        ++start, --end;
    }
}

template <typename T>
int binarySum(T* arr, const unsigned int i, const unsigned int n) {
    if (n == 1)
        return arr[i];
    return binarySum(arr, i, (int)ceil(n / 2)) + binarySum(arr, i + (int)ceil(n / 2), floor(n / 2));
}

#pragma endregion Array Manipulations

int factorial(const int num) {
    int res = 1;
    if (num > 0) {
        res = num * factorial(num - 1);
    }
    return res;
}

unsigned int binaryFib(const unsigned int num) {
    // exponential num of calls
    if (num > 1) return binaryFib(num-1) + binaryFib(num-2);
    return num;
}

std::pair<uint, uint>* linearFib(const unsigned int num) {
    if (num > 1) {
        auto res = linearFib(num - 1);
        res->first += res->second;
        res->second = res->first - res->second;
        return res;
    }
    else {
        auto *pair = new std::pair<uint, uint>(num, 0);
        return pair;
    }
}

void factorialDemo() {
    const uint FACTORIAL_NUM = 3;

    int num = factorial(FACTORIAL_NUM);
    std::cout<<"Factorial of "<<FACTORIAL_NUM<<" is "<<num<<std::endl<<std::endl;
}

void rulerDrawDemo() {
    const uint LENGTH_CM = 10;
    const uint MAJOR_LENGTH = 3;
    
    std::cout<<"Here is a Ruler for you:"<<std::endl;

    drawRuler(LENGTH_CM, MAJOR_LENGTH);
}

void arrayManipulationDemo() {
    const int ARRAY_SIZE = 5;
    const int INIT_VAL = (int)'a';

    std::cout<<std::endl;
    std::cout<<"Array manipulation demo:"<<std::endl;

    char *array = new char[ARRAY_SIZE]();
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (i == 0)
            array[i] = INIT_VAL;
        else array[i] = array[0] + i;
    }
    
    std::cout<<"Reversed array:"<<std::endl;
    // iterativeReverseArray(array, 0, ARRAY_SIZE - 1);
    recursiveReverseArray(array, 0, ARRAY_SIZE - 1);
    std::cout<<array<<std::endl;

    std::cout<<"Numeric representation of the array:"<<std::endl;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        std::cout<<(int)array[i]<<" ";
    }

    std::cout<<std::endl;
    std::cout<<"Sum of the array:"<<std::endl;
    std::cout<<binarySum(array, 0, ARRAY_SIZE - 1);
    std::cout<<std::endl<<std::endl;

    delete array;
}

void fibonacciDemo() {
    const uint NUMBER = 42;
    std::cout<<"Fibonacci calculation demo:"<<std::endl;

    std::cout<<"Calculation using Linear method... "<<std::endl;
    auto linearFibPairPtr = linearFib(NUMBER);
    std::cout<<NUMBER<<" Fibonacci number is "<<linearFibPairPtr->first<<std::endl;

    std::cout<<"Calculation using Binary method..."<<std::endl;
    unsigned int binaryFiboNum = binaryFib(NUMBER);
    std::cout<<NUMBER<<" Fibonacci number is "<<binaryFiboNum<<std::endl;

    delete linearFibPairPtr;
}

int main() {
    factorialDemo();
    rulerDrawDemo();
    arrayManipulationDemo();
    fibonacciDemo();
    
    return 0;
}