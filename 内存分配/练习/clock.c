#include <stdio.h>
#include <time.h>
#include <stdbool.h>
// #include <unistd.h>  // 可以运行，但会提示警告，需要配置
#include <windows.h>
#include <conio.h> // Windows 特有头文件

int main()
{
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8
    // （从1970年1月1日开始的秒数）
    time_t rawtime = 0; // 定义一个time_t类型变量，用于存储时间戳，初始化为0

    // 定义一个tm结构体指针
    struct tm *pTime = NULL; // 让指针指向空指针
    bool isRunning = true;

    printf("DIGITAL CLOCK\n");
    while (isRunning)
    {
        // 传入变量地址，时间会存入current_time(rawtime)
        time(&rawtime); // time函数返回当前时间的时间戳，需要传入一个指针(地址),该指针用于存储时间戳
        // pTime = localtime(&rawtime); // 将时间戳转换为本地时间
        // printf("%ld\n", rawtime);
        pTime = localtime(&rawtime); // 将时间戳转换为本地时间,该函数返回一个指向tm结构体的指针
        // 进行赋值操作后，pTime将指向该tm结构体

        // "\r" 表示光标回到行首
        //   printf("\r%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
        //  printf("-------------------");
        printf("\r当前时间：%d年%d月%d日 %d:%d:%d",
               pTime->tm_year + 1900, // 年份从1900开始计算
               pTime->tm_mon + 1,     // 月份范围0-11
               pTime->tm_mday,
               pTime->tm_hour,
               pTime->tm_min,
               pTime->tm_sec);
        // if (kbhit())
        // { // 注意：kbhit() 是 Windows 特有
        //     if (getchar() == '\n')
        //     {
        //         isRunning = false; // 按下 Enter 退出循环
        //     }
        // }
        fflush(stdout); // 强制刷新输出缓冲区

        if (_kbhit())
        { // 检测键盘输入
            if (_getch() == '\r')
            { // Enter 键的 ASCII 码是 \r
                isRunning = false;
            }
        }
        /*  程序会被卡住
        if (getchar() == '\n')
        {
            break;
        }
        */

        Sleep(1000); // 用于Windows
        // sleep(1); // 用于Linux
    }
    printf("program end\n");
    return 0;
}