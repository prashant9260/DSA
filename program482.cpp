// Doubly Linear
#include<iostream>
using namespace std;

#pragma pack(1)
class node
{
    public :
        int data;
        node *next;
        node *prev;

        node(int no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

class DoulyLLL
{
    public :
        node *first;
        int iCount;

        DoulyLLL();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

DoulyLLL :: DoulyLLL()
{
   cout<<"Link list gets created \n";

   this->first = NULL;
   this->iCount = 0;
}
void DoulyLLL ::  InsertFirst(int no)
{
    node * newn = NULL;
    newn = new node(no);

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
void DoulyLLL :: InsertLast(int no)
{
    node * newn = NULL;
    node *temp = NULL;

    newn = new node(no);

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
void DoulyLLL :: InsertAtPos(int no,int pos)
{
    node * temp = NULL;
    node *newn = NULL;
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
        newn = new node(no);
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

void DoulyLLL ::  DeleteFirst()
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
void DoulyLLL ::DeleteLast()
{
    node *temp = NULL;
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
void DoulyLLL :: DeleteAtPos(int pos) 
{
    node * temp = NULL;
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

void DoulyLLL :: Display()
{
    node * temp = NULL;
    temp = this-> first;

    cout<<"\nNULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp-> data<<" |<=> ";
        temp = temp ->next; 
    }
    cout<<"NULL\n";
}
int DoulyLLL :: Count()
{
    return this->iCount;
}

int main()
{
    DoulyLLL *dobj = new DoulyLLL();
    
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