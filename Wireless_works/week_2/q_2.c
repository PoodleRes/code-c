#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 32+1
#define CORRECT_LEN 32
#define ZERO '0'
#define ONE '1'
#define DOT '.'

int s_gets(char *,int);//No import string.h head file -> strlen(str)
void check(const char *,int);
void binstr_to_decimal(const char *);

int main(void) {
    char str[MAX_LEN];
    int len;
    printf("Input 32 bit binary data:");
    len = s_gets(str,MAX_LEN);
    check(str,len);
    binstr_to_decimal(str);
    return 0;
}

int s_gets(char * str,int len){
    int strlength = 0;
    char * find = NULL;
    fgets(str,len,stdin);
    while(*str != '\0'){
        strlength ++;
        if(*str == '\n')
            find = str;
        str ++;
    }
    if (find)
        *find = '\0';
    else
        while(getchar() != '\n')
            continue;
    return strlength;
}

void check(const char * str,int len){
    if(len != CORRECT_LEN){
        fprintf(stderr,"LengthError:Except %d but %d.\n",CORRECT_LEN,len);
        exit(EXIT_FAILURE);
    }else{
        while(*str != '\0'){
            if (*str != ZERO && *str != ONE){
                fprintf(stderr, "TypeError:Except %c or %c but %c.\n",ZERO,ONE,*str);
                exit(EXIT_FAILURE);
            }
            str ++;
        }
    }
}

void binstr_to_decimal(const char * str){
    char temp[8];
    int a,power,i,j,m;
    printf("IP:");
    for(j = 0;j < CORRECT_LEN; j += 8){
        a = 0;
        power = 0;
        i = 7;
        for (m = 0;m <= i;m++){
            temp[m] = str[j+m];
        }
        for (;i >= 0;i --){
            a += (temp[i] == '0'? 0 : 1)*pow(2,power);
            power ++;
        }
        printf("%d",a);
        if (j == 24)
            putchar('\n');
        else
            putchar(DOT);
    }

}
