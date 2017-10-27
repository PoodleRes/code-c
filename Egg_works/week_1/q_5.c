#include <stdio.h>

int n = 0;
void swap(int *, int *);
void perm(int *, int, int);

int main(void){

    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    perm(list, 0, 8);
    printf("total:%d\n", n);

    return 0;
}

void swap(int *a, int *b){
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

void perm(int list[], int k, int m){
    if(k > m){
        if(list[0] * 100 + list[1] * 10 + list[2] * 1 +
           list[3] * 100 + list[4] * 10 + list[5] * 1 ==
           list[6] * 100 + list[7] * 10 + list[8] * 1){
            printf("%d%d%d + %d%d%d = %d%d%d", list[0],list[1],list[2],list[3],list[4],list[5],list[6],list[7],list[8]);
            printf("\n");
            n++;
        }
    }else{
        for(int i = k; i <= m; i++){
            swap(&list[k], &list[i]);
            perm(list, k + 1, m);
            swap(&list[k], &list[i]);
        }
    }
}
