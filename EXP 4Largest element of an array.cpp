#include <stdio.h>
int findLargest(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int arr[] = {5, 17, 9, 23, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest = findLargest(arr, n);
    printf("The largest element is %d\n", largest);
    return 0;
}
