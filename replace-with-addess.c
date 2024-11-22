#include <stdio.h>
#include <stdlib.h>

void replace_with_address(int *a, int *b){

    int x;
    x=*a;
    *a=*b;
    *b=x;
}

int main() {

    int n1,n2;

    scanf("%d %d", &n1, &n2);
    replace_with_address(&n1, &n2);

    printf("%d %d", n1, n2);

	return 0;
}
