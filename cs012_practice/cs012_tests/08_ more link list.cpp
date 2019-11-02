#include <cstdlib>
#include <iostream>
#include "intlist.h"

using namespace std;

struct IntNode
{
    IntNode *next;
    int data;
}

void IntList::pop_front()
{
    if (head ! = 0)
    {
        IntNode *temp = head;
        head = head -> next; //(*head).next
        delete temp;
    }
}

void IntList::display() const
{
    for(IntNode *curr = head; curr ! = 0; curr = curr->next)
    {
        cout << curr -> data << ' '; //KNOW WHAT ALL THIS IS
    }
}


int main()
{
    
}
