#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Định nghĩa cấu trúc của một node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Hàm khởi tạo danh sách rỗng
Node *initialize()
{
    return NULL;
}

// Hàm tạo một node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phần tử vào đầu danh sách
void addFirst(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Hàm thêm phần tử vào cuối danh sách
void addLast(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Hàm xóa phần tử đầu danh sách
void deleteFirst(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng, không thể xóa.\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Hàm xóa phần tử cuối danh sách
void deleteLast(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng, không thể xóa.\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Hàm tìm kiếm phần tử trong danh sách
bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hàm hiển thị các phần tử trong danh sách
void display(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách rỗng.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Hàm giải phóng bộ nhớ của danh sách
void freeList(Node **head)
{
    Node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    Node *list = initialize();

    printf("Thêm các phần tử vào danh sách:\n");
    addFirst(&list, 10);
    addLast(&list, 20);
    addFirst(&list, 5);
    addLast(&list, 30);
    display(list);

    printf("\nXóa phần tử đầu:\n");
    deleteFirst(&list);
    display(list);

    printf("\nXóa phần tử cuối:\n");
    deleteLast(&list);
    display(list);

    printf("\nTìm kiếm phần tử 20: ");
    if (search(list, 20))
    {
        printf("Tìm thấy.\n");
    }
    else
    {
        printf("Không tìm thấy.\n");
    }

    printf("\nGiải phóng bộ nhớ của danh sách.\n");
    freeList(&list);

    return 0;
}
