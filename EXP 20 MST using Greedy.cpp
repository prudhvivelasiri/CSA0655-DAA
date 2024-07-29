#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define INF 999999
typedef struct {
    int u, v, weight;
} Edge;
Edge edges[MAX_VERTICES * MAX_VERTICES];
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];
int numEdges = 0;
int find(int i) {
    if (parent[i] != i) {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}
void kruskal(int numVertices) {
    qsort(edges, numEdges, sizeof(Edge), compareEdges);
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    int mstWeight = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(u) != find(v)) {
            unionSets(u, v);
            printf("%d -- %d == %d\n", u, v, weight);
            mstWeight += weight;
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
}
int main() {
    int numVertices = 4;
    edges[numEdges++] = (Edge){0, 1, 10};
    edges[numEdges++] = (Edge){0, 2, 6};
    edges[numEdges++] = (Edge){0, 3, 5};
    edges[numEdges++] = (Edge){1, 3, 15};
    edges[numEdges++] = (Edge){2, 3, 4};
    kruskal(numVertices);
    return 0;
}
