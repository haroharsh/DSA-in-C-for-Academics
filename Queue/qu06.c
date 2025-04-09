//Queue using stack
//Using single stack

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front, rear, size;
} Queue;

typedef struct {
    int arr[SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int val) {
    if (s->top < SIZE - 1)
        s->arr[++(s->top)] = val;
}

int pop(Stack* s) {
    if (!isEmpty(s))
        return s->arr[(s->top)--];
    return -1;
}

int peek(Stack* s) {
    if (!isEmpty(s))
        return s->arr[s->top];
    return -1;
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
