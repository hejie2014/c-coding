#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8

    // 判断时间是上午还是下午
    int hour = 11;
    int minute = 30;
    printf("%d:%d %s\n", hour, minute, (hour < 12) ? "AM: 上午" : "PM: 下午");

    hour = 11;
    minute = 3;
    printf("%d:%d %s\n", hour, minute, (hour < 12) ? "AM: 上午" : "PM: 下午");

    // 调整格式
    printf("%02d:%02d %s\n", hour, minute, (hour < 12) ? "AM: 上午" : "PM: 下午");

    hour = 12;
    minute = 3;
    printf("%02d:%02d %s\n", hour, minute, (hour < 12) ? "AM: 上午" : "PM: 下午");

    return 0;
    /*    三元表达式
    int x = 5;
    int y = 6;
    int max = x > y ? x : y;

    printf("max = %d\n", max);

    x = 7;
    y = 6;
    max = x > y ? x : y;
    printf("max = %d\n", max);
    return 0;
    */

    /*   布尔值
    bool isOnline = true;
    printf("%s\n", isOnline ? "Online" : "Offline");

    isOnline = false;
    printf("%s\n", isOnline ? "Online" : "Offline");

    return 0;
    */

    /*
        // 判断一个数的奇偶性
    int num = 3;
    printf("%d: %s\n", num, num % 2 == 0 ? "even: 偶数" : "odd: 奇数");

    num = 8;
    printf("%d: %s\n", num, num % 2 == 0 ? "even: 偶数" : "odd: 奇数");

    return 0;

    */

    /*
        // 判断年龄

    int age = 20;
    printf("%s\n", (age >= 18) ? "adult: 成年" : "child: 未成年");

    age = 15;
    printf("%s\n", (age >= 18) ? "adult: 成年" : "child: 未成年");
    return 0;
    */
}