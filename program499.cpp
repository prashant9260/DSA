//////////////////////////////////////////////////////////////////
//      Final code of Queue using Generic Approch
//////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T>*next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public :
        Queue();

        void enqueue(T);     
        T dequeue();          
        void Display();
        int Count();

};

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created successfully....\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void Queue<T> :: enqueue(T no)               //insertlast
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

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

template<class T>
T Queue<T> :: dequeue()          // deletefirst
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

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

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

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

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

int main()
{
    Queue<double> *eobj = new Queue<double>();

    eobj->enqueue(11.51556);
    eobj->enqueue(21.4584);
    eobj->enqueue(51.4587);
    eobj->enqueue(101.4584);

    eobj->Display();

    cout<<"Number of elements in Queue are: "<<eobj->Count()<<"\n";

    cout<<"Removed element is : "<<eobj->dequeue()<<"\n";
    
    eobj->Display();

    cout<<"Number of elements in Queue are: "<<eobj->Count()<<"\n";
    
    cout<<"Removed element is : "<<eobj->dequeue()<<"\n";
    
    eobj->Display();

    cout<<"Number of elements in Queue are: "<<eobj->Count()<<"\n";

    eobj->enqueue(121.4875);
    
    eobj->Display();

    cout<<"Number of elements in Queue are: "<<eobj->Count()<<"\n";

    delete eobj;

    return 0;
}