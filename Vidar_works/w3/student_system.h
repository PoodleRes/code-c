#ifndef _STUDENT_SYSYTEM_
#define _STUDENT_SYSYTEM_

#define NAME_LEN 50
#define INFO_LEN 100
#define STUDENT_NUM 100

#include <stdio.h>

typedef struct node{
    char name[50];
    int math;
    int chinese;
    struct node * next;
} Node;

char * read_file(FILE *);
char * read_file(FILE * fp){


    return str;
}

void show_all(FILE *);
void show_all(FILE * fp){

}

#endif
