#include <stdio.h>
#include <math.h>
int countDigits(int num) {
    if (num == 0)
        return 0;
    return 1 + countDigits(num / 10);
}
int powerSum(int num, int digits) {
    if (num == 0)
        return 0;
    int digit = num % 10;
    return pow(digit, digits) + powerSum(num / 10, digits);
}
int isArmstrong(int num) {
    int digits = countDigits(num);
    return num == powerSum(num, digits);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
    return 0;
}
