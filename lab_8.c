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

void insert_at_end(int data)
{
    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    struct node *curr=head;
    if(head==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
        newnode->next=NULL;
    }
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    
    curr->next=newnode;
    newnode->prev=curr;
    newnode->next= NULL;

}

void insert_after_key(int key, int data)
{
    struct node *curr=head;
    
    while(curr!=NULL && curr->data!=key)
    {
        curr=curr->next;
    }
    
    if(curr==NULL)
    {
        printf("Key not Found");
    }
    
    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    
    newnode->next=NULL;
    newnode->prev=NULL;
    
    if(curr->next==NULL)
    {
        curr->next=newnode;
        newnode->prev=curr;
    }
    else
    {
        newnode->next=curr->next;
        newnode->prev=curr;
        curr->next->prev=newnode;
        curr->next=newnode;
    }
}

void delete_from_beginning()
{
    struct node *curr=head;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    
    head=head->next;
    
    if(head!=NULL)
    {
        head->prev=NULL;
    }
    free(curr);
    curr=NULL;
}

void delete_given_data(int key)
{
    struct node *curr=head;
    
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    
    if(curr->data==key)
    {
        head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        free(curr);
        curr=NULL;
        return;
    }
    
    while(curr!=NULL && curr->data!=key)
    {
        curr=curr->next;
    }
    
    if(curr->next!= NULL)
    {
        curr->next->prev=curr->prev;
    }
    
    if(curr->prev!=NULL)
    {
        curr->prev->next=curr->next;
    }
    free(curr);
}

void delete_at_end()
{
    struct node *curr=head;
    if(head==NULL)
    {
        printf("List doesnt exist");
    }
    
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    
    while(curr->next != NULL)
    {
        curr=curr->next;
    }
    
    curr->prev->next=NULL;
    free(curr);
    curr=NULL;
    
}

int main() {
    
      insert_at_beginning(3);
      insert_at_beginning(2);
      insert_at_beginning(1);
      insert_at_end(5);
      insert_after_key(3,4);
      delete_from_beginning();
      delete_given_data(5);
      delete_at_end();
      traverse();
    
}