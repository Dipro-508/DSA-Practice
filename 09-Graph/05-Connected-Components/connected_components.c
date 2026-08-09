#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void dfs(int node) {
    visited[node] = 1;

    printf("%d ", node);

    for(int i = 0; i < n; i++) {
        if(graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
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

    int count = 0;

    printf("\nConnected Components:\n");

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            count++;

            printf("Component %d: ", count);

            dfs(i);

            printf("\n");
        }
    }

    printf("Total Connected Components: %d\n", count);

    return 0;
}