//Reversing of a doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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

struct node* reverse(struct node *head)
{
    struct node* ptr1 = head;
    struct node* ptr2 = head->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 45;
    head->next = NULL;

    head = add_at_end(head, 10);
    head = add_at_end(head, 20);
    head = add_at_end(head, 30);
    head = add_at_end(head, 40);

    head = reverse(head);
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}