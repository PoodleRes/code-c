#include <stdio.h>
#define TOTAL 36

int main(int argc, char const *argv[]) {
    int i,j,k,flag = 0;
    for(i = 1;i <= TOTAL;i ++){
        for(j = 1;j <= TOTAL - i; j ++){
            if((float)TOTAL == i * 4 + j * 3 + (TOTAL - i - j) / 2.0){
                flag = 1;
                k = TOTAL - i - j;
                break;
            }
        }
        if(flag){
            printf("%d %d %d\n",i,j,k);
            break;
        }
    }
    return 0;
}
