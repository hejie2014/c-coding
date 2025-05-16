#include <stdio.h>
#include <windows.h>

void drawPyramid(int rows)
{
    int i, j, space;

    for (i = 1; i <= rows; i++)
    {
        // 打印空格
        for (space = 1; space <= rows - i; space++)
        {
            printf(" ");
        }

        // 打印星号
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }

        // 换行
        printf("\n");
    }
}
void drawHollowPyramid(int rows)
{
    int i, j, space;

    for (i = 1; i <= rows; i++)
    {
        // 打印空格
        for (space = 1; space <= rows - i; space++)
        {
            printf(" ");
        }

        // 打印星号
        for (j = 1; j <= 2 * i - 1; j++)
        {
            // j值为1和2*i-1时打印星号，或者i等于rows时打印星号
            // 也就是最后一行的星号都打印出来
            // 其他位置打印空格，j == 1 || j == 2 * i - 1，打印第一个和最后一个星号
            // 当 i == rows 时，条件一直成立，所以最后一行的星号都打印出来
            if (j == 1 || j == 2 * i - 1 || i == rows)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}
int main()
{

    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8
    int rows = 0;
    int rows_hollow = 0;

    printf("请输入金字塔的行数: ");
    scanf("%d", &rows);

    printf("请输入空心金字塔的行数: ");
    scanf("%d", &rows_hollow);

    printf("金字塔图案:\n");
    drawPyramid(rows);

    printf("\n空心金字塔图案:\n");
    drawHollowPyramid(rows_hollow);
    return 0;
}
