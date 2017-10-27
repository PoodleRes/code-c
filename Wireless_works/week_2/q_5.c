#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
int s_gets(char *,int);
void search(const char *,int,int);

int main(void) {
    char str[LEN];
    int son_len;
    puts("Input a string");
    int len = s_gets(str,LEN);
    puts("Input a son_length:");
    scanf("%d",&son_len);
    if(len == 0){
        fprintf(stderr, "Error String Length.\n");
        exit(EXIT_FAILURE);
    }
    if(son_len > len){
        fprintf(stderr, "Length Error.\n");
        exit(EXIT_FAILURE);
    }
    search(str,len,son_len);
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

void search(const char * str,int len ,int son_len){

    char set[len - son_len + 1][son_len + 1];
    int record[len - son_len  + 1],max = 0,output[len - son_len  + 1];
    for(int i = 0; i < len -son_len; i++){
        record[i] = 0;
        output[i] = 0;
    }
    for(int i = 0; i < len -son_len; i++){
        for(int j = 0;j < son_len;j ++){
            set[i][j] = str[i + j];
        }
        set[i][son_len] = '\0';
    }
    for(int i = 0;i < len - son_len; i++){
        for(int j = 0;j < len - son_len; j++){
            if(!strcmp(set[i],set[j]))
                record[i] += 1;
        }
        if (record[i] > max)
            max = record[i];
    }
    for(int i = 0;i < len - son_len; i++){
        if (record[i] == max){
            for (int j = i + 1;j < len - son_len;j ++){
                if (!strcmp(set[i],set[j]))
                    record[j] = 0;
            }
        }
    }
    for(int i = 0;i < len - son_len; i++){
        if (record[i] == max){
            printf("%s ", set[i]);
        }
    }
    putchar('\n');
}
