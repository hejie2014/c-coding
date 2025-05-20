#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    printf("Enter the number of prices: ");
    scanf("%d", &number);

    // 分配内存空间
    float *prices = malloc(number * sizeof(*prices));
    // 判断内存是否分配成功,如果分配失败(malloc返回NULL),打印错误信息,退出程序。
    if (prices == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 为内存空间进行赋值
    for (int i = 0; i < number; i++)
    {
        printf("Enter price #%d: ", i + 1);
        scanf("%f", &prices[i]);
    }
    printf("--------realloc-----------\n");

    int newNumber = 0;
    printf("Enter a new number of prices: ");
    scanf("%d", &newNumber);

    float *temp = realloc(prices, newNumber * sizeof(*temp));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
    }
    else
    {
        prices = temp; // prices指向新的内存空间
        temp = NULL;   // 不使用temp时，设置指针为空，避免悬空指针

        // 为新的内存分配数据， 如果是增加数据，会进入for循环
        // 如果是减少数据，不会进入for循环，因为newNumber小于number，条件不成立；
        for (int i = number; i < newNumber; i++)
        {
            printf("Enter price #%d: ", i + 1);
            scanf("%f", &prices[i]);
        }
        // 打印数据
        for (int i = 0; i < newNumber; i++)
        {
            printf("$%.2f ", prices[i]);
        }
    }

    // 释放内存空间
    free(prices);
    // 设置指针为空，避免悬空指针
    prices = NULL;

    return 0;
}