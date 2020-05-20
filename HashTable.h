#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <list>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
using namespace std;
using std::chrono::system_clock;

const size_t DEFAULT_SIZE = 1048576;

template<typename T>
class HashTable
{
public:
    HashTable(size_t tableSz = DEFAULT_SIZE);
    template<typename InputIterator> HashTable(InputIterator first, InputIterator last, size_t tableSz = DEFAULT_SIZE);
    ~HashTable() { delete[] hashTable; }
    class iterator;
    iterator begin() const;
    iterator end() const;
    void insert(const T& t);
    iterator find(const T&);
private:
    list<T>* hashTable;
    size_t hash_it(const string&);
    size_t tableSize;
};

template<typename T>
class HashTable<T>::iterator
{
private:
    list<T>* bucket;
    typename list<T>::iterator node;
    list<T>* lastBucket;
public:
    iterator(list<T>* _bucket, list<T>* _lastBucket, typename list<T>::iterator _node)
    {
        bucket = _bucket;
        lastBucket = _lastBucket;
        node = _node;
    }
    iterator& operator++()
    {
        node++;
        if (node == bucket->end() && bucket != lastBucket)
        {
            while ((++bucket)->empty() && bucket != lastBucket);
            node = bucket->begin();
        }
        return *this;
    }
    const T& operator*() const { return *node; }
    bool operator==(const iterator & b) const { return b.bucket == bucket && b.node == node; }
    bool operator!=(const iterator & b) const { return !(b == *this);}
};

            template<typename T>
            typename HashTable<T>::iterator HashTable<T>::begin() const
            {
                list<T>* p = hashTable;
                while (p->empty() && p != hashTable + tableSize - 1){ p++; }        //bucket, lastBucket not in scope
                return iterator(p, hashTable + tableSize - 1, p->begin());
            }

            template<typename T>
            typename HashTable<T>::iterator HashTable<T>::end() const
            {
                return iterator(hashTable + tableSize - 1, hashTable + tableSize - 1, (hashTable + tableSize - 1)->end());
            }

            template<typename T>
            void HashTable<T>::insert(const T& t)
            {
                int index = hash_it(t);
                if(hashTable[index].empty()) hashTable[index].push_back(t);
                typename list<T>::iterator it = std::find(hashTable[index].begin(), hashTable[index].end(), t);
                if (it == hashTable[index].end())
                {
                    hashTable[index].push_back(t);
                }
            }
            template<typename T>
            typename HashTable<T>::iterator HashTable<T>::find(const T& t)
            {
                size_t index = hash_it(t);
                typename list<T>::iterator it = std::find(hashTable[index].begin(), hashTable[index].end(), t);
                if (it == hashTable[index].end())
                    return end();
                else
                    return iterator(hashTable + index, hashTable + tableSize - 1, it);
            }


            template<typename T>
            HashTable<T>::HashTable(size_t tableSz)
            {
                tableSize = tableSz;
                hashTable = new list<T>[tableSz];
            }

            template<typename T>
            template<typename InputIterator>
            HashTable<T>::HashTable(InputIterator first, InputIterator last, size_t tableSz)
            {
                tableSize = tableSz;
                hashTable = new list<T>[tableSz];
                while (first != last)
                {
                    insert(*(first++));
                }
            }

            template<typename T> size_t HashTable<T>::hash_it(const string & key)
            {
                size_t hash = 0;
                for (size_t i = 0, n = key.size(); i < n; i++)
                    hash = (hash << 2) ^ key[i];
                return hash % tableSize;
            }

            template<typename T>
            ostream& operator<<(ostream & os, const HashTable<T> & table)
            {
                for(auto a : table)
                    os << a << endl;

                return os;
            }

#endif
