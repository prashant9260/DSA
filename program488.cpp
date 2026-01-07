///////////////////////////////////////////////////////////////
//          Generallised Strucure Librey
///////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------------
Type                    Name of class for node                  Name of class for Functinality
-------------------------------------------------------------------------------------------------
Singly Linear           SinglyLLLnode                           SinglyLLL
Singly Circular         SinglyCLLnode                           SinglyCLL
Doubly Linear           DoublyLLLnode                           DoublyLLL
Doubly Circular         DoublyCLLnode                           DoublyCLLnode
-------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////
//          Singly Linked List using Generic Approch
//////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public :
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }   
};

template<class T>
class SinglyLLL
{
    private :
        SinglyLLLnode<T> * first;
        int iCount;
        
    public :    
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
          
        void DeleteFirst();
        void DeleteLast();
        void Display();
       
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);           
};

template<class T>
SinglyLLL<T> ::SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    newn = new SinglyLLLnode<T>(no);
    
    newn->next = this->first;         
    this->first = newn;

    this->iCount++;                     
}

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T>* temp = NULL;
    SinglyLLLnode<T>* newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)   
    {
        first = newn;
        
    }
    else                
    {
        temp = this->first ;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this->iCount++;
}

template<class T>     
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;
    if(first == NULL)
    {
        return;
    }
    else if(this->first -> next == NULL)         
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first -> next;
        delete temp;
    }
    this->iCount--;
}

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first -> next == NULL)         
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first ;

        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp-> next;
        temp-> next = NULL;
    }
    this->iCount--;
}

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;
    temp = this->first;
    
    for(iCnt = 1; iCnt <= iCount ;iCnt++)         
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }
    
    cout<<"NULL\n";
}

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}


template<class T>
void SinglyLLL<T> :: InsertAtPos(T  no, int pos)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;
    
    if((pos < 1) || (pos > this->iCount+1))   
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);
        
        temp  = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }
        newn->next = temp->next;
        temp->next = newn;
        
        this->iCount++;
    }
}

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;                           
    int iCnt = 0;
    
    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }
        
        target = temp->next;
        
        temp->next = target->next;
        delete target;
        
        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////
//        Doubly Linear Linked List using Generic Approch
//////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public :
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoulyLLL
{
    private :
        DoublyLLLnode<T> *first;
        int iCount;

    public:

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
    DoublyLLLnode<T> * newn = NULL;
    newn = new DoublyLLLnode<T>(no);

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
    DoublyLLLnode<T> * newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

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
    DoublyLLLnode<T> * temp = NULL;
    DoublyLLLnode<T> *newn = NULL;
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
        newn = new DoublyLLLnode<T>(no);
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
    DoublyLLLnode<T> *temp = NULL;
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
    DoublyLLLnode<T> * temp = NULL;
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
    DoublyLLLnode<T> * temp = NULL;
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

//////////////////////////////////////////// End of Library //////////////////////////////////////////////////

int main()
{


    return 0;
}