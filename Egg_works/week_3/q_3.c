#include <stdio.h>
#define LEN 10

int int_sort(int *,int,int,_Bool);

int main(void) {
    int arr[LEN];
    int i;

    for(i = 0;i < LEN;i ++)
        scanf("%d",&arr[i]);

    int_sort(arr,0,LEN - 1,0);
    for(i = 0;i < LEN;i ++)
        printf("%d ",arr[i]);
    putchar('\n');
    
    int_sort(arr,3,3 + 5 - 1,1);
    for(i = 0;i < LEN;i ++)
        printf("%d ",arr[i]);
    putchar('\n');

    return 0;
}

int int_sort(int * p,int start,int end,_Bool up_or_down){
    int i,j,temp;
    for(i = start;i < end;i ++){
        for(j = i + 1;j <= end;j ++){
            if(up_or_down){
                if(p[i] < p[j]){
                    temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }else{
                if(p[i] > p[j]){
                    temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
    }
}
