#include <stdio.h>
#define MAX 10
#define TIMES 1000

int main(void){
    _Bool holes[MAX] = {0};//0 has rabbit
    int i,temp;
    temp = 0;
    for(int i = 1;i <= TIMES;i ++){
        holes[temp] = 1;
        temp = (temp + i) % MAX;
    }

    for(i = 0;i < MAX;i ++)
        if(holes[i] == 0)
            printf("Rabbit in hole %d.\n",i + 1);


    return 0;
}
