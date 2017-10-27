#include <stdio.h>
#define MAX_LEN 10



int main(void) {
    int arr[MAX_LEN],result[MAX_LEN];
    int start,end;
    int i;
    int temp = 0;
    int lens;
    int max;

    puts("input the list(num:10):");
    for(i = 0;i < MAX_LEN;i ++)
        scanf("%d",&arr[i]);
    max = arr[0];
    for(start = 0;start < MAX_LEN;start ++)
        for(end = MAX_LEN - 1;end >= start;end --){
            for(i = start;i < end;i ++){
                temp += arr[i];
            }
            if (temp > max){
                max = temp;
                lens = 0;
                for(i = start;i < end;i ++){
                    result[i] = arr[i];
                    lens ++;
                }
            }
            temp = 0;
        }

    printf("MAX:%d\n",max);
    printf("List:");
    for(i = 0;i < lens;i ++)
        printf("%d ",result[i]);
    putchar('\n');


    return 0;
}
