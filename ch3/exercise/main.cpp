#include <iostream>
#include <vector>
#include <random>
#include<cstdlib>
#include<ctime>

typedef float** Matrix2d;
typedef float* Column;
typedef float Row;

void printMatrix(const Matrix2d mat, const size_t matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        std::cout << "M[" << i << "]: ";
        for (int j = 0; j < matrixSize; ++j) {
            if (j != 0) std::cout << ", ";
            std::cout << mat[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void transposeMatrix(const Matrix2d mat, const size_t matrixSize) {
    const size_t lastN = matrixSize-1;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = i + 1; j < matrixSize; ++j) {
            if (i != j) 
            {            
                mat[lastN-i][lastN-j] += mat[i][j];
                mat[i][j] = mat[lastN-i][lastN-j] - mat[i][j];
                mat[lastN-i][lastN-j] -= mat[i][j];
            }
        }
    }
}

size_t generateRandomIdx(const size_t maxIdx) {
    auto divisor = (RAND_MAX + 1u) / (std::max(1, (int)maxIdx));
    size_t res = std::rand() / divisor;

    return res;
}

void removeRandomItemsUntilArrayEmpty(float *arr, const size_t arrSize) {
    std::vector<size_t> activeIndices;
    for (size_t i = 0; i < arrSize; ++i)
        activeIndices.push_back(i);

    auto activeIndicesCount = activeIndices.size();
    do {
        auto randIdx = generateRandomIdx(activeIndicesCount);
        auto idxToRemove = activeIndices[randIdx];
        
        arr[idxToRemove] = NAN;
        activeIndices.erase(activeIndices.begin() + randIdx);

        --activeIndicesCount;
    } while (activeIndicesCount > 0);   
}

int main() {
    const size_t MATRIX_SIZE = 3;
    Matrix2d matrix = new Column[MATRIX_SIZE];

    for (int i = 0; i < MATRIX_SIZE; ++i) {
        std::cout << "ROW " << i << std::endl;
        matrix[i] = new Row[MATRIX_SIZE];
        for (int j = 0; j < MATRIX_SIZE; ++j)
            matrix[i][j] = (i + 1) * (j + 1) + j;
    }
    
    printMatrix(matrix, MATRIX_SIZE);

    transposeMatrix(matrix, MATRIX_SIZE);
    
    printMatrix(matrix, MATRIX_SIZE);

    // ----------------------------------------------

    std::srand(std::time(nullptr));
    size_t randRow = std::rand() / ((RAND_MAX + 1u)/(MATRIX_SIZE));

    removeRandomItemsUntilArrayEmpty(matrix[randRow], MATRIX_SIZE);

    printMatrix(matrix, MATRIX_SIZE);
    

    for (int i = 0; i < MATRIX_SIZE; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

