#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *del_first(struct node *head)
{
    if(head==NULL)
    {
        printf("\nLinked list is empty");
        return head;
    }
    else
    {
        struct node *temp=head;
        head=head->link;
        free(temp);
    }
    return head;
}
int main(){
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

    // head=del_first(head);
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    return 0;
}