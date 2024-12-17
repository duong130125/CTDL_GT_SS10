#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một node trong danh sách liên kết đôi
typedef struct Node
{
    int data;
    struct Node *prev; // Con trỏ đến node trước
    struct Node *next; // Con trỏ đến node sau
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm node vào đầu danh sách
void addFirst(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Hàm thêm node vào cuối danh sách
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
    newNode->prev = temp;
}

// Hàm xóa node ở đầu danh sách
void deleteFirst(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng, không thể xóa.\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Hàm xóa node ở cuối danh sách
void deleteLast(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng, không thể xóa.\n");
        return;
    }
    Node *temp = *head;
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Hàm xóa node ở một vị trí bất kỳ
void deleteAt(Node **head, int position)
{
    if (*head == NULL || position < 1)
    {
        printf("Vị trí không hợp lệ hoặc danh sách rỗng.\n");
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Vị trí vượt quá số lượng node.\n");
        return;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Hàm duyệt danh sách từ đầu đến cuối
void displayForward(Node *head)
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

// Hàm duyệt danh sách từ cuối về đầu
void displayBackward(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách rỗng.\n");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
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
    displayForward(list);

    printf("\nDuyệt danh sách từ cuối về đầu:\n");
    displayBackward(list);

    printf("\nXóa phần tử đầu:\n");
    deleteFirst(&list);
    displayForward(list);

    printf("\nXóa phần tử cuối:\n");
    deleteLast(&list);
    displayForward(list);

    printf("\nXóa phần tử ở vị trí 2:\n");
    deleteAt(&list, 2);
    displayForward(list);

    printf("\nGiải phóng bộ nhớ của danh sách.\n");
    freeList(&list);

    return 0;
}
