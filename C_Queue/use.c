#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char const *argv[]) {
    Item item;
    Queue temp;
    puts("Input Int Num:");
    InitializeQueue(&temp);
    while (!QueueIsFull(&temp) && scanf("%d",&item) == 1 ) {
        while(getchar() != '\n')
            continue;
        EnQueue(item,&temp);
        puts("Input next Num:");
    }
    while (DeQueue(&item,&temp)) {
        printf("Item : %d\n",item);
    }
    EmptyQueue(&temp);

    return 0;
}
