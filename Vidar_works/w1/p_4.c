#include <stdio.h>

int main(void){
    int n,step = 0;
    printf("input num:");
    scanf("%d",&n);

    while(n != 1){
        n = n % 2 == 0 ? (n / 2):((3*n + 1) / 2);
        step ++;
    }
    printf("Step:%d\n",step);

    return 0;
}
