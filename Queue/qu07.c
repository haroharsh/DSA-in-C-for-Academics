//Queue using stack
//Using single stack

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {
    int arr[SIZE];
    int top;
} Stack;

typedef struct {
    Stack s1, s2;
} Queue;

void initQueue(Queue* q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(Queue* q, int val) {
    push(&q->s1, val);
}

int dequeue(Queue* q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }

    return pop(&q->s2);
}

int front(Queue* q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return peek(&q->s2);
}

int isEmptyQueue(Queue* q) {
    return isEmpty(&q->s1) && isEmpty(&q->s2);
}


int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front: %d\n", front(&q));  // 10
    printf("Dequeue: %d\n", dequeue(&q)); // 10
    printf("Front: %d\n", front(&q));  // 20
    printf("Empty? %d\n", isEmptyQueue(&q)); // 0

    return 0;
}
