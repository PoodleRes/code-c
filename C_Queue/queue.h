#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>
#define MAXLENGTH 10

typedef int Item;

typedef struct node{
    Item item;
    struct node * next;
} Node;

typedef struct queue{
    Node * head;
    Node * last;
    unsigned int size;
} Queue;//Queue -> head is (Node *)

void InitializeQueue(Queue *);
bool QueueIsFull(const Queue *);
bool QueueIsEmpty(const Queue *);
unsigned int QueueSize(const Queue *);
bool EnQueue(Item,Queue *);
bool DeQueue(Item *,Queue *);
void EmptyQueue(Queue *);

#endif
