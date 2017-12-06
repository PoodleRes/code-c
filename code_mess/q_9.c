#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n,i,positive = 0,negative = 0,zero = 0;
    double temp;
    scanf("%d,",&n);
    for(i = 0;i < n;i ++){
        if(i != n - 1)
            scanf("%lf,",&temp);
        else
            scanf("%lf",&temp);
        if(temp > 0)
            positive ++;
        else if(temp < 0)
            negative ++;
        else
            zero ++;
    }
    printf("%d,%d,%d",positive,zero,negative);
    return 0;
}
