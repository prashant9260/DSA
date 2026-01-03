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

            if(first == NULL)
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

        void InsertAtPos(int no, int pos)
        {}

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void DeleteAtPos(int pos)
        {}

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

    return 0;
}
