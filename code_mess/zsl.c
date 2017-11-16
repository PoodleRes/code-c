#include <stdio.h>

int sqr(int,int);//这个是计算整数a 的 b次方
int operate(int,int,int);//这是操作 核心函数


int main(void) {
    int candy_start,res;//candy_start是起始糖果数，res是结果
    int seconds,candy_add;//seconds是秒数,candy_add是增加的数量
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
