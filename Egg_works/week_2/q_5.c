#include <stdio.h>
#define MAX_LEN (10+6+1)
//+3.4E+38
char str[MAX_LEN];
char * myFloatToString(float);
int pow_ten(int);


int main(void) {
    float f;
    printf("input float:");
    scanf("%f",&f);
    printf("%f\n",f);
    printf("%s\n",myFloatToString(f));

    return 0;
}

int pow_ten(int num){
    int temp = 1;
    for(;num > 0;num --)
        temp *= 10;
    return temp;
}


char * myFloatToString(float f){
    int i;
    int index = 0;
    int r;
    int int_part = (int)f;
    float float_part = f - int_part;
    _Bool flag = 0;
    for(i = 10;i >= 0;i --){
        r = int_part / pow_ten(i);
        if(r != 0)
            flag = 1;
        if(flag){
            int_part -= r * pow_ten(i);
            str[index] = '0'+r;
            index ++;
        }
    }
    str[index] = '.';
    index ++;
    int_part = (int) (float_part * pow_ten(6));
    for(i = 5;i >= 0;i --){
        r = int_part / pow_ten(i);
        int_part -= r * pow_ten(i);
        str[index] = '0'+ r;
        index ++;
    }
    str[index] = '\0';

    return str;
}
