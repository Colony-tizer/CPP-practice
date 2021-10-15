#include "HashMap.h"
#include <iostream>
struct HashInt {
    int operator()(int key) {
        return key;
    }
};

int main() {
    HashMap<int, int, HashInt> hm;
    hm.put(10, 5);
    auto entry = hm.find(10);
    std::cout<<(*entry).key()<<": "<<(*entry).value()<<std::endl;
}