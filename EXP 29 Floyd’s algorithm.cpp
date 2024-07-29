#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
#define INF INT_MAX
void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int dist[MAX_VERTICES][MAX_VERTICES], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
void printSolution(int dist[MAX_VERTICES][MAX_VERTICES], int V) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int graph[MAX_VERTICES][MAX_VERTICES], dist[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (use 9999 for infinity):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 9999) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = graph[i][j];
            }
        }
    }
    floydWarshall(graph, dist, V);
    printSolution(dist, V);
    return 0;
}
