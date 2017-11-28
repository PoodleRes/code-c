#include <stdio.h>
#define ARR_LEN 50
#define FLASH_TIME 30
#define START_DELAY 100
#define ON 255
#define OFF 0

int main(void) {
    int lighttime[ARR_LEN];
    int i,j;
    int times;
    for(i = 0;i < ARR_LEN;i ++)
        lighttime[i] = i;

    while(1){
        for(i = 0;i < ARR_LEN;i ++){
            for(j = 0;j < FLASH_TIME;j ++){
                LED = OFF;
                delay(START_DELAY - lighttime[i]);
                LED = ON;
                delay(lighttime[i]);
            }
        }
        for(i = ARR_LEN - 1;i >= 0 ;i --){
            for(j = 0;j < FLASH_TIME;j ++){
                LED = OFF;
                delay(START_DELAY - lighttime[i]);
                LED = ON;
                delay(lighttime[i]);
            }
        }
    }

    return 0;
}
