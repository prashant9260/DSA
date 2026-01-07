// Doubly Linear(Generic)
#include<iostream>
using namespace std;

#pragma pack(1)
template <class T>
class node
{
    public :
        T data;
        node *next;
        node *prev;

        node(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoulyLLL
{
    public :
        node<T> *first;
        int iCount;

        DoulyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoulyLLL<T> :: DoulyLLL()  // constructor
{
   cout<<"Link list gets created \n";

   this->first = NULL;
   this->iCount = 0;
}

template <class T>
void DoulyLLL<T> ::  InsertFirst(T no)
{
    node<T> * newn = NULL;
    newn = new node<T>(no);

    if(this->first == NULL)
    {
       this ->first = newn;
    }
    else
    {
        newn -> next = this-> first;
        this->first->prev= newn;
        this->first =newn;
    }

    this->iCount++;
}

template <class T>
void DoulyLLL<T> :: InsertLast(T no)
{
    node<T> * newn = NULL;
    node<T> *temp = NULL;

    newn = new node<T>(no);

    if(this->first == NULL)
    {
        this ->first = newn;
    }
    else
    {
        temp = this -> first;

        while(temp-> next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
        newn -> prev = temp;
    }

    this->iCount++;
}

template <class T>
void DoulyLLL<T> :: InsertAtPos(T no,int pos)
{
    node<T> * temp = NULL;
    node<T> *newn = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid \n";
        return ;
    }
    if(pos == 1)
    {
       this-> InsertFirst(no);
    }
    else if(pos == this ->iCount+1)
    {
        this-> InsertLast(no);
    }
    else
    {
        newn = new node<T>(no);
        temp = this-> first;

        for(iCnt = 1;iCnt <pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn ->next = temp->next;
        temp->next->prev= newn;
        temp->next=newn;
        newn->prev =temp;

        this->iCount++;
    }
}

template <class T>
void DoulyLLL<T> ::  DeleteFirst()
{
    if(this->first == NULL)              //LL IS emepty
    {
        return;
    }
    else if(this->first->next == NULL)   // LL contain one node
    {
        delete this-> first;
        this->first = NULL;
    }
    else                                 // LL contain more than one node 
    {
        this->first = this->first-> next;
        delete this-> first -> prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

template <class T>
void DoulyLLL<T> ::DeleteLast()
{
    node<T> *temp = NULL;
    if(this->first == NULL)              //LL IS emepty
    {
        return;
    }
    else if(this->first->next == NULL)   // LL contain one node
    {
        delete this-> first;
        this->first = NULL;
    }
    else                                 // LL contain more than one node 
    {
        temp = this-> first;
        while (temp->next->next!= NULL)
        {
            temp= temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

template <class T>
void DoulyLLL<T> :: DeleteAtPos(int pos) 
{
    node<T> * temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid \n";
        return ;
    }
    if(pos == 1)
    {
       this-> DeleteFirst();
    }
    else if(pos == this ->iCount)
    {
        this-> DeleteLast();
    }
    else
    {
        temp = this-> first;

        for(iCnt = 1;iCnt <pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next =temp->next->next;
        delete temp->next->prev;
        temp->next->prev =temp;


        this->iCount--;
    }
}

template <class T>
void DoulyLLL<T> :: Display()
{
    node<T> * temp = NULL;
    temp = this-> first;

    cout<<"\nNULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp-> data<<" |<=> ";
        temp = temp ->next; 
    }
    cout<<"NULL\n";
}

template <class T>
int DoulyLLL<T> :: Count()
{
    return this->iCount;
}

int main()
{
    DoulyLLL<int> *dobj = new DoulyLLL<int>();
    
    dobj-> InsertFirst(51);
    dobj-> InsertFirst(21);
    dobj-> InsertFirst(11);

    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj-> InsertLast(101);
    dobj-> InsertLast(111);
    dobj-> InsertLast(121);

    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->InsertAtPos(105,4);
    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    delete dobj;
    return 0;
}