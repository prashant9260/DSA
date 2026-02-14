#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Insert(PPNODE first, int No)
{

}

int main()
{
    PNODE head = NULL;

    Insert(&head, 21);
    Insert(&head, 11);
    Insert(&head, 51);

    return 0;
}