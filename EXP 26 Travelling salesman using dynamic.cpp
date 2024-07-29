#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 20
#define INF INT_MAX

int tsp(int dist[MAX_CITIES][MAX_CITIES], int n, int pos, int visited, int dp[MAX_CITIES][1 << MAX_CITIES]) {
    if (visited == (1 << n) - 1) {
        return dist[pos][0];
    }

    if (dp[pos][visited] != -1) {
        return dp[pos][visited];
    }

    int minCost = INF;

    for (int city = 0; city < n; city++) {
        if ((visited & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tsp(dist, n, city, visited | (1 << city), dp);
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    return dp[pos][visited] = minCost;
}

int main() {
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    int dist[MAX_CITIES][MAX_CITIES];
    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    int dp[MAX_CITIES][1 << MAX_CITIES];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    int minCost = tsp(dist, n, 0, 1, dp);
    printf("Minimum cost of visiting all cities: %d\n", minCost);

    return 0;
}
