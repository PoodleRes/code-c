#include <stdio.h>

const char * Month[12] = {"January","February","March","April","May",
                        "June","July","August","September","October",
                        "Novermber","December"};

int main(void) {
    int n;
    printf("Input a num to show Month:");
    if(scanf("%d",&n) == 1 && (1 <= n && n <= 12)){
        puts(Month[n - 1]);
    }else{
        fprintf(stderr, "Oops!Error input!\n");
    }
    return 0;
}
