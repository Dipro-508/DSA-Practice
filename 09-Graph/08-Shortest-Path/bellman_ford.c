#include <stdio.h>

#define MAX 100
#define INF 999999

struct Edge {
    int u;
    int v;
    int w;
};

int main() {

    int n, e;
    struct Edge edges[MAX * MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter weighted edges (u v w):\n");

    for(int i = 0; i < e; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    int start;

    printf("Enter source vertex: ");
    scanf("%d", &start);

    int distance[MAX];

    for(int i = 0; i < n; i++) {
        distance[i] = INF;
    }

    distance[start] = 0;

    for(int i = 0; i < n - 1; i++) {

        int updated = 0;

        for(int j = 0; j < e; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(distance[u] != INF &&
               distance[u] + w < distance[v]) {

                distance[v] = distance[u] + w;
                updated = 1;
            }
        }

        if(!updated)
            break;
    }

    int negative_cycle = 0;

    for(int i = 0; i < e; i++) {

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(distance[u] != INF &&
           distance[u] + w < distance[v]) {

            negative_cycle = 1;
            break;
        }
    }

    if(negative_cycle) {

        printf("Negative-weight cycle detected!\n");

    } else {

        printf("\nShortest distances from vertex %d:\n",
               start);

        for(int i = 0; i < n; i++) {

            if(distance[i] == INF)
                printf("%d -> INF\n", i);
            else
                printf("%d -> %d\n",
                       i,
                       distance[i]);
        }
    }

    return 0;
}