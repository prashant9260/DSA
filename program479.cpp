#include<iostream>
using namespace std;

#pragma pack(1)
class node
{
    public:
        int data;
        struct node *next;
        struct node *prev;

        node(int no)
        {
            data = no;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLLL
{
    public:
        node * first;
        int iCount;

        DoublyLLL();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

DoublyLLL :: DoublyLLL()
{

}

void DoublyLLL :: InsertFirst(int no)
{
    
}

void  DoublyLLL :: InsertLast(int no)
{
    
}

void  DoublyLLL :: InsertAtPos(int no ,int pos)
{
    
}

void  DoublyLLL :: DeleteFirst()
{
    
}

void  DoublyLLL :: DeleteLast()
{
    
}

void  DoublyLLL :: DeleteAtPos(int pos)
{
    
}

void  DoublyLLL :: Display()
{
    
}

int  DoublyLLL ::Count()
{
    return iCount;
}

int main()
{
    DoublyLLL *dobj = new DoublyLLL();

    return 0;
}