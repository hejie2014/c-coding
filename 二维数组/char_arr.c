#include <stdio.h>
#include <string.h>

int main()
{

    char fruits[3][10] = {"apple",
                          "banana",
                          "orange"};
    printf("apple: %d\n", strlen(fruits[0]) - 1);  // apple
    printf("banana: %d\n", strlen(fruits[1]) - 1); // banana
    printf("orange: %d\n", strlen(fruits[2]) - 1); // orange

    fruits[0][0] = 'e';                     // 可以直接修改字符数组中的单个字符
    fruits[0][strlen(fruits[0]) - 1] = 'a'; // 可以直接修改字符数组中的单个字符

    fruits[1][0] = 'a';                     // 可以直接修改字符数组中的单个字符
    fruits[1][strlen(fruits[1]) - 1] = 'b'; // 可以直接修改字符数组中的单个字符

    fruits[2][0] = 'e';                     // 可以直接修改字符数组中的单个字符
    fruits[2][strlen(fruits[2]) - 1] = 'o'; // 可以直接修改字符数组中的单个字符

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", fruits[i]);
    }
    // fruits[0] = "pear"; // 错误，不能直接赋值,他是指针
    printf("\n-----------\n"); // apple
    strcpy(fruits[0], "pear"); // 正确，使用 strcpy 函数复制字符串
                               //  printf("%s\n", fruits[0]); // pear
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", fruits[i]);
    }
    return 0;
}