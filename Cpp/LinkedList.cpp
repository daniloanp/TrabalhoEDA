#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->no = NULL;
}

bool LinkedList::find(string value)
{
    No* no = this->no;

    while(no!=NULL)
        if(no->value == value)
            return true;
        else
            no = no->next;

    return false;
}
bool LinkedList::insert(string value)
{

    No* no = this->no;
    if(no == NULL)
    {
        no = new No();
        no->value = value;
        return true;
    }else do
    {
        if(no->next == NULL)
        {
            no->next = new No();
            no->next->value = value;
            return true;
        }
        else
        {
            no = no->next;
        }

    }while(no!=NULL);

    return false;
}

bool LinkedList::remove(string value)
{
    No* no = this->no;
    No *parentNo = this->no;
    while(no!=NULL)
        if(no->value == value)
        {
            parentNo->next = no->next;
            no->next == NULL;
            delete(no);
            return true;
        }
        else
        {
            parentNo = no;
            no = no->next;

        }

    return false;

}

















