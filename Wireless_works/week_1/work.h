#ifndef _WORK_H_
#define _WORK_H_

#include <stdio.h>
#include <math.h>
#include <limits.h>
#define LEN 128
#define ARRLEN 10
#define MON 12
#define WEEK 7
#define LIM_WEEK 15
#define YEARDAY 365
#define COUNT_YEAR 2017
#define COUNT_MON 1
#define COUNT_DAY 1
#define COUNT_WEEK 6

static const int MONTHDAY[MON] = {31,28,31,30,31,30,31,31,30,31,30,31};
static const char  NAME[WEEK][LIM_WEEK] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Sunday","Saturday"};

void sort_output(const int *);
int year_day(int);
void work_1(void);
void work_2(void);
void work_3(void);
void work_4(void);

#endif
