#include "work.h"
void work_1(void){
    printf("Count the circle:Area and Round.\n");
    int r;
    scanf("%d",&r);
    printf("S:%.2f C:%.2f\n",M_PI*r*r,r*M_PI);
}

void work_2(void){
    printf("Count the char in string:stdin.\n");
    char str[LEN],ch;
    int up_case = 0,low_case = 0,num = 0,symbol = 0;
    size_t i = 0;
    scanf("%s",str);
    while (ch = str[i]) {
        if('A' <= ch && ch <= 'Z')
            up_case ++;
        else if('a' <= ch && ch <= 'z')
            low_case ++;
        else if('0' <= ch && ch <= '9')
            num ++;
        else
            symbol ++;
        i ++;
    }
    printf("Lower_case:%d\nUpper_case:%d\nNumber    :%d\nSymbol    :%d\n",low_case,up_case,num,symbol);
}

void work_3(void){
    printf("Sort the interge array.\n");
    int arr[ARRLEN];
    for(size_t i = 0;i < ARRLEN;i ++)
        scanf("%d",&arr[i]);

    sort_output(arr);
}

void work_4(void){
    printf("Year/Month/Day:\n");
    int month,day,days_to_zero= 0,weekday = COUNT_WEEK;
    long long int year;
    unsigned long long int days_to_count = 0;
    scanf("%d/%d/%d",&year,&month,&day);
    _Bool leap_year = ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0;
    for(int i = 0;i < month - 1;i ++)
        days_to_zero += MONTHDAY[i];
    if(leap_year && (month >= 3))
        days_to_zero += 1;
    days_to_zero += day;
    //WEEKDAY count from 2017/1/1 1 Saturday
    if (year >= COUNT_YEAR){
        for(long long int i = year;i > COUNT_YEAR;i --)
            days_to_count += year_day(i);
        days_to_count += days_to_zero;
        weekday += (days_to_count - 1) % WEEK;
        weekday %= WEEK;
    }else{
        for(long long int i = year;i < COUNT_YEAR;i ++)
            days_to_count += year_day(i);
        days_to_count -= days_to_zero - 1;
        weekday -= days_to_count % WEEK;
    }
    printf("%d %s\n",days_to_zero,NAME[weekday]);




}

int year_day(int year){
    _Bool leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    return leap_year?YEARDAY+1:YEARDAY;
}

void sort_output(const int * arr){
    int arrcp[ARRLEN];
    for(int i = 0;i < ARRLEN;i ++)
        arrcp[i] = arr[i];
    for(int i = 0;i < ARRLEN - 1;i ++)
        for(int j = 0;j < ARRLEN - 1 - i;j ++)
            if(arrcp[j] > arrcp[j + 1]){
                arrcp[j] ^= arrcp[j + 1];
                arrcp[j + 1] ^= arrcp[j];
                arrcp[j] ^= arrcp[j + 1];
            }
    for(int i = 0;i < ARRLEN;i ++)
        printf("%d ",arrcp[i]);
    putchar('\n');
}
