#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node *reverse(struct node *head)
{
    struct node *prev=NULL;
    struct node *next=NULL;
    while(head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}

int main(){
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current1=(struct node *)malloc(sizeof(struct node));
    current1->data=98;
    current1->link=NULL;
    head->link=current1;
    
    struct node *current2=(struct node *)malloc(sizeof(struct node));
    current2->data=3;
    current2->link=NULL;
    head->link->link=current2;

    struct node *current3=(struct node *)malloc(sizeof(struct node));
    current3->data=5;
    current3->link=NULL;
    head->link->link->link=current3;
    
    head=reverse(head);
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    return 0;
}
struct node* middle(struct node *head)
{
    struct node *slow=head;
    struct node *fast=head;
    while(fast!=NULL && fast->link!=NULL)
    {
        slow=slow->link;
        fast=fast->link->link;
    }
    return slow;
}