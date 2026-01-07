//class with first and last pointer

#include<iostream>
using namespace std;

#pragma pack(1)
class Queuenode
{
    public:
        int data;
        Queuenode *next;

        Queuenode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Queue
{
    private:
        Queuenode *first;
        Queuenode *last;
        int iCount;

    public :
        Queue();

        void enqueue(int);     //InsertLast
        int dequeue();          //DeleteFirst
        void Display();
        int Count();

};

Queue :: Queue()
{
    cout<<"Queue gets created successfully....\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

void Queue :: enqueue(int no)               //insertlast
{
    Queuenode *newn = NULL;

    newn = new Queuenode(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
       this->last->next = newn;       
       this->last = this->last->next;
    }

    this->iCount++;
}

int Queue :: dequeue()          // deletefirst
{
    int Value = 0;
    Queuenode *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty...\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    
    return Value;

}        

void Queue :: Display()
{
    Queuenode *temp = this->first;

    if(this->first == NULL)
    {     
        cout<<"Queue is empty \n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | ";
        temp = temp->next;
    }

    cout<<"\n";
}

int Queue :: Count()
{
    return this->iCount;
}

int main()
{
    Queue *eobj = new Queue();

    eobj->enqueue(11);
    eobj->enqueue(21);
    eobj->enqueue(51);
    eobj->enqueue(101);

    eobj->Display();

    cout<<"Number of elements in Queue are: "<<eobj->Count()<<"\n";

    cout<<"Removed element is : "<<eobj->dequeue()<<"\n";
    
    eobj->Display();

    cout<<"Number of elements in Queue are: "<<eobj->Count()<<"\n";
    
    cout<<"Removed element is : "<<eobj->dequeue()<<"\n";
    
    eobj->Display();

    cout<<"Number of elements in Queue are: "<<eobj->Count()<<"\n";

    eobj->enqueue(121);
    
    eobj->Display();

    cout<<"Number of elements in Queue are: "<<eobj->Count()<<"\n";

    delete eobj;

    return 0;
}