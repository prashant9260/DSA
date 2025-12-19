#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Call by value

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("%d\t",first->data);
        first = first -> next;
    }
    printf("\n");
}

int Count(PNODE first)
{
    return 0;
}

// Call by address

void InsertFirst(PPNODE first, int no)
{}

void InsertLast(PPNODE first, int no)
{}

void InsertAtPos(PPNODE first, int no, int pos)
{}

void DeleteFirst(PPNODE first)
{}

void DeleteLast(PPNODE first)
{}

void DeleteAtPos(PPNODE first, int pos)
{}

int main()
{
    PNODE head = NULL;

    Display(head);
    Count(head);
    
    InsertFirst(&head,11);
    InsertLast(&head,21);
    InsertAtPos(&head,51,5);
    
    DeleteFirst(&head);
    DeleteLast(&head);
    DeleteAtPos(&head,5);
    
    return 0;
}