#include <stdio.h>
#define MAX 100
int binomialCoeff(int n, int k) {
    int dp[MAX][MAX];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[n][k];
}
int main() {
    int n, k;
    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);
    printf("Binomial Coefficient C(%d, %d) is %d\n", n, k, binomialCoeff(n, k));
    return 0;
}
