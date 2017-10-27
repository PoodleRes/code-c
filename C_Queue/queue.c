#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void AddItem(Item item,Node * pnode){
    pnode -> item = item;
}

static void CopyToItem(Item * pitem,Node * pnode){
    * pitem = pnode -> item;
}

void InitializeQueue(Queue * qp){
    qp -> head = NULL;
    qp -> last = NULL;
    qp -> size = 0;
}

bool QueueIsFull(const Queue * qp){
    return qp -> size == MAXLENGTH;
}

bool QueueIsEmpty(const Queue * qp){
    return qp -> size == 0;
}

unsigned int QueueSize(const Queue * qp){
    return qp -> size;
}

bool EnQueue(Item item,Queue * qp){
    Node * pnode;

    if(QueueIsFull(qp))
        return false;
    pnode = (Node *)malloc(sizeof(Node));
    if(pnode == NULL){
        fprintf(stderr, "No available memory!\n");
        exit(EXIT_FAILURE);
    }
    AddItem(item,pnode);
    pnode -> next = NULL;
    if(QueueIsEmpty(qp))
        qp -> head = pnode;
    else
        qp -> last -> next = pnode;
    qp -> last = pnode;
    qp -> size ++;

    return true;
}

bool DeQueue(Item * pitem,Queue * qp){
    if(QueueIsEmpty(qp))
        return false;
    Node * temp = qp -> head;
    CopyToItem(pitem,qp -> head);
    qp -> head = qp -> head -> next;
    free(temp);
    qp -> size --;
    if (QueueIsEmpty(qp))
        qp -> last = NULL;
    return true;
}

void EmptyQueue(Queue * qp){
    Item item;
    while (DeQueue(&item,qp))
        continue;
}
