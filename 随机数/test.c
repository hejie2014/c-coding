#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(NULL)); // 设置随机数种子

    int guess = 0;     // 用户猜测的数字
    int gameCount = 0; // 游戏次数
    int min = 1;
    int max = 100;
    int answer = (rand() % (max - min + 1)) + min; // 生成一个范围在1到100之间的随机数

    printf("*** 欢迎来到猜数字游戏！***\n");
    printf("*** Number Guessing Game ***\n");
    // 使用 do-while 循环来实现，先执行一次循环体，然后再判断条件
    do
    {
        printf("Guess a number between %d - %d: ", min, max);
        scanf("%d", &guess);
        gameCount++;
        if (guess < min || guess > max)
        {
            printf("number out of range!\n");
            continue;
        }
        if (guess < answer)
        {
            printf("too low!\n");
        }
        else if (guess > answer)
        {
            printf("too high!\n");
        }
        else
        {
            printf("Congratulations!You took %d attempts.\n", gameCount);
        }

    } while (guess != answer);

    //     if (guess < min || guess > max)
    //     {
    //         printf("输入的数字不在范围内，请重新输入！\n");
    //         continue;
    //     }

    //     if (guess < answer)
    //     {
    //         printf("你猜的数字小了！\n");
    //     }
    //     else if (guess > answer)
    //     {
    //         printf("你猜的数字大了！\n");
    //     }
    //     else
    //     {
    //         printf("恭喜你，猜对了！你总共猜了 %d 次。\n", gameCount);
    //         break;
    //     }
    // }
    printf("随机数是：%d\n", answer);
    printf("游戏结束，谢谢参与！\n");
    return 0;
}