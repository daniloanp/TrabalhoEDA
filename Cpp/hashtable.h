#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "LinkedList.h"

class HashTable
{
private:
    LinkedList* lists;
    int hashFunction(string value);
public:
    HashTable(int tam);

    bool insert(string value);
    bool remove(string value);
    bool find(string value);

};

#endif // HASHTABLE_H
