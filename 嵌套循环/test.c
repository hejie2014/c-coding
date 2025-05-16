#include <stdio.h>

int main()
{

    int rows = 0;
    int columns = 0;
    char symbol = '\0';

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);
    printf("Enter the symbol to use: ");
    scanf(" %c", &symbol); // 跳过空格和换行符

    for (int i = 0; i < rows; i++)
    {
        int spaces = rows - i - 1; // 计算空格数,空格数不需要在减1了，因为i值每个循环会自动加1，也就是变相的减1.
        // 打印空格
        for (int k = 0; k < spaces; k++)
        {
            printf(" ");
        }

        // 打印符号
        for (int j = 0; j < columns - 2 * spaces; j++)
        {
            printf("%c", symbol);
        }
        printf("\n");
    }

    return 0;
}