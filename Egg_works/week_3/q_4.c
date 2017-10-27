#include <stdio.h>
#include <string.h>

#define LEN 11

_Bool is_right(const char *);
char * s_gets(char *,int);
_Bool can_be_right(const char *);

int main(void){
    char str[LEN];
    s_gets(str,LEN);
    if(*str){
        if(can_be_right(str))
            puts("Yes");
        else
            puts("No");
    }else{
        puts("Empty String");
    }

    return 0;
}

_Bool is_right(const char * str){
    int i,j;
    for(i = 0,j = strlen(str) - 1;i < strlen(str);i ++,j --)
        if(str[i] != str[j])
            return 0;
    return 1;
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

_Bool can_be_right(const char * str){
    char temp[LEN + 1];
    int i,j,k,x;
    char ch;
    for(i = 0;i < strlen(str);i ++){
        ch = str[i];
        for(j = 0;j <= strlen(str);j ++){
            for(k = 0,x = 0;k <= strlen(str);){
                if(k == j){
                    temp[k] = ch;
                    k ++;
                }else{
                    temp[k] = str[x];
                    k ++;
                    x ++;
                }
            }
            temp[k] = '\0';
            if(is_right(temp))
                return 1;
        }
    }

    return 0;
}
