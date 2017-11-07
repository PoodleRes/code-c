#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int * make_next(const char *,int);
int kmp(const char *,int,const char *,int);
int get_str(char *,int);


int main(int argc, char const *argv[]) {
    char str[MAX],son[MAX];
    int len_str,len_son,status;
    puts("Get String:");
    len_str = get_str(str,MAX);
    puts("Want to search:");
    len_son = get_str(son,MAX);
    status = kmp(str,len_str,son,len_son);
    if(status == -1)
        printf("Not Found.\n");
    else
        printf("Index:%d\n",status);

    return 0;
}


int * make_next(const char * str,int len){
    int i,j;
    int * next;
    next = (int *)malloc(sizeof(int) * len);
    next[0] = 0;
    j = 0;
    for(i = 1;i < len;i ++){
        while(j > 0 && str[j] != str[i])
            j = next[j - 1];
        if(str[i] == str[j])
            j ++;
        next[i] = j;
    }
    return next;
}


int kmp(const char * str,int len_str,const char * son,int len_son){
    int * next = make_next(son,len_son);
    int i,j;
    i = 0;
    j = 0;

    while(i < len_str && j < len_son){
        if(str[i] == son[j]){
            i ++;
            j ++;
        }else{
            j = next[j];
            if(j == 0)
                i ++;
        }
    }
    free(next);
    if(j == len_son)
        return i - j;
    else
        return -1;

}


int get_str(char * str,int len){
    int get_len = 0;
    char * sp = fgets(str,len,stdin);
    while(*sp != '\0' && *sp!='\n'){
        get_len ++;
        sp ++;
    }
    if(*sp == '\0')
        while(getchar() != '\n')
            continue;
    else
        *sp = '\0';
    return get_len;
}
