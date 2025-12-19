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

//call by value

void Display(PNODE first)
{}

int Count(PNODE first)
{
    return 0;
}

int main()
{
    PNODE head = NULL;

    Display(head);

    Count(head);

    return 0;
}