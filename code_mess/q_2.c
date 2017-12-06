#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n,m,i,temp,k,avg;
    temp = 0;
    k = 0;
    scanf("%d%d",&n,&m);
    for(i = 1;i <= n;i ++){
        if(i % m == 0 || i == n){
            temp += i * 2;
            k ++;
            avg = temp / k;
            temp = 0;
            k = 0;
            printf("%d ",avg);
        }else{
            temp += i * 2;
            k ++;
        }
    }
    return 0;
}
