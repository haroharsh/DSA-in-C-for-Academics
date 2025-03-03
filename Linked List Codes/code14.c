#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void del_at_pos(struct node **head, int pos)
{
    struct node *current = *head;
    struct node *prev = *head;
    if(*head==NULL)
    {
        printf("\nLinked list is empty");
    }
    else if(pos==1)
    {
        *head=(*head)->link;
        free(current);
        current=NULL;
    }
    else
    {
        while (pos!=1)
        {
            prev=current;
            current=current->link;
            pos--;
        }
        prev->link=current->link;
        free(current);
        current=NULL;
    }
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

    del_at_pos(&head,2);
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    return 0;
}