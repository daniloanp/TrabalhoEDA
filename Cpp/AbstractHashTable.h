#ifndef ABSTRACTHASHTABLE_H
#define ABSTRACTHASHTABLE_H

class AbstractHashTable
{
public:
    AbstractHashTable();
    //AbstractHashTable(int initial);
    virtual bool insert();
    virtual bool remove();
    virtual bool search();
private:
    //int hashFunction();
};

#endif // ABSTRACTHASHTABLE_H
