#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];   // Adjacency matrix
int visited[MAX];      // Visited array
int n;                 // Number of vertices

// DFS function using recursion
void DFS(int v) {
    printf("%d ", v);      // Print current vertex
    visited[v] = 1;        // Mark as visited

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);        // Recursive call
        }
    }
}

int main() {
    int source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    printf("DFS Traversal: ");
    DFS(source);

    return 0;
}