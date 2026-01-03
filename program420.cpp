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

};

int main()
{
    SignlyLL obj1;
    SignlyLL obj2;

    return 0;
}