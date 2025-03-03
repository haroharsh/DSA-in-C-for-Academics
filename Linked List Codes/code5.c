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
        printf("%d",count);
    
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
            printf("\n%d",ptr->data);
            ptr=ptr->link;
        }
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
    return 0;
}