#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Insert(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)      //if tree is empty 
    {
        *first = newn;
    }
    else                    //if contains at least one 
    {
        temp = *first;

        while(1)
        {
            if(no > temp->data)        //if element is greater 
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)    ////if element is smaller
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild; 
            }
            else if(no == temp->data)
            {   
                printf("Unable to insert dublicate element\n");
                free(newn);
                break;
            }            
        }
    }
}

//L  D  R
void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\n",first->data);
        Inorder(first->rchild);
    }
}

//D   L   R
void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\n",first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

//L    R    D
void PostOrder(PNODE first)
{
    if(first != NULL)
    {
        PostOrder(first->lchild);
        PostOrder(first->rchild);
        printf("%d\n",first->data);
    }
}

bool Serach(PNODE first, int no)
{
    bool bFlag = false;
    
    while(first != NULL)
    {
        if(no > first->data)
        {
            first = first->rchild;
        }
        else if(no < first->data)
        {
            first = first->lchild;
        }
        else if(no == first->data)
        {
            bFlag = true;
            break;
        }
    }
}

int Count(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        iCount++;
        Count(first->lchild);
        Count(first->rchild);
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    bool bRet = false;
    int iRet = 0;

    Insert(&head, 21);
    Insert(&head, 11);
    Insert(&head, 51);
    Insert(&head, 67);
    Insert(&head, 40);
    Insert(&head, 10);
    Insert(&head, 13);
    Insert(&head, 38);
    
    printf("Inorder traversal \n");
    Inorder(head);

    bRet = Serach(head,47);

    if(bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("there is no such element\n");
    }

    iRet = Count(head);

    printf("Number of elements are : %d\n",iRet);

    return 0;
}