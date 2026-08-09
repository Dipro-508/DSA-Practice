#include <stdio.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int n;

void dijkstra(int start) {
    int distance[MAX];
    int visited[MAX] = {0};

    for(int i = 0; i < n; i++) {
        distance[i] = INF;
    }

    distance[start] = 0;

    for(int count = 0; count < n - 1; count++) {

        int min = INF;
        int node = -1;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && distance[i] < min) {
                min = distance[i];
                node = i;
            }
        }

        if(node == -1)
            break;

        visited[node] = 1;

        for(int i = 0; i < n; i++) {
            if(graph[node][i] != INF && !visited[i]) {

                int new_distance =
                    distance[node] + graph[node][i];

                if(new_distance < distance[i]) {
                    distance[i] = new_distance;
                }
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", start);

    for(int i = 0; i < n; i++) {
        if(distance[i] == INF)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, distance[i]);
    }
}

int main() {
    int e;

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
    }

    int start;

    printf("Enter source vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}