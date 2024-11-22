#include <stdio.h>
#include <stdlib.h>

int isPrime(int *a) {

    if (*a <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= *a; i++) {
        if (*a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    int n1;
    scanf("%d" ,&n1);

    printf("%d", isPrime(&n1));

	return 0;
}
