#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *del_last(struct node *head){
    if(head==NULL)
    {
        printf("\nLinked list is empty");
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp1=head;
        struct node *temp2=head;
        while(temp1->link!=NULL)
        {
            temp2=temp1;
            temp1=temp1->link;
        }
        temp2->link=NULL;
        free(temp1);
        temp1=NULL;
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

    head=del_last(head);
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    return 0;
}