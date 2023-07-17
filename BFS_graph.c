#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Queue implementation for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Graph representation using adjacency matrix
typedef struct {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Queue functions
void enqueue(Queue* q, int value) {
    q->items[q->rear] = value;
    q->rear++;
}

int dequeue(Queue* q) {
    int item = q->items[q->front];
    q->front++;
    return item;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Graph functions
void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    // Add an edge between two vertices
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

void breadthFirstSearch(Graph* g, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    Queue q;
    q.front = 0;
    q.rear = 0;

    visited[startVertex] = true;
    printf("Visited vertex: %d\n", startVertex);
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                printf("Visited vertex: %d\n", i);
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    Graph g;
    int vertices, edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("BFS traversal starting from vertex %d:\n", startVertex);
    breadthFirstSearch(&g, startVertex);

    return 0;
}

