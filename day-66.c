#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to perform DFS
bool dfs(int node, int V, int adj[MAX][MAX], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {  // edge exists
            if (!visited[i] && dfs(i, V, adj, visited, recStack))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

// Function to detect cycle
bool isCyclic(int V, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

// Driver code
int main() {
    int V = 4;

    int adj[MAX][MAX] = {0};

    // Example graph:
    // 0 → 1 → 2 → 3 → 1 (cycle)
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    if (isCyclic(V, adj))
        printf("Cycle exists\n");
    else
        printf("No cycle\n");

    return 0;
}