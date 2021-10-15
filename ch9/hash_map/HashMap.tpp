#include "HashMap.h"

template <class K, class V, class H>
HashMap<K,V,H>::HashMap(int size) {
    _size = 0; 
    _bucketsVec = buckets_vec(size);
}
template <class K, class V, class H>
HashMap<K,V,H>::~HashMap() {
}
template <class K, class V, class H>
bool HashMap<K,V,H>::isEmpty() const {
    return getSize() == 0;
}
template <class K, class V, class H>
int HashMap<K,V,H>::getSize() const {
    return _size;
}
template <class K, class V, class H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::find(const K& key) {
    Iterator it = finder(key);
    if (endOfBucket(it)) it = end();
    return it;
}
template <class K, class V, class H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::put(const K& key, const V& val) {
    Iterator it = finder(key);
    if (endOfBucket(it)) it = inserter(it, val_entry(key, val));
    else it._bucketIt->setValue(val);
    return it;
}
template <class K, class V, class H>
void HashMap<K,V,H>::erase(const K& key) {
    Iterator it = find(key);
    if (endOfBucket(key)) throw "HashMapEraseNonExistentException";
    eraser(it);
}
template <class K, class V, class H>
void HashMap<K,V,H>::erase(const Iterator& it) {
    eraser(it);
}
template <class K, class V, class H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::begin() {
    if (isEmpty()) return end();
    buckets_vec_it bckVecIt = _bucketsVec.begin();
    while (bckVecIt->empty()) ++bckVecIt;
    return Iterator(_bucketsVec, bckVecIt, bckVecIt->begin());
}
template <class K, class V, class H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::end() {
    return Iterator(_bucketsVec, _bucketsVec.end());
}
template <class K, class V, class H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::finder(const K& key) {
    int ind = _hashFun(key) % _bucketsVec.size();
    buckets_vec_it bktVecIt = _bucketsVec.begin() + ind;
    Iterator it(_bucketsVec, bktVecIt, bktVecIt->begin());
    while (!endOfBucket(it) && (*it).key() != key) nextEntry(it);
    return it;
}
template <class K, class V, class H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::inserter(const Iterator& it, const_ref_entry entry) {
    bucket_it insertPos = it._bucketsVecIt->insert(it._bucketIt, entry);
    ++_size;
    return Iterator(_bucketsVec, it._bucketsVecIt, insertPos);
}
template <class K, class V, class H>
void HashMap<K,V,H>::eraser(const Iterator& it) {
    it._bucketsVecIt->erase(it._bucketIt);
    --_size;
}

template <class K, class V, class H>
typename HashMap<K,V,H>::ref_entry HashMap<K,V,H>::Iterator::operator*() const {
    return *_bucketIt;
}
template <class K, class V, class H>
bool HashMap<K,V,H>::Iterator::operator==(const Iterator& it) const {
    return (_bucketsVec == it._bucketsVec) && (_bucketsVecIt == _bucketsVec->end() || _bucketIt == it._bucketIt);
}
template <class K, class V, class H>
typename HashMap<K,V,H>::Iterator& HashMap<K,V,H>::Iterator::operator++() {
    ++_bucketIt;
    if (endOfBucket(*this)) {
        ++_bucketsVecIt;
        while (_bucketsVecIt != _bucketsVec->end() && _bucketsVecIt->empty()) 
            ++_bucketsVecIt;
        if (_bucketsVecIt != _bucketsVec->end()) _bucketIt = _bucketsVecIt->begin();
    }
    return *this;
}
template <class K, class V, class H>
typename HashMap<K,V,H>::Iterator& HashMap<K,V,H>::Iterator::operator++(int) {
    return this->operator++();
}