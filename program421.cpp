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

        void InsertFirst(int no)
        {}

        void InsertLast(int no)
        {}

        void InsertAtPos(int no, int pos)
        {}

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void DeleteAtPos(int pos)
        {}

        void Display()
        {}

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

    return 0;
}