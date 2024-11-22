#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void bubbleSort(int a, int *d){

    for(int i=1;i<a;i++){
        for(int j=0;j<a-1;j++){
            if(*(d+j)>*(d+j+1)){
                int temp=*(d+j);
                *(d+j)=*(d+j+1);
                *(d+j+1)=temp;
            }
        }
    }
}


int main() {


    int a;
    scanf("%d",&a);
    int *ptr=(int* ) malloc(sizeof(int)*a);

     for(int i=0;i<a;i++){

            printf("%d. elemani giriniz. ",i+1);
            scanf("%d",ptr+i);
    }

    bubbleSort(a,ptr);

     for(int i=0;i<a;i++){

            printf("%d ",ptr[i]);

    }
    free(ptr);
    ptr=NULL;


	return 0;
}
