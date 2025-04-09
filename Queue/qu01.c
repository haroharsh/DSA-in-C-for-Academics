#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->arr = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front > queue->rear;
}

void enqueue(struct Queue* queue, int x) {
    if (queue->rear < queue->capacity - 1) {
        queue->arr[++queue->rear] = x;
    }
}

void dequeue(struct Queue* queue) {
    if (!isEmpty(queue)) {
        queue->front++;
    }
}

int getFront(struct Queue* queue) {
    return isEmpty(queue) ? -1 : queue->arr[queue->front];
}

void display(struct Queue* queue) {
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQueue(100);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d\n", getFront(q));
    dequeue(q);
    enqueue(q, 4);
    display(q);
    return 0;
}
