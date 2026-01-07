///////////////////////////////////////////////////////////////
//          Generallised Strucure Librey
///////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------------
Type                    Name of class for node                  Name of class for Functinality
-------------------------------------------------------------------------------------------------
Singly Linear           SinglyLLLnode                           SinglyLLL           Done
Singly Circular         SinglyCLLnode                           SinglyCLL
Doubly Linear           DoublyLLLnode                           DoublyLLL           Done
Doubly Circular         DoublyCLLnode                           DoublyCLL
Stack                   Stacknode                               Stack               Done
Queue                   Queuenode                               Queue               Done
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

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             Nothing
//  Description:        Used to insert node at first position
//  Author:             Prashant Raosaheb Todmal
//  Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////
//          Stack using Generic Approch
//////////////////////////////////////////////////////////////

template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public :
        Stack();

        void push(T);     
        T pop();          
        T peep();
        void Display();
        int Count();

};

template <class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created successfully....\n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty...\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    
    return Value;
}  

template <class T>      
T Stack<T> :: peep()
{    
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty...\n";
        return -1;
    }

    Value = this->first->data;
    
    return Value;
}

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty \n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|"<<"\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////
//          Queue using Generic Approch
//////////////////////////////////////////////////////////////

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

//////////////////////////////////////////// End of Library //////////////////////////////////////////////////

int main()
{    
    SinglyLLL<int> *obj1 = new SinglyLLL<int>();
    int iRet = 0;
    
    obj1->InsertFirst(51);
    obj1->InsertFirst(21);
    obj1->InsertFirst(11);
    
    obj1->Display();
    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";     
    
    obj1->InsertLast(101);
    obj1->InsertLast(111);
    obj1->InsertLast(121);  
    
    obj1->Display();
    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj1->DeleteFirst();

    obj1->Display();

    
    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj1->DeleteLast();

    obj1->Display();
    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";


    obj1->InsertAtPos(105,4);

    obj1->Display();
    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj1->DeleteAtPos(4);

    obj1->Display();
    iRet = obj1->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n"; 
    
    delete obj1;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    DoulyLLL<char> *dobj = new DoulyLLL<char>();
    
    dobj-> InsertFirst('A');
    dobj-> InsertFirst('B');
    dobj-> InsertFirst('C');

    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj-> InsertLast('X');
    dobj-> InsertLast('Y');
    dobj-> InsertLast('Z');

    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);
    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    delete dobj;

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

    Stack<char> *sobj = new Stack<char>();

    sobj->push('A');
    sobj->push('B');
    sobj->push('C');
    sobj->push('D');

    sobj->Display();

    cout<<"Number of elements in Stack are: "<<sobj->Count()<<"\n";

    cout<<"Return value of peep is : "<<sobj->peep()<<"\n";
    
    sobj->Display();

    cout<<"Number of elements in Stack are: "<<sobj->Count()<<"\n";

    cout<<"Poped element is : "<<sobj->pop()<<"\n";
    
    sobj->Display();

    cout<<"Number of elements in Stack are: "<<sobj->Count()<<"\n";
    
    cout<<"Poped element is : "<<sobj->pop()<<"\n";
    
    sobj->Display();

    cout<<"Number of elements in Stack are: "<<sobj->Count()<<"\n";

    sobj->push('E');
    
    sobj->Display();

    cout<<"Number of elements in Stack are: "<<sobj->Count()<<"\n";

    delete sobj;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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