#include <stdio.h>

#define MAX 100

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX];
    int order[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter directed edges (u v):\n");

    for(int i = 0; i < e; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        indegree[v]++;
    }

    int front = 0;
    int rear = 0;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while(front < rear) {
        int node = queue[front++];

        order[count++] = node;

        for(int i = 0; i < n; i++) {
            if(graph[node][i]) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if(count != n) {
        printf("Topological sort is not possible.\n");
        printf("The graph contains a cycle.\n");
    }
    else {
        printf("Topological Order: ");

        for(int i = 0; i < n; i++) {
            printf("%d ", order[i]);
        }

        printf("\n");
    }

    return 0;
}