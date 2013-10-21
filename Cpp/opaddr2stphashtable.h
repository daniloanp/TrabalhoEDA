#ifndef OPADDR2StpHASHTABLE_H
#define OPADDR2StpHASHTABLE_H

#include <string>
#ifdef __cplusplus
extern "C"{
#endif

#include "fnv.h"

#ifdef __cplusplus
}
#endif
using std::string;

class OpAddr2StpHashTable
{
private:
    string * vector;
    unsigned int hashFunction(string value);
    unsigned int hashFunction2(string value);
    unsigned int tam;
public:
    OpAddr2StpHashTable(unsigned int tam);
    bool insert(string value);
    bool remove(string value);
    bool find(string value);
};

#endif // OPADDR2StpHASHTABLE_H
