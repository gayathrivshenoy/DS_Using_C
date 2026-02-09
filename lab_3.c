// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;  

void insert_at_beginning(int data)
{
    struct node *newNode=NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}

void traverse()
{
   struct node *current;
   current=head;
   while(current != NULL)
   {
       printf("%d\n",current->data);
       current=current->next;
   }
}

void insert_after_the_key(int key, int data)
{
   struct node *curr= head;
   while(curr != NULL && curr->data != key)
   {
       curr=curr->next;
   }
   struct node *NewNode= (struct node *)malloc(sizeof(struct node));
   NewNode ->data=data;
   NewNode->next=curr->next;
   curr->next= NewNode;
}

int main() {

    insert_at_beginning(1);
    insert_at_beginning(7);
    insert_at_beginning(5);
    insert_at_beginning(3);
    
   insert_after_the_key(7,10);
   traverse();
    return 0;
}