#include<iostream>
using namespace std;

#pragma pack(1)
class Stacknode
{
    public:
        int data;
        Stacknode *next;

        Stacknode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Stack
{
    private:
        Stacknode *first;
        int iCount;

    public :
        Stack();

        void push(int);     //InsertFirst()
        int pop();          //DeleteFirst()
        int peep();
        void Display();
        int Count();

};

Stack :: Stack()
{
    
}

Stack :: void push(int no)
{

}

Stack :: int pop()
{
    return 0;
}        
Stack :: int peep()
{
    return 0;
}

Stack :: void Display()
{

}

Stack :: int Count()
{
    return this->iCount;
}

int main()
{
    Stack *sobj = new Stack();

    
    delete sobj;

    return 0;
}