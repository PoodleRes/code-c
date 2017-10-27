#include <stdio.h>

#define MON 12
#define WEEK 7
#define LIM_WEEK 15
#define YEARDAY 365
#define COUNT_YEAR 2017
#define COUNT_MON 1
#define COUNT_DAY 1
#define COUNT_WEEK 6

static const int MONTHDAY[MON] = {31,28,31,30,31,30,31,31,30,31,30,31};
static const char  NAME[WEEK][LIM_WEEK] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
int year_day(int);
int get_week(void);
void showhead(int);
void show(int);
void star(int);
void space(int);
int showbody(int,int);
int main(void){
    int weekday = get_week();
    show(weekday);
    return 0;
}


void showhead(int n){
    star(115);
    putchar('\n');
    putchar('*');
    printf("%19d%19c%19d%19c%19d%19c\n",n,'*',n+1,'*',n+2,'*');
    putchar('*');
    for(int i = 0; i< 3;i ++){
        printf("%5s%5s%5s%5s%5s%5s%5s",NAME[0],NAME[1],NAME[2],NAME[3],NAME[4],NAME[5],NAME[6]);
        putchar(' ');
        putchar(' ');
        putchar('*');
    }
    putchar('\n');
}

void show(int weekday){
    showhead(1);
    weekday = showbody(1,weekday);
    showhead(4);
    weekday = showbody(4,weekday);
    showhead(7);
    weekday = showbody(7,weekday);
    showhead(10);
    weekday = showbody(10,weekday);
    star(115);
    putchar('\n');
}

int showbody(int mon,int weekday){
    int a = 1,b = 1,c = 1,temp,line = 1,p,record = weekday;

    while (line <= 6){
        putchar('*');
        for(int k = mon - 1;k < mon + 2 ;k++){
            if ((k + 1) % 3 == 1)
                temp = a;
            else if ((k + 1) % 3 == 2)
                temp = b;
            else
                temp = c;
            if (line == 1){
                for(int i = 0;i < weekday;i ++)
                    space(5);
                p = weekday;
            }else
                p = 0;
            for(int i = COUNT_WEEK;i >= p;i --,temp ++){
                if(temp <= MONTHDAY[k])
                    printf("%5d",temp);
                else
                    space(5);
            }
            if ((k + 1) % 3 == 1)
                a = temp;
            else if ((k + 1) % 3 == 2)
                b = temp;
            else
                c = temp;
            putchar(' ');
            putchar(' ');
            putchar('*');
            weekday = (MONTHDAY[k]  + weekday) % WEEK;
            record += MONTHDAY[k];
        }
        putchar('\n');
        line ++;
    }
    return record % WEEK;
}

void star(int n){
    for(int i = 0; i < n;i ++)
        putchar('*');
}

void space(int n){
    for(int i = 0; i < n;i ++)
        putchar(' ');
}

int year_day(int year){
    _Bool leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    return leap_year?YEARDAY+1:YEARDAY;
}
int get_week(void){
    printf("Year:");
    int month = 1,day = 1,days_to_zero= 0,weekday = COUNT_WEEK;
    int year;
    unsigned int days_to_count = 0;
    scanf("%d",&year);
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
    return weekday;
}
