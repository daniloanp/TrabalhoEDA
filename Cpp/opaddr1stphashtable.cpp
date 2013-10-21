#include "opaddr1stphashtable.h"
#include "fnv.h"

OpAddr1StpHashTable::OpAddr1StpHashTable(int tam)
{
    this->tam = tam;
    this->vector = new string[tam];
}
int OpAddr1StpHashTable::hashFunction(string value){
    /*char* c =(char*) value.c_str();
    /*return fnv_32a_str( c, FNV1_32_INIT) % this->tam;
     *
    */
    return 1;
}
bool OpAddr1StpHashTable::insert(string value)
{
    string e;
    int keyI, key;
    keyI = key = this->hashFunction(value);

    do{
        e = this->vector[key];
        if(e.empty()== 0)
        {
            e = value;
            return true;
        }
        else
        {
            if(key < this->tam-1)
                key++;
            else
                key = 0;
        }
    }while(key != keyI);

    return false;
}

bool OpAddr1StpHashTable::remove(string value)
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


bool OpAddr1StpHashTable::find(string value)
{
    string e;
    int keyI, key;
    keyI = key = this->hashFunction(value);

    do{
        e = this->vector[key];
        if(e == value)
        {
            return true;
        }
        else
        {
            if(key < this->tam-1)
                key++;
            else
                key = 0;
        }
    }while(key != keyI || e.empty());
    return false;
}
