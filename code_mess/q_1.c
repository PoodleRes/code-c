#include <stdio.h>

int main(void) {
    int n,i = 2;
    long long int res = 1;
    scanf("%d",&n);
    for(;i <= n;i ++)
        res *= i;
    while(res >= 100000)
        res /= 10;
    printf("%d",res);
    return 0;
}
