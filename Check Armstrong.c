#include <stdio.h>
#include <math.h>

int main() {
    int numbers[20], i;

    // Input 20 integers
    printf("Enter 20 integers:\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &numbers[i]);
    }

    // Check for Armstrong numbers
    printf("Armstrong numbers among the given integers are:\n");
    for (i = 0; i < 20; i++) {
        int num = numbers[i];
        int originalNum = num;
        int sum = 0;
        int digits = 0;

        // Count the number of digits
        while (originalNum != 0) {
            originalNum /= 10;
            digits++;
        }

        originalNum = num;

        // Calculate the sum of the powers of the digits
        while (originalNum != 0) {
            int digit = originalNum % 10;
            sum += pow(digit, digits);
            originalNum /= 10;
        }

        // Check if the number is an Armstrong number
        if (sum == num) {
            printf("%d ", num);
        }
    }
    printf("\n");

    return 0;
}

