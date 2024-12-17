#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc một nút trong cây nhị phân
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Hàm tạo nút mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm thêm phần tử vào cây nhị phân
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Duyệt cây theo thứ tự trước (PreOrder)
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Duyệt cây theo thứ tự giữa (InOrder)
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Duyệt cây theo thứ tự sau (PostOrder)
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Tìm kiếm một phần tử trong cây
Node *search(Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Hàm hiển thị menu và xử lý tùy chọn của người dùng
void menu()
{
    Node *root = NULL;
    int choice, value;
    do
    {
        printf("\n==== MENU ====\n");
        printf("1. Thêm phần tử vào cây nhị phân\n");
        printf("2. Duyệt cây (PreOrder)\n");
        printf("3. Duyệt cây (InOrder)\n");
        printf("4. Duyệt cây (PostOrder)\n");
        printf("5. Tìm kiếm phần tử trong cây\n");
        printf("6. Thoát\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Nhập giá trị cần thêm: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Đã thêm phần tử %d vào cây.\n", value);
            break;
        case 2:
            printf("Duyệt cây theo thứ tự trước (PreOrder): ");
            preOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Duyệt cây theo thứ tự giữa (InOrder): ");
            inOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Duyệt cây theo thứ tự sau (PostOrder): ");
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Nhập giá trị cần tìm: ");
            scanf("%d", &value);
            Node *found = search(root, value);
            if (found != NULL)
            {
                printf("Phần tử %d tồn tại trong cây.\n", value);
            }
            else
            {
                printf("Phần tử %d không tồn tại trong cây.\n", value);
            }
            break;
        case 6:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
            break;
        }
    } while (choice != 6);
}

// Hàm chính
int main()
{
    menu();
    return 0;
}
