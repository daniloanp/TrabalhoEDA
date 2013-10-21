#include "hashtable.h"

#ifdef __cplusplus
extern "C"{
#endif

#include "fnv.h"

#ifdef __cplusplus
}
#endif
HashTable::HashTable(int tam)
{
    this->lists = new LinkedList[tam];
}

int HashTable::hashFunction(string value)
{
    return 1;
}

bool HashTable::insert(string value)
{
    LinkedList* list;
    int key = this->hashFunction(value);
    list = &(this->lists[key]);
    if(list == NULL)
        return false;
    return list->insert(value);
}

bool HashTable::remove(string value)
{
    LinkedList* list;
    int key = this->hashFunction(value);
    list = &(this->lists[key]);
    if(list ==NULL)
        return false;
    return list->remove(value);
}


bool HashTable::find(string value)
{
    LinkedList* list;
    int key = this->hashFunction(value);
    list = &(this->lists[key]);
    if(list ==NULL)
        return false;
    return list->find(value);
}


