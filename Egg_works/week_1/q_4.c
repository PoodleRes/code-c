#include <stdio.h>
#define TREE_ARGS 9
#define TREE_FLOOR 3

void show_space(int);
void show_star(int);
void show_tree(void);
void show_trangle(int,int);
void show_rect(int,int);

int main(void) {

    //ugly tree emmmm.
    show_tree();

    return 0;
}


void show_space(int x){
    for(int i = 0;i < x;i ++)
        putchar(' ');
}

void show_star(int x){
    for(int i = 0;i < x;i ++)
        putchar('*');
}

void show_trangle(int x,int num){
    for(int i = x / 2;i >= num;i --){
        show_space(i);
        show_star(x - i * 2);
        putchar('\n');
    }
}

void show_tree(void){//x is odd
    int x = TREE_ARGS;
    int num =  TREE_FLOOR;
    while(num -- > 0)
        show_trangle(x,num);
    show_rect(x,x/2+1);
}

void show_rect(int x,int y){
    for(int i = 0;i < y; i++){
        show_space(x / 2 - 1);
        show_star(3);
        putchar('\n');
    }
    show_star(x);
    putchar('\n');
    show_star(x);
    putchar('\n');
}
