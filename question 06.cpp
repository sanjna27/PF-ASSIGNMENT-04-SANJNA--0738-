#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        if (num1 > 100) {
            printf("%d is significantly larger than %d\n", num1, num2);
        } else {
            printf("%d is larger than %d\n", num1, num2);
        }
    } else if (num1 < num2) {
        if (num1 < 0) {
            printf("%d is negative and smaller than %d\n", num1, num2);
        } else {
            printf("%d is smaller than %d\n", num1, num2);
        }
    } else {
        printf("Both numbers are equal\n");
    }

    return 0;
}
