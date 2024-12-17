#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một node trong ngăn xếp
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Hàm khởi tạo ngăn xếp rỗng
Node *initialize()
{
    return NULL;
}

// Hàm kiểm tra ngăn xếp có rỗng không
int isEmpty(Node *top)
{
    return top == NULL;
}

// Hàm thêm phần tử vào ngăn xếp (push)
void push(Node **top, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Hàm xóa phần tử khỏi ngăn xếp (pop)
int pop(Node **top)
{
    if (isEmpty(*top))
    {
        printf("Ngăn xếp rỗng. Không thể xóa phần tử.\n");
        return -1; // Giá trị mặc định khi không có phần tử
    }
    Node *temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

// Hàm kiểm tra phần tử trên cùng của ngăn xếp (peek)
int peek(Node *top)
{
    if (isEmpty(top))
    {
        printf("Ngăn xếp rỗng. Không có phần tử trên cùng.\n");
        return -1; // Giá trị mặc định khi không có phần tử
    }
    return top->data;
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Node *top)
{
    if (isEmpty(top))
    {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    printf("Các phần tử trong ngăn xếp: ");
    Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Hàm giải phóng bộ nhớ của ngăn xếp
void freeStack(Node **top)
{
    Node *temp;
    while (*top != NULL)
    {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main()
{
    Node *stack = initialize();

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(stack);

    printf("Phần tử trên cùng: %d\n", peek(stack));

    printf("Xóa phần tử: %d\n", pop(&stack));
    display(stack);

    printf("Ngăn xếp có rỗng không? %s\n", isEmpty(stack) ? "Có" : "Không");

    freeStack(&stack);
    return 0;
}
