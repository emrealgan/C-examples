#include <stdio.h>

void printPattern(int number) {
    // Upper half of the pattern
    for (int i = 0; i <= number; ++i) {
        // Print spaces
        for (int j = number - 1; j >= i; --j) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= 2 * i - 1; ++j) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half of the pattern
    for (int i = 1; i <= number - 1; ++i) {
        // Print spaces
        for (int j = 0; j < i; ++j) {
            printf(" ");
        }
        // Print stars
        for (int j = 2 * number - i - 1; j > i; --j) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int number;

    printf("Enter the number: ");
    scanf("%d", &number);

    printPattern(number);

    return 0;
}
