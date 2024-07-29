#include <stdio.h>
typedef struct {
    int min;
    int max;
} MinMax;
MinMax findMinMax(int array[], int left, int right) {
    MinMax result, leftResult, rightResult;
    if (left == right) {
        result.min = array[left];
        result.max = array[left];
        return result;
    }
    if (right == left + 1) {
        if (array[left] < array[right]) {
            result.min = array[left];
            result.max = array[right];
        } else {
            result.min = array[right];
            result.max = array[left];
        }
        return result;
    }
    int mid = left + (right - left) / 2;
    leftResult = findMinMax(array, left, mid);
    rightResult = findMinMax(array, mid + 1, right);
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;
    return result;
}
int main() {
    int array[] = {3, 5, 0, 4, 7, 2, 6};
    int size = sizeof(array) / sizeof(array[0]);
    MinMax result = findMinMax(array, 0, size - 1);
    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);
    return 0;
}
