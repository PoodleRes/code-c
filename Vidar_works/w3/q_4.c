#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUT 100

typedef struct node{
    char name[50];
    int math;
    int chinese;
    struct node * next;
} Node;

typedef Node * First;

void welcome(void);
int get_str(char *,int);
int check_form(Node *,const char *,int);
int check_form(Node * np,const char * str,int mode){
    char * cp;
    if(mode == 1){
        char * prefix = "insert Name:";
        char * middle = "Math:";
        char * suffix = "Chinese:";
        while(1){
            if(*prefix != '\0')
                break;
            if(*cp == *prefix){
                cp ++;
                prefix ++;
            }else{
                return -1;
            }
        }
        if(get_str(np -> name,50) <= 0)
            return -1;
        


    }
}
int getinfo(char *);
int getinfo(char * str){
    char name_temp[50];
    printf("Insert>");
    while(1){
        if(get_str(str,MAX_INPUT + 1) > 0){
            if(str[0] == 'q')
                break;
            else

        }
    }

}


int main(int argc, char const *argv[]) {
    First frist;
    char temp[MAX_INPUT + 1];
    frist = (Node *)malloc(sizeof(Node));

    return 0;
}

void welcome(void){
    puts("1 -> Show all info.");
    puts("2 -> Insert new one.");
    puts("3 -> Delete one by name.");
    puts("4 -> Find one by name.");
    puts("5 -> Change one by name.");

}

int get_str(char * str,int len){
    int get_len = 0;
    char * sp = fgets(str,len,stdin);
    while(*sp != '\0' && *sp!='\n'){
        get_len ++;
        sp ++;
    }
    if(*sp == '\0'){
        while(getchar() != '\n')
            continue;
        return -1;
    }
    else
        *sp = '\0';
    return get_len;
}
