#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using std::string;
class LinkedList
{
private:
    class No
    {
    public:
        string value;
        No* next;
        No()
        {
            next = NULL;
        }
    };
    No* no;
public:
    LinkedList();
    bool  find(string value);
    bool insert(string value);
    bool remove(string value);


};

#endif // LINKEDLIST_H
