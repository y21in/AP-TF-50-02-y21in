#include <stdio.h>

int main() {
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    result = num1 + num2;
    printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, result);
    return 0;
}