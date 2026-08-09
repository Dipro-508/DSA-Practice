#include <stdio.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];

int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter weighted edges (u v w):\n");

    for(int i = 0; i < e; i++) {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int start;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    int key[MAX];
    int parent[MAX];
    int visited[MAX] = {0};

    for(int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[start] = 0;

    int total_cost = 0;
    int edges_used = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for(int count = 0; count < n; count++) {

        int min = INF;
        int node = -1;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && key[i] < min) {
                min = key[i];
                node = i;
            }
        }

        if(node == -1)
            break;

        visited[node] = 1;

        if(parent[node] != -1) {
            printf("%d -- %d  weight: %d\n",
                   parent[node],
                   node,
                   key[node]);

            total_cost += key[node];
            edges_used++;
        }

        for(int i = 0; i < n; i++) {
            if(graph[node][i] != INF &&
               !visited[i] &&
               graph[node][i] < key[i]) {

                key[i] = graph[node][i];
                parent[i] = node;
            }
        }
    }

    if(edges_used != n - 1) {
        printf("\nMST is not possible because the graph is disconnected.\n");
    } else {
        printf("\nMinimum Cost: %d\n", total_cost);
    }

    return 0;
}