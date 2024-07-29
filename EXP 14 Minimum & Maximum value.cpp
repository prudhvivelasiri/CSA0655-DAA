#include <stdio.h>
void findMinMax(int array[], int size, int *min, int *max) {
    *min = array[0];
    *max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < *min) {
            *min = array[i];
        }
        if (array[i] > *max) {
            *max = array[i];
        }
    }
}
int main() {
    int array[] = {5, 3, 8, 6, 2, 7, 4, 1};
    int size = sizeof(array) / sizeof(array[0]);
    int min, max;
    findMinMax(array, size, &min, &max);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    return 0;
}
