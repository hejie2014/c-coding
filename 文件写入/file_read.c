#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(65001);                                         // 设置控制台输出为UTF-8
    FILE *pFile = fopen("C:\\Users\\peace\\Desktop\\output.txt", "r"); // 打开文件, "r" 为读取模式
    char buffer[1024] = {0};                                           // 定义缓冲区

    // 文件读取，判断是否正确读取文件
    if (pFile == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // 使用while循环逐行读取文件，直到文件末尾，就是pFile指针指向NULL
    while (fgets(buffer, sizeof(buffer), pFile) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(pFile); // 关闭文件

    return 0;
}