#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;

}NODE,*PNODE,**PPNODE;

int main()
{
    PNODE ptr = NULL;
    
    ptr = (PNODE)malloc(sizeof(NODE));

    //use the node

    free(ptr);

    return 0;
}