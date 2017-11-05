#include <stdio.h>

#define END 1000
#define START 1


int pow_int(int,int);
int cube(int);

int main(void){
    int i,j,bits,temp,sumtemp,temp_1;

    printf("NUMS:");
    for(i = START;i < END;i ++){
        bits = 0;
        sumtemp = 0;
        temp = i;
        while(temp != 0){
            temp = i / pow_int(10,bits);
            bits ++;
        }
        temp = i;
        for (j = bits - 1;j >= 0;j --){
            temp_1 = temp / pow_int(10,j);
            temp -= temp_1 * pow_int(10,j);
            sumtemp += cube(temp_1);
        }
        if(sumtemp == i)
            printf("%d ",i);
    }
    putchar('\n');
    return 0;
}


int cube(int n){
    return n * n * n;
}

int pow_int(int a,int b){
    int result = 1;
    int i;

    if(b == 0)
        return result;

    for(i = 1;i <= b;i ++)
        result *= a;

    return result;
}
