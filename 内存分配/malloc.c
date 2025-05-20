#include <stdio.h>
#include <stdlib.h>
int main()
{

    // 定义我们需要分配的内存空间
    int number = 0;
    printf("Enter the number of grades: ");
    scanf("%d", &number);

    // 分配内存空间
    /* malloc 返回 void* 类型，C语言允许将 void* 隐式转换为其他指针类型（如 char*），因此无需强制转换。

    如果忘记包含 <stdlib.h>，malloc 的返回值会被假定为 int（而非 void*），此时：

     1. 无强制转换：编译器会直接报错（类型不匹配）。
     2. 有强制转换：强制转换会掩盖错误，可能导致未定义行为。

     char *grades = malloc(number * sizeof(*grades));
     使用 sizeof(*grades) 替代 sizeof(char)。
     1. 优点：如果后续修改指针类型（如改为 int*），无需手动调整 sizeof 参数。
     2. 原理：sizeof(*grades) 会根据指针类型自动计算大小。
     3. 可以简化为sizeof(*grades)，因为grades是char*类型，*grades就是char，所以sizeof(char)和sizeof(*grades)是等价的。
    */
    char *grades = malloc(number * sizeof(char));

    // 判断内存是否分配成功,如果分配失败(malloc返回NULL)，打印错误信息,
    if (grades == NULL)
    {

        printf("Memory allocation failed!\n");
        return 1;
    }
    // 为内存空间进行赋值
    for (int i = 0; i < number; i++)
    {
        printf("Enter grade #%d: ", i + 1);
        scanf(" %c", &grades[i]); // 跳过空格和换行符,并将输入的字符赋值给grades[i],可以使用下标访问
    }
    // 打印数据

    for (int i = 0; i < number; i++)
    {
        printf("Grade #%d: %c\n", i + 1, grades[i]);

        if (i % 6 == 5)
        {
            printf("\n");
            // 当我们需要没打印 n行数据 可以使用 i % N  == (N - 1)
            // i % 3 == 0, 会在打印第1个数进行换行，使用 (i % 3 == 2)
            /*
                Grade #1: e

                Grade #2: e
                Grade #3: e
                Grade #4: e
            */
        }
    }
    // 释放内存空间
    free(grades);
    // 将指针设置为NULL，避免悬空指针
    grades = NULL;

    return 0;
}