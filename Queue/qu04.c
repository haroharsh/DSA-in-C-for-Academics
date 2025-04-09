//better approach
#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front, rear, size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int x) {
    if (q->size == SIZE) return; // overflow
    q->arr[++q->rear] = x;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int val = q->arr[q->front++];
    q->size--;
    return val;
}

int front(Queue* q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->front];
}
