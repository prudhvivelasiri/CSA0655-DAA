#include <stdio.h>
typedef struct {
    int weight;
    int value;
} Item;
void knapsack(Item items[], int n, int capacity) {
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }
    printf("Maximum value: %.2f\n", totalValue);
}
int main() {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    knapsack(items, n, capacity);
    return 0;
}
