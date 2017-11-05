#include <stdio.h>

void right(int *);
void left_down(int *,int *);
void down(int *);
void right_up(int *,int *);

int main(int argc, char const *argv[]) {
    int n,i,j,k;
    _Bool turn_1,turn_2;
    puts("The num per col(row)?");
    scanf("%d",&n);
    //-std=c99
    int arr_arr[n][n];
    int arr[n * n];
    for(i = 0;i < n;i ++)
        for(j = 0;j < n;j ++)
            scanf("%d",&arr_arr[i][j]);
    i = 0;
    j = 0;
    k = 0;
    turn_1 = 1;// rihgt_up
    turn_2 = 0;// left_down
    while (k < n * n) {
        arr[k] = arr_arr[i][j];
        k ++;
        if(turn_1 && (i - 1 < 0 && j + 1 <= n -1)){
            right(&j);
            turn_1 = 0;
            turn_2 = 1;
        }else if(turn_1 && (j + 1 > n -1)){
            down(&i);
            turn_1 = 0;
            turn_2 = 1;
        }else if(turn_1 && (i - 1 >= 0 && j + 1 <= n - 1)){
            right_up(&j,&i);
        }else if(turn_2 && (i + 1 > n - 1)){
            right(&j);
            turn_1 = 1;
            turn_2 = 0;
        }else if(turn_2 && (j - 1 < 0)){
            down(&i);
            turn_1 = 1;
            turn_2 = 0;
        }else if(turn_2 && (i + 1 <= n - 1 && j - 1 >= 0)){
            left_down(&j,&i);
        }
    }
    for(i = 0;i < n * n;i ++)
        printf("%d ",arr[i]);
    putchar('\n');
    return 0;
}

void right(int * jp){
    (*jp) ++;
}
void left_down(int * jp,int * ip){
    (*jp) --;
    (*ip) ++;
}
void down(int * ip){
    (*ip) ++;
}
void right_up(int * jp,int * ip){
    (*jp) ++;
    (*ip) --;
}
