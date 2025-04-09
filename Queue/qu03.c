// C program for insertion and deletion 
// in Circular Queue
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};


struct Node* createNode(int newdata);

// Function to insert element in a Circular queue
void enQueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);

    if (q->front == NULL)
        q->front = newNode;
    else
        q->rear->next = newNode;

    q->rear = newNode;
    q->rear->next = q->front;
}

// Function to delete element from Circular Queue
int deQueue(struct Queue* q) {

    // if queue is empty
    if (q->front == NULL) {
        return -1;
    }

    int value;

    // If this is the last node to be deleted
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }

    return value;
}

void printQueue(struct Queue* q) {
    if (q->front == NULL) return;

    struct Node* curr = q->front;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != q->front);
    printf("\n");
}

// Function to return the front value
int front(struct Queue* q) {
	struct Node* front = q->front;

	if (front == NULL) {
		return -1;
	}
	
	return front->data;
}

// Function to return the rear value
int rear(struct Queue* q) {
	struct Node* rear = q->rear;

	if (rear == NULL) {
		return -1;
	}

	return rear->data;
}

struct Queue* createQueue() {
    struct Queue* q = 
    (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

struct Node* createNode(int newdata) {
    struct Node* newnode
        = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}

int main() {
    struct Queue* q = createQueue();

    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);
    enQueue(q, 20);
    
    printf("Front value: %d\n", front(q)); 
    printf("Rear value: %d\n", rear(q));

    printQueue(q);

    printf("Deleted value = %d\n", deQueue(q));
    printf("Deleted value = %d\n", deQueue(q));

    printQueue(q);

    return 0;
}
