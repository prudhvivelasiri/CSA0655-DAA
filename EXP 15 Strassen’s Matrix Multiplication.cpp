#include <stdio.h>
void add(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtract(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];
    int temp1[2][2], temp2[2][2];

    add(A, A, temp1);
    add(B, B, temp2);
    add(temp1, temp2, M1);

    add(A, A, temp1);
    add(temp1, B, M2);

    subtract(B, B, temp2);
    add(A, temp2, M3);

    subtract(B, B, temp2);
    add(A, temp2, M4);

    add(A, A, temp1);
    add(B, B, temp2);
    add(temp1, temp2, M5);

    subtract(A, A, temp1);
    add(B, B, temp2);
    add(temp1, temp2, M6);

    subtract(A, A, temp1);
    add(B, B, temp2);
    add(temp1, temp2, M7);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i + 1][j] = M3[i][j] + M5[i][j];
            C[i][j + 1] = M2[i][j] + M4[i][j];
            C[i + 1][j + 1] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}
int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];
    strassen(A, B, C);
    printf("Product Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
