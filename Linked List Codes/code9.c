#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void add_begin(struct node **head, int info)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=info;
    ptr->link=*head;
    *head=ptr;

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
    
    add_begin(&head,96);
    

    return 0;
}