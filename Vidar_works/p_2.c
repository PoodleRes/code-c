#include <stdio.h>

void show_char(int,char);
void show_trapezoid(int);
void show_x(int);
void get_num(int *);

int main(void){
    int n;

    get_num(&n);
    show_trapezoid(n);
    get_num(&n);
    show_x(n);

    return 0;
}

void get_num(int * np){
    printf("input n:");
    while(scanf("%d",np) != 1){
        fprintf(stderr, "GG retry:\n");
        while(getchar() != '\n')
            continue;
    }
}

void show_char(int num,char c){
    int i;
    for(i = 0;i < num;i ++)
        putchar(c);
}

void show_trapezoid(int n){
    int i;

    show_char(n-1,' ');
    show_char(n,'*');
    putchar('\n');
    for(i = n - 2;i > 0;i --){
        show_char(i,' ');
        putchar('*');
        show_char((n - i - 2) * 2 + n,' ');
        putchar('*');
        putchar('\n');
    }
    show_char(3 * n - 2,'*');
    putchar('\n');
}

void show_x(int n){
    int i;

    for(i = n;i >= 0;i --){
        show_char(n - i,' ');
        if(i != 0){
            putchar('*');
            show_char(2 * i - 1,' ');
            putchar('*');
        }else{
            putchar('*');
        }
        putchar('\n');
    }

    for(i = 1;i < n;i ++){
        show_char(n - i,' ');
        putchar('*');
        show_char(2 * i - 1,' ');
        putchar('*');
        putchar('\n');
    }
}
