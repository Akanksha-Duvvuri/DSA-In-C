#include <stdio.h>
#include <stdlib.h>

#define V 5
int adjMatrix[V][V];
int visited[V];

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

// ─── DFS (Recursive) 

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

// ─── BFS (Iterative using Queue) 

int queue[V];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear == V - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void bfs(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for (int i = 0; i < V; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    for (int i = 0; i < V; i++) visited[i] = 0;
    printf("DFS from 0: ");
    dfs(0);

    for (int i = 0; i < V; i++) visited[i] = 0;
    front = rear = -1;
    printf("BFS from 0: ");
    bfs(0);

    printf("");
    return 0;
}