#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // Input edges
    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;  // increase indegree of v
    }

    // Step 1: Add all vertices with indegree 0 to queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int topo[MAX], index = 0;

    // Step 2: Process queue
    while (!isEmpty()) {
        int u = dequeue();
        topo[index++] = u;

        // Reduce indegree of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    // Step 3: Check for cycle
    if (index != V) {
        printf("Graph has a cycle. Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < V; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}