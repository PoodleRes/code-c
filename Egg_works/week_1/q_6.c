#include <stdio.h>

int getSeedNumber(int n){
    int num=0;
    if(n==10){
        printf("Day:%d Leaf:%d\n", n, 1);
        return 1;
    }else{
    num = (getSeedNumber(n+1)+1)*2 ; //Problem
    printf("Day:%d Leaf:%d\n", n, num);
    }
    return num;
}

int main(){
    int num = getSeedNumber(1);
    printf("All :%d \n", num);
    return 0;
}
