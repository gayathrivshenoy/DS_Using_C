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
    struct node *head;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}

void traverse()
{
   struct node *current;
   current=head;
   while(current!= NULL)
   {
       printf("%d",current->data);
       current=current->next;
   }
}

int main() {

    insert_at_beginning(1);
    insert_at_beginning(3);
    insert_at_beginning(5);
    insert_at_beginning(7);
    
    traverse();
   // inside_after_the_key(int key, int data);
    return 0;
}