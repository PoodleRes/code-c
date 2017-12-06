#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i,n,temp1 = 1,temp2 = 1,temp;
    scanf("%d", &n);
    if(n == 1)
        printf("%d",temp1);
    else if(n == 2)
        printf("%d",temp2);
    else{
        for(i = 2;i < n;i ++){
            temp = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp;
        }
        printf("%d",temp);
    }

    return 0;
}
