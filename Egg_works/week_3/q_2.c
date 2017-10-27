#include <stdio.h>

#define MAX 100

char * s_gets(char *,int);
char * s_copy(char *,const char *,int);

int main(void) {
    char src[MAX];
    char dst[MAX];
    int m;

    puts("Input String(MAX = 100):");
    s_gets(src,MAX);
    puts("Input Number m(No check from 1 to strlen):");
    scanf("%d",&m);
    s_copy(dst,src,m);
    puts(dst);

    return 0;
}

char * s_gets(char * str,int max){
    char * flag = fgets(str,max,stdin);
    while(*flag != '\n' && *flag != '\0')
        flag ++;
    if (*flag == '\n'){
        *flag = '\0';
    }else{
        while(getchar() != '\n')
            continue;
    }
    return str;
}

char * s_copy(char * dst,const char * src,int m){
    const char * no_null = src + m - 1;
    int i = 0;

    while (*no_null != '\0') {
        dst[i] = *no_null;
        i ++;
        no_null ++;
    }
    return dst;
}
