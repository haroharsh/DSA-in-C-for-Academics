//Deleting the last node of the doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *add_at_end(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
    return head;
}

struct node *add_at_pos(struct node *head, int data, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    int i = 1;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
    }
    temp->next = p->next;
    p->next->prev = temp;
    p->next = temp;
    temp->prev = p;
    return head;
}
struct node* del_last(struct node *head)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 45;
    head->next = NULL;

    head = add_at_end(head, 10);
    head = add_at_pos(head, 20, 2);
    head = del_last(head);
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}