#include <stdio.h>
#include <stdlib.h>

void qsort_my(int *,int,int);

int main(int argc, char const *argv[]) {
    int * array,i,num;
    puts("input num's num:");
    scanf("%d",&num);
    array = (int *)malloc(sizeof(int) * num);
    puts("input your numbers:");
    for(i = 0;i < num;i ++)
        scanf("%d",&array[i]);
    qsort_my(array,0,num - 1);
    for(i = 0;i < num;i ++)
        printf("%d ",array[i]);
    putchar('\n');

    free(array);
    return 0;
}

void qsort_my(int * arr,int start,int end){
    if(start >= end)
        return ;

    int keyword = arr[start];
    int left = start,right = end;

    while(left < right){
        //can be loop & next time will change normally
        //arr[left] = arr[right1]
        //arr[right1] = arr[left1]
        //arr[left1] = arr[right2]
        //arr[right2] = arr[left2]
        //arr[left2] = keyword
        while(left < right && arr[right] > keyword)
            right --;
        arr[left] = arr[right];
        while(left < right && arr[left] < keyword)
            left ++;
        arr[right] = arr[left];
    }
    arr[left] = keyword;
    qsort_my(arr,start,left - 1);
    qsort_my(arr,left + 1,end);
}
