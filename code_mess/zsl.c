#include <stdio.h>

int sqr(int,int);
int operate(int,int,int);


int main(void) {
    int candy_start,res;
    int seconds,candy_add;
    seconds = sqr(10,9) + 7;
    scanf("%d%d",&candy_start,&candy_add);
    printf("%d\n",operate(candy_start,candy_add,seconds));


    return 0;
}

int operate(int start,int add,int seconds){
    int res;
    res = start;
    while (seconds > 0) {
        res /= 2;
        res += add;
        seconds --;
    }
        return res;
}

int sqr(int a,int b){
    int i;
    long long int res = 1;
    for(i = 0;i < b;i ++)
        res *= a;
    return res;
}
