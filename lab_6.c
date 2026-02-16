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


void delete_given_data(int data)
{
    struct Node *curr=head;
    struct Node *prev=NULL;
    if(head==NULL)
    {
        printf("List does not exist");
    }
    
     if(curr->data==data)
    {
        head=curr->next;
        free(curr);
        curr=NULL;
    }
    
    while(curr!= NULL && curr->data!=data)
    {
        prev=curr;
        curr=curr->next;
      
    }
    
     if(curr==NULL)
        {
            printf("It doesnt exist\n");
            return;
        }
    
    prev->next=curr->next;
    free(curr);
    curr=NULL;
}

void delete_from_end()
{
     struct Node *curr=head;
    if(head==NULL)
    {
        printf("List does not exist");
    }

    
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    free(curr->next);
    curr->next=NULL;
    
    if(curr==NULL)
        {
            printf("It doesnt exist\n");
            return;
        }
        
    if(head->next == NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    
}
    
    int main()
{
    insert_at_begining(1);
   insert_at_begining(7);
   insert_at_begining(5);
   insert_at_begining(3);

    delete_given_data(1);
   delete_from_end();
    traverse();
    return 0;
}