#include <stdio.h>
#include <stdlib.h>

void allPrimeFactors(int *a){

    for(int i = 2; *a > 1; i++){

        while(*a % i == 0){
            printf("%d\n", i);
            *a /= i;
        }
    }
}

void primeFactors(int *a){

    int i, j;

    for(i = 2; i <= *a; i++){

        int flag = 1;
        for(j = 2; j < i; j++){

            if(i % j == 0)  flag = 0;

        }
        if(flag == 1  &&  *a % i == 0)  printf("%d\n", i);
    }
}

int main() {

    int n1;
    scanf("%d" ,&n1);

    primeFactors(&n1);
    allPrimeFactors(&n1)
    
    return 0;
}
