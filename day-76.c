#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

// -------- DFS --------
void dfs(int node, int graph[MAX][MAX], int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, graph, n);
        }
    }
}

// -------- BFS --------
void bfs(int start, int graph[MAX][MAX], int n) {
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// -------- Count Components using DFS --------
int countComponentsDFS(int graph[MAX][MAX], int n) {
    int count = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, n);
            count++;
        }
    }

    return count;
}

// -------- Count Components using BFS --------
int countComponentsBFS(int graph[MAX][MAX], int n) {
    int count = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, graph, n);
            count++;
        }
    }

    return count;
}

// -------- Main --------
int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int dfsCount = countComponentsDFS(graph, n);
    int bfsCount = countComponentsBFS(graph, n);

    printf("Connected Components (DFS): %d\n", dfsCount);
    printf("Connected Components (BFS): %d\n", bfsCount);

    return 0;
}