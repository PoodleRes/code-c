#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i,j,size,
        sum = 0;
    int * np;

    printf("The length of num:");
    scanf("%d",&size);
    np = (int *)malloc(sizeof(int) * size);
    puts("input data:");
    for(i = 0;i < size;i ++)
        scanf("%d",np + i);

    puts("Possibilities:");
    for(i = 0;i < size;i ++)
        for(j = 0;j < size;j ++)
            if(np[i] != np[j]){
                printf("%d ",np[i] * 10 + np[j]);
                sum += np[i] * 10 + np[j];
            }

    printf("\nThe result:%d\n",sum);

    return 0;
}
