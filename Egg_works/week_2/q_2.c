#include <stdio.h>
#define MAX_LEN 6

void sort(int *,int);

int main(void){
    int arr[MAX_LEN];
    int i;

    puts("input data(num:5):");
    for(i = 0;i < MAX_LEN - 1;i ++)
        scanf("%d",&arr[i]);
    sort(arr,MAX_LEN - 1);
    puts("insert num:");
    scanf("%d",&arr[MAX_LEN - 1]);
    sort(arr,MAX_LEN);

    return 0;
}

void sort(int * ip,int len){
    int i;
    int j;
    int temp;

    for(i = 0;i < len - 1;i ++)
        for(j = i + 1;j < len;j ++)
            if(ip[i] > ip[j]){
                temp = ip[i];
                ip[i] = ip[j];
                ip[j] = temp;
            }

    for(i = 0;i < len;i ++)
        printf("%d ",ip[i]);
    putchar('\n');
}
