#include "VectorArr.h"
#include <iostream>

using namespace std;

const int FIRST_IDX = 0;

void removeAll(VectorArr<int>& vector) {
    cout << "Clearing the vector..." << endl;
    while (vector.getSize() > 0)
        vector.removeAt(FIRST_IDX);
}

void testRemoveFromEmpty(VectorArr<int>& emptyVector) {
    cout << "Removing from empty vector..." << endl;
    try {
        emptyVector.removeAt(FIRST_IDX);
    } catch (EmptyVectorError& ex) {
        cout << "Could not remove item at index " << FIRST_IDX << ". Reason: " << ex.what() << endl;
    }
}

void testInsertAtEnd(VectorArr<int>& vector) {
    const int FIRST_ITEM = 1;
    const int SECOND_ITEM = 2;
    const int THIRD_ITEM = 3;

    cout << "Inserting " << FIRST_ITEM << " at the end of the vector:" << endl;
    vector.insertAt(vector.getSize(), FIRST_ITEM);

    cout << vector.toString() << endl;

    cout << "Inserting " << SECOND_ITEM << " at the end of the vector:" << endl;
    vector.insertAt(vector.getSize(), SECOND_ITEM);

    cout << vector.toString() << endl;

    cout << "Inserting " << THIRD_ITEM << " at the end of the vector:" << endl;
    vector.insertAt(vector.getSize(), THIRD_ITEM);

    cout << vector.toString() << endl;
}

void testSetAt(VectorArr<int>& vector) {
    const int NEW_VALUE = 10;
    cout << "Set the first element to " << NEW_VALUE << ":" << endl;
 
    vector.setAt(FIRST_IDX, NEW_VALUE);

    cout << vector.toString() << endl;;
}

void testInsertAtMiddle(VectorArr<int>& vector) {
    const int MID_IDX = vector.getSize() / 2;
    cout << "Inserting 13 at index " << MID_IDX << ":" << endl;

    vector.insertAt(MID_IDX, 13);
 
    cout << vector.toString() << endl;
}

void testInsertAtInvalidIdx(VectorArr<int>& vector) {
    const int NEGATIVE_IDX = -1;
    try {
        vector.removeAt(NEGATIVE_IDX);
    } catch (OutOfRangeError& ex) {
        cout << "Could not remove item at index " << NEGATIVE_IDX << ". Reason: " << ex.what() << endl;
    }

    const int OUT_OF_BOUNDS_IDX = vector.getSize() + 1;
    try {
        vector.removeAt(OUT_OF_BOUNDS_IDX);
    } catch (OutOfRangeError& ex) {
        cout << "Could not remove item at index " << OUT_OF_BOUNDS_IDX << ". Reason: " << ex.what() << endl << endl;
    }
}


int main() {
    VectorArr<int> vector(3);

    testInsertAtEnd(vector);
    testSetAt(vector);
    testInsertAtMiddle(vector);
    testInsertAtInvalidIdx(vector);

    cout << "Contents of vector:";
    cout << vector.toString() << endl;

    cout << "The size of the vector " << vector.getSize() << endl << endl;

    removeAll(vector);
    testRemoveFromEmpty(vector);

    return 0;
}