#include <iostream>
#include <math.h>
#include <random>
typedef float** matrix;
typedef float* column;
typedef float row;

void printMatrix(const matrix mat, const size_t n, const size_t m) {
    for (int i = 0; i < n; ++i) {
        std::cout<<"M["<<i<<"]: ";
        for (int j = 0; j < m; ++j) {
            if (j != 0) std::cout<<", ";
            std::cout<<mat[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
void transposeMatrix(const matrix mat, const size_t n, const size_t m) {
    const size_t lastN = n-1, lastM = m-1;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < m; ++j) {
            if (i == j) continue;
            mat[lastN-i][lastM-j] += mat[i][j];
            mat[i][j] = mat[lastN-i][lastM-j] - mat[i][j];
            mat[lastN-i][lastM-j] -= mat[i][j];
        }
    }
}
template <class T>
void removeRandom(T *arr, const size_t len) {
    if (len > 1) {
        int randInd = std::rand()/((RAND_MAX+1u)/(len-1)) ;
        T* newArr = new T(len-1);
        for (int i = 0, j = 0; i < len-1; ++i, ++j) {
            newArr[i] = (i == randInd) ? arr[++j] : arr[i];
        }
        delete arr;
        arr = newArr;
        removeRandom(arr, len-1);
    } else delete arr;
    
}
int main() {
    const size_t n = 3, m = 3;
    matrix a = new column[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new row[m];
        for (int j = 0; j < m; ++j)
            a[i][j] = (i+1)*(j+1) + j;
    }
    
    printMatrix(a, n, m);

    transposeMatrix(a, n, m);
    
    printMatrix(a, n, m);

    removeRandom(a[0], m);
}

