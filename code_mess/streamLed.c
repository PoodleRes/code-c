#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);
    if(!(n % 3) && !(n % 5))
        printf("Yes");
    else
        printf("No");
    return 0;
}
