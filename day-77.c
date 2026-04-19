#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

// ================= DFS =================
void dfs(int node, int adj[MAX][MAX], int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, adj, n);
        }
    }
}

// ================= BFS =================
void bfs(int start, int adj[MAX][MAX], int n) {
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// ================= CHECK CONNECTIVITY =================
int isConnectedDFS(int adj[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0, adj, n);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

int isConnectedBFS(int adj[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    bfs(0, adj, n);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

// ================= MAIN =================
int main() {
    int n, adj[MAX][MAX];
    int choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nChoose method:\n");
    printf("1. DFS\n");
    printf("2. BFS\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (isConnectedDFS(adj, n))
            printf("Graph is Connected (using DFS)\n");
        else
            printf("Graph is NOT Connected (using DFS)\n");
    }
    else if (choice == 2) {
        if (isConnectedBFS(adj, n))
            printf("Graph is Connected (using BFS)\n");
        else
            printf("Graph is NOT Connected (using BFS)\n");
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}