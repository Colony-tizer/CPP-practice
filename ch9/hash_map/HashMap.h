#ifndef HASHMAP_H_
#define HASHMAP_H_
#include "../map/Entry.h"
#include <list>
#include <vector>
template <class K, class V> class Entry;

template <class K, class V, class H> 
class HashMap {
    public:
        typedef Entry<const K, V> val_entry;
        typedef val_entry& ref_entry;
        typedef val_entry const& const_ref_entry;
        class Iterator;
    protected:
        typedef typename std::list<val_entry> val_bucket;
        typedef val_bucket& ref_bucket;
        typedef val_bucket const& const_ref_bucket;

        typedef typename std::vector<val_bucket> buckets_vec;
        typedef buckets_vec& ref_buckets_vec;
        typedef buckets_vec const& const_ref_buckets_vec;
        typedef buckets_vec* ptr_buckets_vec;
        typedef buckets_vec const* const_ptr_buckets_vec;

        typedef typename val_bucket::iterator bucket_it;
        typedef bucket_it& ref_bucket_it;
        typedef bucket_it const& const_ref_bucket_it;

        typedef typename buckets_vec::iterator buckets_vec_it;
        typedef buckets_vec_it& ref_buckets_vec_it;
        typedef buckets_vec_it const& const_ref_buckets_vec_it;
    public:
        HashMap(int size = 100);
        ~HashMap();
        bool isEmpty() const;
        int getSize() const;
        Iterator find(const K& key);
        Iterator put(const K& key, const V& val);
        void erase(const K& key);
        void erase(const Iterator& it);
        Iterator begin();
        Iterator end();
    protected:
        Iterator finder(const K& key);
        Iterator inserter(const Iterator& it, const_ref_entry entry);
        void eraser(const Iterator& it);
        static void nextEntry(Iterator& it) 
            { ++it._bucketIt; }
        static bool endOfBucket(const Iterator& it) 
            { return it._bucketIt == it._bucketsVecIt->end(); }
    private:
        int _size;
        H _hashFun;
        buckets_vec _bucketsVec;
    public:
        class Iterator {
            public:
                Iterator(const buckets_vec& bucketsVec, const buckets_vec_it& bucketsVecIt, const bucket_it& bucketIt = bucket_it()) : _bucketIt(bucketIt), _bucketsVecIt(bucketsVecIt), _bucketsVec(&bucketsVec) {}
                ref_entry operator*() const;
                bool operator==(const Iterator& it) const;
                Iterator& operator++();
                Iterator& operator++(int);
            private:
                bucket_it _bucketIt;
                buckets_vec_it _bucketsVecIt;
                const_ptr_buckets_vec _bucketsVec;
            public:
                friend class HashMap;
        };
};
#include "HashMap.tpp"
#endif