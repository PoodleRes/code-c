#include <stdio.h>

int day_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int full_year(int);

int main(int argc, char const *argv[]) {
    int year,month,day,i,res = 0;
    scanf("%d/%d/%d",&year,&month,&day);
    for(i = 0;i < month - 1;i ++)
        res += day_month[i];
    res += day;
    if(full_year(year) && month > 2)
        res += 1;
    printf("%d\n",res);
    return 0;
}

int full_year(int year){
    return (year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0));
}
