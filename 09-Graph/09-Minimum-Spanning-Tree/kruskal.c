#include <stdio.h>

#define MAX 100

struct Edge {
    int u;
    int v;
    int w;
};

int parent[MAX];
int rank[MAX];

int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

int union_set(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);

    if(root_a == root_b)
        return 0;

    if(rank[root_a] < rank[root_b]) {
        parent[root_a] = root_b;
    }
    else if(rank[root_a] > rank[root_b]) {
        parent[root_b] = root_a;
    }
    else {
        parent[root_b] = root_a;
        rank[root_a]++;
    }

    return 1;
}

void sort_edges(struct Edge edges[], int e) {

    for(int i = 0; i < e - 1; i++) {

        for(int j = 0; j < e - i - 1; j++) {

            if(edges[j].w > edges[j + 1].w) {

                struct Edge temp = edges[j];

                edges[j] = edges[j + 1];

                edges[j + 1] = temp;
            }
        }
    }
}

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

    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sort_edges(edges, e);

    int total_cost = 0;
    int edges_used = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for(int i = 0; i < e; i++) {

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(union_set(u, v)) {

            printf("%d -- %d  weight: %d\n",
                   u, v, w);

            total_cost += w;
            edges_used++;

            if(edges_used == n - 1)
                break;
        }
    }

    if(edges_used != n - 1) {

        printf("\nMST is not possible because the graph is disconnected.\n");

    } else {

        printf("\nMinimum Cost: %d\n", total_cost);
    }

    return 0;
}