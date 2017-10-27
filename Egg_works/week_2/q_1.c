#include <stdio.h>
#define MAX_LEN 10

double get_result(const double *,int);

int main(void){
    double arr[MAX_LEN];
    int i;

    puts("input data(num:10):");
    for(i = 0;i < MAX_LEN;i ++)
        scanf("%lf",&arr[i]);

    printf("result:%lf\n",get_result(arr,MAX_LEN));

    return 0;
}

double get_result(const double * ap,int len){
    double result = 1;
    int i;

    for(i = 0;i < len;i ++)
        result *= ap[i];

    return result;
}
