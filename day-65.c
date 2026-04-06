#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
bool visited[MAX];
int V; // number of vertices

bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // if edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle detected
            }
        }
    }
    return false;
}

bool hasCycle() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    V = 4;

    // Example graph
    // 0 - 1
    // |   |
    // 3 - 2  (cycle exists)

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][0] = adj[0][3] = 1;

    if (hasCycle())
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}