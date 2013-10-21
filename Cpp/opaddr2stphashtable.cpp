#include "opaddr2stphashtable.h"

OpAddr2StpHashTable::OpAddr2StpHashTable(unsigned int tam)
{
    this->tam = tam;
    this->vector = new string[tam];
}
unsigned int OpAddr2StpHashTable::hashFunction(string value){
    //char* c =(char*) value.c_str();
    //return fnv_32a_str( c, FNV1_32_INIT) % this->tam;
    return 1;
}
bool OpAddr2StpHashTable::insert(string value)
{
    int keyI, key;
    string e;
    keyI = key = this->hashFunction(value);

    do{
        e = this->vector[key];
        if(e.empty())
        {
            e = value;
            return true;
        }
        else
        {
            key = this->hashFunction2(value);
        }
    }while(key != keyI);

    return false;
}

bool OpAddr2StpHashTable::remove(string value)
{
    int key, prevKey;
    prevKey = key = this->hashFunction(value);
    if(this->vector[key].empty())
        return false;
    do
    {
        key++;
        if(this->vector[key].empty() || this->hashFunction(this->vector[key]) != prevKey)
        {
            this->vector[prevKey] = "";
            return true;
        }
        else
        {
            this->vector[prevKey] = this->vector[key];
            prevKey = key;
            if(key < this->tam-1)
                key++;
            else
                key = 0;
        }
    }while(key != prevKey);
    return true;
}


bool OpAddr2StpHashTable::find(string value)
{
    int keyI, key;
    string  e;
    keyI = key = this->hashFunction(value);

    do{
        e = this->vector[key];
        if(e == value)
        {
            return true;
        }
        else if( this->hashFunction(value) != this->hashFunction(this->vector[key]) )
            return false;
        else
        {
            key = this->hashFunction2(value);
        }
    }while(key != keyI || e.empty());

    return false;
}

unsigned int OpAddr2StpHashTable::hashFunction2(string value)
    {
        unsigned char *str = (unsigned char *)value.c_str();
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash % this->tam;
    }
