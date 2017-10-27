#include <stdio.h>
#define LEN 10

static int a[LEN] = {132,443,17,325,128,55,589,250,666,999};

void sort(int *,int);

int main(void){
    int new[LEN];
    int i;
    int index = 0;

    printf("Deleted:");
    for(i = 0;i < LEN;i ++)
        if(a[i] % 5 == 0)
            printf("%d ",a[i]);
        else{
            new[index] = a[i];
            index ++;//following index is len
        }
    putchar('\n');
    sort(new,index);

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
    printf("Sorted:");
    for(i = 0;i < len;i ++)
        printf("%d ",ip[i]);
    putchar('\n');
}
