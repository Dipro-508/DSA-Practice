#include <stdio.h>

#define MAX 100

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

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

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while(front < rear) {
        int node = queue[front++];

        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");

    return 0;
}