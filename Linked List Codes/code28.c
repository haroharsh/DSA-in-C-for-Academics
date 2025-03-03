//Circular Doubly Linked List
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* circularlySingly(int data)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

int main()
{
    int data = 34;
    struct node *tail;
    tail = circularlySingly(data);
    printf("Data = %d\n", tail->data);
    return 0;
}