#include <stdio.h>
void printNumbers(int current) {
    if (current == 0) return;
    printNumbers(current - 1);
    printf("%d ", current);
}
void printPattern(int rows, int currentRow) {
    if (currentRow > rows) return;
    printNumbers(currentRow);
    printf("\n");
    printPattern(rows, currentRow + 1);
}
int main() {
    int n = 4;
    printPattern(n, 1);
    return 0;
}
