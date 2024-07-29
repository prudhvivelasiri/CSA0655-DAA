#include <stdio.h>
void printNumbers(int n) {
    if (n == 0) return;
    printNumbers(n - 1);
    printf("%d ", n);
}
void printPattern(int rows, int current) {
    if (current > rows) return;
    printNumbers(current);
    printf("\n");
    printPattern(rows, current + 1);
}
int main() {
    int rows = 4;
    printPattern(rows, 1);
    return 0;
}
