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
//You are given the head of a linked list.

//Remove every node which has a node with a greater value anywhere to the right side of it.

//Return the head of the modified linked list.
void remove nodes(struct node **head)
{
    struct node *current=*head;
    struct node *prev=*head;
    struct node *temp=*head;
    while(current!=NULL)
    {
        temp=current;
        while(temp->link!=NULL)
        {
            if(temp->link->data>current->data)
            {
                if(temp==*head)
                {
                    *head=(*head)->link;
                    free(temp);
                    temp=*head;
                }
                else
                {
                    prev->link=temp->link;
                    free(temp);
                    temp=prev->link;
                }
            }
            else
            {
                prev=temp;
                temp=temp->link;
            }
        }
        current=current->link;
    }
}