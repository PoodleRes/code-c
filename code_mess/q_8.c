#include <stdio.h>

int main(int argc, char const *argv[]) {
    double input;
    char format;
    scanf("%c%lf",&format,&input);
    if(format == 'F')
        printf("C %.2lf\n",5.0 / 9 * (input - 32));
    if(format == 'C')
        printf("F %.2lf\n",input * 9.0 / 5 + 32);
    return 0;
}
