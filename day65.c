//  Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];
int n;               // Number of vertices

// DFS function with parent tracking
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            
            // If not visited, recurse
            if (!visited[i]) {
                if (dfs(i, node))
                    return 1;
            }
            // If visited and not parent → cycle
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check cycle in graph
int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    if (hasCycle())
        printf("Cycle detected in the graph.\n");
    else
        printf("No cycle in the graph.\n");

    return 0;
}