#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i;
    double s;
    scanf("%3d%*d%6lf",&i,&s);
    printf("%d %lf",i,s);
    return 0;
}
