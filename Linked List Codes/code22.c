//creating entire doubly linked list
#include <stdio.h>
#include <stdlib.h>

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
struct node* addToEmpty(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* createList(struct node *head)
{
    int n,data,i;
    printf("Enter the number of nodes: \n");
    scanf("%d",&n);

    if(n==0)
    {
        printf("No nodes to create");
        return head;
    }
    printf("Enter the element for the node 1 : \n");
    scanf("%d",&data);
    head = addToEmpty(head,data);

    for(i=2;i<=n;i++)
    {
        printf("Enter the element for the node %d : \n",i);
        scanf("%d",&data);
        head = add_at_end(head,data);
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    head = createList(head);
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}