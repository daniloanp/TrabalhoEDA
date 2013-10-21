#ifndef OPADDR1STPHASHTABLE_H
#define OPADDR1STPHASHTABLE_H
#include<string>
#ifdef __cplusplus
extern "C"{
#endif

#include "fnv.h"

#ifdef __cplusplus
}
#endif


using std::string;

class OpAddr1StpHashTable
{
private:
    string * vector;
    int hashFunction(string value);
    int tam;
public:
    OpAddr1StpHashTable(int tam);
    bool insert(string value);
    bool remove(string value);
    bool find(string value);
};

#endif // OPADDR1STPHASHTABLE_H
