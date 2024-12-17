#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Danh sách kề (Adjacency List)
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    bool isDirected;
    Node *adjacencyList[MAX_VERTICES];
} Graph;

// Tạo một đỉnh mới
Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Tạo đồ thị
Graph *createGraph(int numVertices, bool isDirected)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->isDirected = isDirected;
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

// Thêm cạnh vào đồ thị
void addEdge(Graph *graph, int src, int dest)
{
    // Thêm dest vào danh sách kề của src
    Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Nếu đồ thị không có hướng, thêm cạnh ngược lại
    if (!graph->isDirected)
    {
        newNode = createNode(src);
        newNode->next = graph->adjacencyList[dest];
        graph->adjacencyList[dest] = newNode;
    }
}

// Hiển thị đồ thị
void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("%d: ", i);
        Node *temp = graph->adjacencyList[i];
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// DFS sử dụng đệ quy
void DFSUtil(Graph *graph, int vertex, bool visited[])
{
    visited[vertex] = true;
    printf("%d ", vertex);

    Node *temp = graph->adjacencyList[vertex];
    while (temp)
    {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex])
        {
            DFSUtil(graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(Graph *graph, int startVertex)
{
    bool visited[MAX_VERTICES] = {false};
    printf("DFS starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// BFS sử dụng hàng đợi
void BFS(Graph *graph, int startVertex)
{
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS starting from vertex %d: ", startVertex);
    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node *temp = graph->adjacencyList[currentVertex];
        while (temp)
        {
            int connectedVertex = temp->vertex;
            if (!visited[connectedVertex])
            {
                visited[connectedVertex] = true;
                queue[rear++] = connectedVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int numVertices = 5;
    Graph *graph = createGraph(numVertices, false); // false: đồ thị không hướng

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Adjacency List of the graph:\n");
    printGraph(graph);

    DFS(graph, 0);
    BFS(graph, 0);

    // Giải phóng bộ nhớ (nếu cần)

    return 0;
}
