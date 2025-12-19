#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;      // $
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // $

    if(*first == NULL)
    {
        *first = newn;
    }   
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // $

    if(*first == NULL)
    {
        *first = newn;
    }   
    else
    {

    }
}

void InsertAtPos(PPNODE first, int no, int pos)
{}

void DeleteFirst(PPNODE first)
{}

void DeleteLast(PPNODE first)
{}

void DeleteAtPos(PPNODE first, int pos)
{}

void Display(PNODE first)
{
    printf("\nNULL <=> ");
    while(first != NULL)
    {
        printf("| %d | <=> ",first->data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    return 0;
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    
    Display(head);
    
    return 0;
}

