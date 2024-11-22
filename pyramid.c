#include <stdio.h>

void printPyramid(int satirSayisi) {

    for (int i = 1; i <= satirSayisi; ++i) {
        for (int j = 1; j <= satirSayisi - i; ++j) {
            printf(" ");
        }

        for (int j = 1; j <= 2 * i - 1; ++j) {
            printf("*");
        }

        printf("\n");
    }
}

int main() {
    int height;

    scanf("%d", &height);

    printPyramid(height);

    return 0;
}
