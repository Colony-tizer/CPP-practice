#include <iostream>
#include <math.h>
//#include <string>
int factorial(const int num) {
    int res = 1;
    if (num > 0) {
        res = num * factorial(num-1);
    }
    return res;
}
#pragma region 
// Ruler section
void drawOneTick(int length, int label = -1) {
    for (int i = 0; i < length; ++i)
        std::cout<<"-";
    if (label >= 0) std::cout<<" "<<std::to_string(label);
    std::cout<<std::endl;
}
void drawTicks(int tickLen) {
    if (tickLen > 0) {
        drawTicks(tickLen-1);
        drawOneTick(tickLen);
        drawTicks(tickLen-1);
    }
}
void drawRuler(int nCentimetres, int majorLength) {
    for (int i = 0; i <= nCentimetres; ++i) {
        if (i > 0)
            drawTicks(majorLength-1);
        drawOneTick(majorLength, i);
    }
}
#pragma endregion
#pragma region
// array manipulations
template <class T>
void recReverseArray(T* arr, const unsigned int i, const unsigned int j) {
    // i -- index of first item
    // j -- index of last item
    if (i != j) {
        std::swap(arr[i], arr[j]);
        reverseArray(arr, i+1, j-1);
    }
}
template <class T>
void itReverseArray(T* arr, const unsigned int i, const unsigned int j) {
    // i -- index of first item
    // j -- index of last item
    int start = i, end = j;
    while (start != end) {
        std::swap(arr[start], arr[end]);
        ++start, --end;
    }
}
template <class T>
int binarySum(T* arr, const unsigned int i, const unsigned int n) {
    if (n == 1)
        return arr[i];
    return binarySum(arr, i, (int)ceil(n/2)) + binarySum(arr, i + (int)ceil(n/2), floor(n/2));
}
#pragma endregion
unsigned int binaryFib(const unsigned int num) {
    // exponential num of calls
    if (num > 1) return binaryFib(num-1) + binaryFib(num-2);
    return num;
}
unsigned int* linearFib(const unsigned int num) {
    // returns pair of fib nums f_k, f_k-1
    if (num > 1) {
        unsigned int *res = linearFib(num-1);
        res[0] += res[1];
        res[1] = res[0] - res[1];
        return res;
    }
    else {
        unsigned int *pair = new unsigned int(2);
        pair[0] = num; pair[1] = 0;
        return pair;
    }
}
int main() {
    int num = factorial(3);
    std::cout<<num<<std::endl<<std::endl;
    drawRuler(5, 1);

    const int max = 5;
    const int init_val = (int)'a';
    char *array = new char[max]();
    for (int i = 0; i < max; ++i) {
        if (i == 0)
            array[i] = init_val;
        else array[i] = array[0] + i;
    }
    //std::cout<<array<<std::endl;
    itReverseArray(array, 0, max-1);
    for (int i = 0; i < max; ++i) {
        if (i != 0) std::cout<<", ";
        std::cout<<array[i];
    }
    std::cout<<std::endl;
    std::cout<<binarySum(array, 0, max-1);
    std::cout<<std::endl;
    unsigned int fiboNum = binaryFib(2);
    unsigned int *res = linearFib(4);
    delete res;
}