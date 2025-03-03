#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void count_of_nodes(struct node *head)
{
    int count=0;
    if(head==NULL)
    {
        printf("\nLinked list is empty");
    }
        struct node *ptr=NULL;
        ptr=head;
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->link;
        }
        printf("%d\n",count);
    
}
void print_data(struct node *head)
{
    if(head==NULL)
    {
        printf("\nLinked list is empty");
    }
    struct node *ptr=NULL;
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
}
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
    
    count_of_nodes(head);
    print_data(head);
    add_at_end(head,96);
    print_data(head);
    return 0;
}