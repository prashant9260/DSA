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
    PNODE temp = NULL;

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
        temp = *first;

        while(temp -> next != NULL)     // Type 2
        {
            temp = temp -> next;
        }

        temp->next = newn;
        newn->prev = temp;          // $    temp->next->prev = temp;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first) -> next;
        free(temp);
        (*first) -> prev = NULL;            // $
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp ->next -> next != NULL)      // Type 3
        {
            temp = temp -> next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

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
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }

    return iCount;
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iSize = 0;
    int iCnt = 0;
    iSize = Count(*first);

    PNODE newn = NULL;
    PNODE temp = NULL;
    
    if((pos < 1) || (pos > iSize+1))
    {
        printf("Invalid position \n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++ )
        {
            temp = temp -> next;
        }

        newn->next = temp->next;    //1
        temp->next->prev = newn;    //2 $
        temp->next = newn;          //3
        newn->prev = temp;          //4 $
    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    iSize = Count(*first);

    PNODE temp = NULL;
    
    if((pos < 1) || (pos > iSize))
    {
        printf("Invalid position \n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {        
        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++ )
        {
            temp = temp -> next;
        }        

    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    
    Display(head);
    
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);
    
    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);
    
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);
    
    Display(head);
    
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);
    
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&head,105,3);
    
    Display(head);
    
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&head,5);
    
    Display(head);
    
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    return 0;
}
