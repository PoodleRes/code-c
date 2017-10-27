#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double average(const double *,int);
double variance(const double *,int);

int main(void) {

    int n;
    double * arr_pointer;

    puts("Input N:");
    scanf("%d",&n);
    arr_pointer = (double *)malloc(n*sizeof(double));
    puts("Input sample:");
    for(int i = 0;i < n;i ++)
        scanf("%lf",&arr_pointer[i]);
    printf("Average:%lf Variance:%lf\n",average(arr_pointer,n),
            variance(arr_pointer,n));

    return 0;
}

double average(const double * arr,int length){
    double sum = 0;
    for(int i = 0;i < length;i ++)
        sum += arr[i];
    return (sum / length);
}

double variance(const double * arr,int length){
    double average_value = average(arr,length);
    double sum_var = 0;
    for(int i = 0;i < length;i ++)
        sum_var += pow(arr[i]-average_value,2);
    return (sum_var / length);
}
