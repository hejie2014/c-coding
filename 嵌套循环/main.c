#include <stdio.h>

void print_multiplication_table_reverse(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            char buf[16];
            sprintf(buf, "%d * %d = %2d", j, i, j * i);
            printf("%12s", buf); // 每个表达式宽度12
        }
        printf("\n");
    }
}
void print_multiplication_table(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char buf[16];
            sprintf(buf, "%d * %d = %2d", j, i, j * i);
            printf("%12s", buf); // 每个表达式宽度12
        }
        printf("\n");
    }
}
int main()
{
    print_multiplication_table(9);
    printf("-----------------------------------\n");
    print_multiplication_table_reverse(9);
    return 0;
}

// #include <stdio.h>

// int main()
// {
//     for (int i = 1; i < 10; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             // 每个表达式宽度固定，用%2d和%2d，表达式之间用2个空格分隔
//             printf("%2d *%2d =%2d  ", j, i, j * i);
//         }
//         printf("\n");
//     }

//     return 0;
// }

// int main()
// {

//     for (int i = 1; i < 10; i++)
//     {

//         for (int j = 1; j <= i; j++)
//         {

//             printf("%2d * %2d = %2d\t", j, i, j * i);
//         }
//         printf("\n");
//     }

//     return 0;
// }