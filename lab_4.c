#include <stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insert_at_begining(int data)
{
    struct Node *new_Node = NULL;
    new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data=data;
    new_Node->next=head;
    head=new_Node;
}

void traverse ()
{
    struct Node *curr=head;
    while(curr!=NULL)
    {
        printf("%d\n",curr->data);
        curr=curr->next;
    }
}
void insert_at_end(int data)
{
    struct Node *curr;
    curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    struct Node *new_Node = NULL;
    new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data=data;
    curr->next=new_Node;
    new_Node->next=NULL;
    
}

    

    
    int main()
{
    insert_at_begining(1);
    insert_at_begining(7);
    insert_at_begining(5);
    insert_at_begining(3);
    insert_at_end(10);
    traverse();
    return 0;
}