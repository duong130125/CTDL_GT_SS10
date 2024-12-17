#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Định nghĩa cấu trúc hàng đợi
typedef struct Queue
{
    Node *front; // Phần tử đầu hàng đợi
    Node *rear;  // Phần tử cuối hàng đợi
} Queue;

// Hàm khởi tạo hàng đợi
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Hàm thêm phần tử vào hàng đợi (enqueue)
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    { // Nếu hàng đợi rỗng
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode; // Nối nút mới vào cuối hàng đợi
        q->rear = newNode;       // Cập nhật phần tử cuối
    }
    printf("Enqueued: %d\n", value);
}

// Hàm xóa phần tử khỏi hàng đợi (dequeue)
int dequeue(Queue *q)
{
    if (q->front == NULL)
    { // Hàng đợi rỗng
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    { // Nếu hàng đợi trở nên rỗng sau khi xóa
        q->rear = NULL;
    }

    free(temp);
    printf("Dequeued: %d\n", value);
    return value;
}

// Hàm kiểm tra phần tử đầu hàng đợi (peek)
int peek(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty. No element to peek.\n");
        return -1;
    }
    return q->front->data;
}

// Hàm kiểm tra hàng đợi có rỗng không
bool isEmpty(Queue *q)
{
    return q->front == NULL;
}

// Hàm giải phóng bộ nhớ của hàng đợi
void freeQueue(Queue *q)
{
    while (!isEmpty(q))
    {
        dequeue(q);
    }
    free(q);
}

// Hàm chính để kiểm tra các chức năng
int main()
{
    Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Peek: %d\n", peek(q));

    dequeue(q);
    dequeue(q);

    printf("Peek after dequeues: %d\n", peek(q));

    printf("Is queue empty? %s\n", isEmpty(q) ? "Yes" : "No");

    dequeue(q);

    printf("Is queue empty after all dequeues? %s\n", isEmpty(q) ? "Yes" : "No");

    freeQueue(q);

    return 0;
}
