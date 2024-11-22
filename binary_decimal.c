#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void decimal_to_binary(int x)
{
    int i = 0;
    int *binary = (int *) malloc (sizeof(x/2+1));

    while(x > 0)
    {
        binary[i] = x % 2;
        x/= 2;
        ++i;
    }

    for(i = i-1; i >= 0; --i)
            printf("%d", binary[i]);
}

void binary_to_decimal(int y)
{
    int rem, decimal = 0, weight = 1;
    while(y != 0)
    {
     rem = y % 10;
     decimal = decimal + rem * weight;
     y/= 10;
     weight*= 2;
    }
    printf("%d", decimal);
}
int main()
{
    int number;
    printf("Enter a base 10 number ");
    scanf("%d", &number);

    decimal_to_binary(number);

    printf("\nEnter a base 2 number ");
    scanf("%d", &number);

    binary_to_decimal(number);

    return 0;
}
