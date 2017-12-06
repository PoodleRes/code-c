#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n,i;
    double res = 0;
    scanf("%d",&n);
    for(i = 1;i <= n;i ++)
        res += (i % 2 == 0 ? -1 : 1) * 1.0 / i;
    printf("%.2lf",res);
    return 0;
}
