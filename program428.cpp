#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SignlyLL
{
    public:
        PNODE first;
        int iCount;

        SignlyLL()
        {
            cout<<"Object of singlyLL gets created.\n";
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)            //UPdate
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            newn->next =first;
            first = newn;
            
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(iCount == 0)     //Updated
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)    //else if(icount == 1)
            {
               delete first;
               first = NULL;
            }
            else
            {
                temp = first;

                first = first->next;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)    //else if(icount == 1)
            {
               delete(first);
               first = NULL;
            }
            else
            {
                temp = first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                
                delete temp->next;
                temp->next = NULL;

            }
            iCount--;
        }

        void Display()      //Updated
        {
            PNODE temp = NULL;
            int iCnt = 0;

            temp = first;
            
            for(iCnt = 1; iCnt <= iCount; iCnt++)
            {
                cout<<"| "<<temp->data<<" |->";
                temp = temp->next;
            }

            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }
        
        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
        
            int iCnt = 0;

            if(pos < 1 || pos > iCount+1)          
            {
                cout<<"Invalid position \n";
                return;
            }
            
            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;

                temp = first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }

        }
        
        void DeleteAtPos(int pos)
        {
            
            PNODE temp = NULL;
            PNODE target = NULL;

            int iCnt = 0;

            if(pos < 1 || pos > iCount)          
            {
                cout<<"Invalid position \n";
                return;
            }
            
            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                target = temp->next;

                temp->next = target->next;
                delete target;

                iCount--;
            }
        }
};

int main()
{
    SignlyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}
