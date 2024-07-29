#include <stdio.h>
#include <limits.h>
#define MAX_KEYS 100
void optimalBST(int keys[], int freq[], int n) {
    int cost[MAX_KEYS][MAX_KEYS] = {0};
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += freq[k];
            }
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + 
                        ((r < j) ? cost[r + 1][j] : 0) + 
                        sum;
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }
    printf("Minimum cost of optimal BST is %d\n", cost[0][n - 1]);
}
int main() {
    int n;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    int keys[MAX_KEYS], freq[MAX_KEYS];
    printf("Enter keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }
    printf("Enter frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }
    optimalBST(keys, freq, n);
    return 0;
}
