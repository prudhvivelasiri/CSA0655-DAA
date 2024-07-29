#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100 
void matrixMultiply(int A[N][N], int B[N][N], int C[N][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
int main() {
    int A[N][N], B[N][N], C[N][N];
    int i, j;
    clock_t start, end;
    double cpu_time_used;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }
    start = clock();
    matrixMultiply(A, B, C);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %f seconds\n", cpu_time_used);
    return 0;
}
