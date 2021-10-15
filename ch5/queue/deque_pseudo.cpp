class DequeArr {
    public:  
        DequeArr(inCap) {
            init_array(array, inCap);
            size = firstInd = lastInd = 0;
        }
        inserFront(val) {
            if (size == capacity) throw FULL;
            if (size > 0) firstInd = firstInd - 1 < 0 ? capacity - 1 : firstInd - 1;
            array[firstInd] = val;
            ++size;
        }
        insertBack(val) {
            if (size == capacity) throw FULL;
            if (size > 0) lastInd = (lastInd + 1) % capacity;
            array[lastInd] = val;
            ++size;
        }
        front() {
            if (size == 0) throw EMPTY;
            return array[firstInd];
        }
        last() {
            if (size == 0) throw EMPTY;
            return array[lastInd];
        }
        removeFront() {
            if (size == 0) throw EMPTY;
            firstInd = (firstInd + 1) % capacity;
            --size;
        }
        removeBack() {
            if (size == 0) throw EMPTY;
            lastInd = (lastInd - 1 < 0) ? capacity - 1 : lastInd - 1;
            --size;
        }
    private:
        array;
        capacity (cap);
        size;
        firstInd, lastInd;
};