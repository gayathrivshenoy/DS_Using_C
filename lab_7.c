// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;

void insert_at_beginning(int data)
{
    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    if(head==NULL)
    {
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    
}

void traverse()
{
    struct node *curr=head;
    
    if(head==NULL)
    {
        printf("List doesnt exist");
        return;
    }
    printf("Forward:\n ");
    while(curr->next!=NULL)
    {
        printf("%d ", curr->data);
        curr=curr->next;
    }
    
    printf("%d", curr->data);
    printf("\nBackward:\n ");
   
    while(curr!=NULL)
    {
        printf("%d ", curr->data);
        curr=curr->prev;
    }
    
}


int main() {

    insert_at_beginning(1);
     insert_at_beginning(3);
      insert_at_beginning(5);
      
      traverse();
    
}