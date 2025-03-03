#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

//Not ptr!=NULL but ptr->link!=NULL

void add_at_end(struct node *head, int info)
{
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=info;
    temp->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    
}

int main() {
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    
    head->data=45;
    head->link=NULL;
    
    struct node *current=(struct node *)malloc(sizeof(struct node));
    
    current->data=95;
    current->link=NULL;
    head->link=current;
    
    current=(struct node *)malloc(sizeof(struct node));
    
    current->data=100;
    current->link=NULL;
    head->link->link=current;
    
    add_at_end(head,96);

    return 0;
}