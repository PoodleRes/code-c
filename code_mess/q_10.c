#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n,i;
    double temp,sum,min,max,avg;
    scanf("%d",&n);
    for(i = 0;i < n;i ++){
        scanf("%lf",&temp);
        sum += temp;
        if(i == 0){
            min = temp;
            max = temp;
        }else{
            if(temp > max)
                max = temp;
            if(temp < min)
                min = temp;
        }
    }
    sum -= min + max;
    avg = sum / (n - 2);
    printf("%.2lf\n",avg);
    return 0;
}
