#include <stdio.h>
#include <stdlib.h>
#define MAX (30+1)

int s_gets(char *,int);
void operate(const char *,int,int);

int main(void) {
    char str[MAX];
    int len;
    puts("Input some num(support char type):");
    if(len = s_gets(str,MAX));
    else{
        fprintf(stderr, "LengthError:Nothing input.\n");
        exit(EXIT_FAILURE);
    }
    operate(str,1,len);

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

void operate(const char * str,int start,int len){
    if (len == 1){
        putchar(*str);
        putchar('\n');
        return ;
    }
    char temp[len - (len + 1) / 2];
    int ti = 0;
    for(int i = 0;i < len;i ++){
        if((i + start) % 2 == 1){
            putchar(str[i]);
        }else{
            temp[ti] = str[i];
            ti ++;
        }
    }
    operate(temp,start + len - 1,len - (len + 1) / 2);
}
