//implementing stack nusing queue
//We’ll use queue rotation after every push() to make the front of the queue always the top of the stack.
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front, rear, size;
} Queue;

typedef struct {
    Queue q;
} Stack;

void initStack(Stack* s) {
    initQueue(&s->q);
}

void push(Stack* s, int x) {
    enqueue(&s->q, x);
    int n = s->q.size;

    // Rotate the queue to bring the new element to front
    for (int i = 0; i < n - 1; i++) {
        int val = dequeue(&s->q);
        enqueue(&s->q, val);
    }
}

int pop(Stack* s) {
    return dequeue(&s->q);
}

int top(Stack* s) {
    return front(&s->q);
}

int isEmptyStack(Stack* s) {
    return isEmpty(&s->q);
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top: %d\n", top(&s));   // 30
    printf("Pop: %d\n", pop(&s));   // 30
    printf("Top: %d\n", top(&s));   // 20
    printf("Is Empty: %d\n", isEmptyStack(&s)); // 0

    return 0;
}
