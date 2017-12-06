#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    int a,b,i,j,flag,res = 0;
    scanf("%d%d",&a,&b);
    for(i = a;i <= b;i ++){
        flag = 0;
        if(i == 1)
            continue;
        if(i == 2){
            res ++;
            continue;
        }
        if(i == 3){
            res ++;
            continue;
        }
        for(j = 2;j <= sqrt(i);j ++){
            if(i % j == 0 && i != 2){
                flag = 0;
                break;
            }else{
                flag = 1;
            }
        }
        if(flag)
            res ++;
    }
    printf("%d\n",res);
    return 0;
}
