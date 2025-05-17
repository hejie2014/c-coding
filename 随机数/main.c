#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int min = 1;
    int max = 10;
    // 设置随机数种子
    srand(time(NULL));

    // 生成随机数 (0~ max-min+1),加上偏移量min，(min ~ max + 1),再结合取余,就是 （min ~ max）

    int randomNum1 = (rand() % (max - min + 1)) + min; // 生成一个范围在1到10之间的随机数
    int randomNum2 = (rand() % (max - min + 1)) + min;
    int randomNum3 = (rand() % (max - min + 1)) + min;

    printf("随机数1: %d\n", randomNum1);
    printf("随机数2: %d\n", randomNum2);
    printf("随机数3: %d\n", randomNum3);

    //   printf("%d", rand()); // 生成一个随机数(41)

    //   printf("%d\n", rand() % 100); // 生成一个0-99之间的随机数

    // printf("%d\n", RAND_MAX); // 生成一个0到RAND_MAX之间的随机数(32767)

    return 0;
}