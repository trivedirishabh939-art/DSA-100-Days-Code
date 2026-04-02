#include <stdio.h>
#include <stdlib.h>

// Function to create adjacency matrix
int** createGraph(int n) {
    int **adjMatrix = (int**)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int*)malloc(n * sizeof(int));
        
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0; // initialize with 0
        }
    }
    
    return adjMatrix;
}

// Function to add edge
void addEdge(int **adjMatrix, int u, int v, int isDirected) {
    adjMatrix[u][v] = 1;
    
    if (!isDirected) {
        adjMatrix[v][u] = 1;
    }
}

// Function to print adjacency matrix
void printMatrix(int **adjMatrix, int n) {
    printf("\nAdjacency Matrix:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    
    printf("Enter number of vertices (n): ");
    scanf("%d", &n);
    
    printf("Enter number of edges (m): ");
    scanf("%d", &m);
    
    int isDirected;
    printf("Enter 1 for Directed graph, 0 for Undirected graph: ");
    scanf("%d", &isDirected);
    
    // Create graph
    int **adjMatrix = createGraph(n);
    
    printf("Enter edges (u v) where 0 <= u,v < n:\n");
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        addEdge(adjMatrix, u, v, isDirected);
    }
    
    // Print adjacency matrix
    printMatrix(adjMatrix, n);
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    
    return 0;
}