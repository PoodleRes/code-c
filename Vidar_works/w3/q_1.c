#include <stdio.h>

void swap(int *,int *);
void show(int (*)[4],int (*)[4]);


int main(int argc, char const *argv[]) {
    int arr1[4][4],arr2[4][4];
    int i,j,k = 0;
    for(i = 0;i < 4;i ++)
        for(j = 0;j < 4;j ++,k ++)
            arr1[i][j] = k;
    for(i = 0;i < 4;i ++)
        for(j = 0;j < 4;j ++,k ++)
            arr2[i][j] = k;
    show(arr1,arr2);
    for(i = 0;i < 4;i ++)
        for(j = 0;j < 4;j ++,k ++)
            swap(&arr1[i][j],&arr2[i][j]);
    show(arr1,arr2);
    return 0;
}


void show(int (*arr1)[4],int (*arr2)[4]){
    int i,j;
    printf("Arr1:\n");
    for(i = 0;i < 4;i ++){
        for(j = 0;j < 4;j ++)
            printf("%d ",arr1[i][j]);
        putchar('\n');
    }
    printf("Arr2:\n");
    for(i = 0;i < 4;i ++){
        for(j = 0;j < 4;j ++)
            printf("%d ",arr2[i][j]);
        putchar('\n');
    }
}


void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
