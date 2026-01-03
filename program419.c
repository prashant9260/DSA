#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first) == NULL && (*last) == NULL)     //LL is empty 
    {
        *first = newn;
        *last = newn;
    }
    else                                    // LL contains one or more
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first) == NULL && (*last) == NULL)     //LL is empty 
    {
        *first = newn;
        *last = newn;
    }
    else                                    // LL contains one or more
    {
        (*last)->next = newn;
        newn-> prev = *last;
        *last = newn;
    }
    (*last)->next = *first;
    (*first)->prev = *last;
}

void DeleteFirst(PPNODE first, PPNODE last)
{
if((*first) == NULL && (*last) == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{    
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
       *last = (*last)->prev;
       free((*last)->next);

       (*last)->next = *first;
       (*first)->prev = *last;
    }
}

void Display(PNODE first, PNODE last)
{
    // Important
    if(first == NULL && last == NULL)       //LL is empty
    {
        printf("Linked List is empty \n");
        return;
    }

    printf("<=>");

    do
    {
        printf("| %d | <=>",first->data);
        first = first->next;
    }while(first != last->next);

    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;
    
    if(first == NULL && last == NULL)       //LL is empty
    {
        return 0;
    }

    do
    {
        iCount++;
        first = first->next;
    }while(first != last->next);
    
    return iCount;
}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{    
    int iCount = 0, i = 0;
    PNODE temp = NULL;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount)
    {
        printf("Invalid position \n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {   
        temp = *first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;

    }
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    int iCount = 0, i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount+1)
    {
        printf("Invalid position \n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,last,no);
    }
    else
    {   
        temp = *first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    Display(head,tail);
    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);
    
    Display(head,tail);
    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head,&tail);
    DeleteLast(&head,&tail);
    
    Display(head,tail);
    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&head,&tail,105,3);
    
    Display(head,tail);
    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&head,&tail,3);
    
    Display(head,tail);
    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    return 0;
}