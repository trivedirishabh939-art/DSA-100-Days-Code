#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // acts like dynamic list (simplified)
int size[MAX];       // number of neighbors

void addEdge(int u, int v) {
    adj[u][size[u]++] = v;
    adj[v][size[v]++] = u; // undirected
}

void printGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < size[i]; j++) {
            printf("%d -> ", adj[i][j]);
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices = 5;

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);

    printGraph(vertices);
    return 0;
}