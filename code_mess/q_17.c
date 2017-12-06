#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i,j,n;
    scanf("%d",&n);
    for(i = 1;i <= n;i ++){
        for(j = 1;j <= i;j ++){
            printf("%d*%d=%d ",j,i,i * j);
        }
        putchar('\n');
    }
    return 0;
}
