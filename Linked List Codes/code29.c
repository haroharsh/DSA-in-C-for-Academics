//Insert at begining of a circular singly linked list   
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *add_to_empty(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct node *add_at_beginning(struct node *tail, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
    return tail;
}
void print(struct node *tail)
{
    struct node *p = tail->next;
    do
    {
        printf("Element: %d\n", p->data);
        p = p->next;
    } while (p != tail->next);
}
int main()
{
    struct node *tail = add_to_empty(45);
    tail = add_at_beginning(tail, 34);
    tail = add_at_beginning(tail, 23);
    tail = add_at_beginning(tail, 12);
    print(tail);
    return 0;
}
