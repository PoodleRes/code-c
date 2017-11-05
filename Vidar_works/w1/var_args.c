#include <stdio.h>
#include <stdarg.h>
#define OUT(VA) VA

#define NUS(X,VA) X(OUT(VA))


int plus(int a,int b){
    return a + b;
}

int main(void){
    int n;
    //callany(scanf,"%d",&n);
    NUS(printf,"SS");
}
