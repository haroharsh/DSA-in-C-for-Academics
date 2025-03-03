#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void add_begin(struct node **head, int info)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = info;
    ptr->link = *head;
    *head = ptr;
}

void add_at_pos(struct node **head, int info, int pos)
{
    struct node *ptr1 = *head; // FIX: Correctly referencing the head
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = info;
    ptr2->link = NULL;

    if (pos == 1) // Special case: insert at beginning
    {
        ptr2->link = *head;
        *head = ptr2;
        return;
    }

    pos--;
    while (pos != 1 && ptr1->link != NULL)
    {
        ptr1 = ptr1->link;
        pos--;
    }

    ptr2->link = ptr1->link;
    ptr1->link = ptr2;
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));

    current->data = 95;
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));

    current->data = 100;
    current->link = NULL;
    head->link->link = current;

    add_begin(&head, 96);
    add_at_pos(&head, 99, 3);

    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    return 0;
}
