#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node * prev;
    struct node * next;
} Node;

typedef Node * Loop;

void creat_loop(Loop *,int);
void coperate(Loop,int,int,int);
void delete_node(Node *);

int main(int argc, char const *argv[]) {
    int n,m,k;
    Loop loop;

    printf("input n m k(format 10 5 5):");
    scanf("%d%d%d",&n,&m,&k);
    creat_loop(&loop,n);
    coperate(loop,n,m,k);

    return 0;
}

void creat_loop(Loop * ploop,int n){
    Node * temp;
    *ploop = (Node *)malloc(sizeof(Node));
    temp = *ploop;
    temp -> num = 1;
    for(int i = 2;i <= n;i ++){
        temp -> next = (Node *)malloc(sizeof(Node));
        temp -> next -> prev = temp;
        temp = temp -> next;
        temp -> num = i;
    }
    temp -> next = *ploop;
    (*ploop) -> prev = temp;
}


void coperate(Loop loop,int n,int m,int k){
    Node * temp = loop,* temp_1;
    k = k - 1;
    int i,j;

    while(temp -> num != k)
        temp = temp -> next;

    for(i = 0;i < n;i ++){
        for(j = 0;j < m;j ++)
            temp = temp -> next;
        delete_node(temp);
    }
    putchar('\n');
}

void delete_node(Node * pnode){
    pnode -> next -> prev = pnode -> prev;
    pnode -> prev -> next = pnode -> next;
    printf("%d ",pnode -> num);
    free(pnode);
}
