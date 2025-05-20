#include <stdio.h>
#include <stdlib.h>

int main()
{

    int number = 0;
    printf("Enter the number of plays: ");
    scanf("%d", &number);

    // 分配内存空间,malloc分配内存更快，但是可能包含垃圾值，calloc分配内存慢(导致错误较少，为每块内存进行初始值 0)，但是不包含垃圾值
    int *scores = calloc(number, sizeof(*scores));
    // 判断内存是否分配成功,如果分配失败(malloc返回NULL)，打印错误信息,退出程序。
    if (scores == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // 为内存空间进行赋值
    for (int i = 0; i < number; i++)
    {
        printf("Enter scores #%d: ", i + 1);
        scanf("%d", &scores[i]);
    }
    for (int i = 0; i < number; i++)
    {
        printf("%d ", scores[i]);
        if (i % 5 == 4)
            printf("\n");
        /*可能输出（提供一个默认值0）：
        Enter the number of plays: 10
            0 0 0 0 0 0 0 0 0 0
        */
    }

    // 释放内存空间
    free(scores);
    // 设置指针为空，避免悬空指针
    scores = NULL;

    return 0;
}

// int main()
// {

//     int number = 0;
//     printf("Enter the number of plays: ");
//     scanf("%d", &number);

//     // 分配内存空间
//     int *scores = malloc(number * sizeof(*scores));
//     // 判断内存是否分配成功,如果分配失败(malloc返回NULL)，打印错误信息,退出程序。
//     if (scores == NULL)
//     {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }
//     /*
//      // malloc分配的内存空间是未初始化的，可能包含垃圾值
//     for (int i = 0; i < number; i++)
//     {
//         printf("%d ", scores[i]);
//     }
//     可能输出（垃圾值）：
//     Enter the number of plays: 10
//         4980828 6488175 7077985 5242972 7274610
//         7471207 7143521 6029427 7077967 6357100
//     */

//     // 释放内存空间
//     free(scores);
//     // 设置指针为空，避免悬空指针
//     scores = NULL;

//     return 0;
// }