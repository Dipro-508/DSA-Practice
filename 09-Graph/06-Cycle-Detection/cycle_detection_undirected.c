#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

int has_cycle(int node, int parent) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[node][i]) {
            if(!visited[i]) {
                if(has_cycle(i, node))
                    return 1;
            }
            else if(i != parent) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");

    for(int i = 0; i < e; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int cycle = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(has_cycle(i, -1)) {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle)
        printf("Cycle detected!\n");
    else
        printf("No cycle detected.\n");

    return 0;
}