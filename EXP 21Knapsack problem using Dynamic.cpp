#include <stdio.h>
#define MAX_ITEMS 100
#define MAX_WEIGHT 1000
int max(int a, int b) {
    return (a > b) ? a : b;
}
void knapsack(int n, int W, int weights[], int values[]) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    printf("Maximum value in knapsack = %d\n", dp[n][W]);
}
int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int weights[MAX_ITEMS], values[MAX_ITEMS];
    printf("Enter weights and values of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
    }
    printf("Enter maximum weight capacity of knapsack: ");
    scanf("%d", &W);
    knapsack(n, W, weights, values);
    return 0;
}
