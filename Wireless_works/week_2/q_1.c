#include <stdio.h>

int get_kinds(int);

int main(void) {
    int m,kinds;
    printf("Input M:");
    scanf("%d",&m);
    kinds = get_kinds(m);
    printf("Kinds:%d\n",kinds);

    return 0;
}

int get_kinds(int m){
    if (m == 1)
        return 0;
    else if (m == 2)
        return 1;
    else if (m == 3)
        return 2;
    else if (m > 3)
        return get_kinds(m - 1) + get_kinds(m - 2);
    else
        printf("Error Floor!");
        return 0;
}
