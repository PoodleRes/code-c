#include <stdio.h>

int greater_common_divsor(int,int);
int least_common_multiple(int,int);

int main(void) {

    int a,b;

    puts("Input two num(No check.):");
    scanf("%d%d",&a,&b);
    printf("greater_common_divsor:%d\n",greater_common_divsor(a,b));
    printf("least_common_multiple:%d\n",least_common_multiple(a,b));

    return 0;
}

int greater_common_divsor(int a,int b){
    if(a < b){//ensure a>=b
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int r;
    while (r = a % b) {
        a = b;
        b = r;
    }
    return b;
}

int least_common_multiple(int a,int b){
    return (a * b / greater_common_divsor(a , b));
}
