#include <stdio.h>
#include <stdlib.h>
#define NUMS 5

float sum(float *,int);
float average(float *,int);
float variance(float *,int);
float sqr(float);

int main(void) {
    float numbers[NUMS];
    int i,se;
    for(i = 0;i < NUMS;i ++)
        scanf("%f",&numbers[i]);
    scanf("%d",&se);
    float (*funcp)(float *,int);
    printf("Result:");
    if(se == 1)
        funcp = sum;
    else if(se == 2)
        funcp = average;
    else if(se == 3)
        funcp = variance;
    else{
        fprintf(stderr, "Error Input(1 - 3 is right.)\n");
        exit(1);
    }
    printf("%f\n",funcp(numbers,NUMS));

    return 0;
}

float sqr(float f){
    return f * f;
}

float sum(float * fpointer,int n){
    int i;
    float fsum = 0;

    for(i = 0;i < n;i ++)
        fsum += fpointer[i];

    return fsum;
}

float average(float * fpointer,int n){
    return sum(fpointer,n) / n;
}

float variance(float * fpointer,int n){
    int i;
    float fsum_sqr = 0;

    float ave = average(fpointer,n);
    for(i = 0;i < n;i ++){
        fsum_sqr += sqr(fpointer[i] - ave);
    }

    return fsum_sqr / n;
}
