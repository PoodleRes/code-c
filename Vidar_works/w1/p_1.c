#include <stdio.h>

#define PI 3.14
#define AREA(X,Y) (((X) * (X) * PI)*2 + (X)*(Y))
#define VOLUME(X,Y) ((X)*(X)*PI*Y)


int main(void){
    double r;
    double h;

    puts("input r and h:");
    scanf("%lf%lf",&r,&h);
    printf("Surface Area:%.2lf Volume:%.2lf\n",AREA(r,h),VOLUME(r,h));

    return 0;
}
