#include <stdio.h>

/*
   动态分配内存：
    1. malloc()：分配指定大小的内存块，返回指向该内存块的指针。
    2. calloc()：分配指定数量的内存块，每个内存块大小为指定字节数，并初始化为0，返回指向该内存块的指针。
    3. realloc()：重新分配已分配的内存块的大小，返回指向新内存块的指针。
    4. free()：释放之前分配的内存块，防止内存泄漏。
    注意事项：
    1. malloc()和calloc()分配的内存块需要使用free()函数释放。
    2. realloc()函数可以用于扩展或缩小已分配的内存块的大小。
    3. 使用malloc()和calloc()分配的内存块是未初始化的，可能包含垃圾值。
    4. 使用free()函数释放内存后，指针仍然指向原来的地址，但该地址的内存已被释放，不能再访问。
    5. 使用malloc()和calloc()分配的内存块的大小是以字节为单位的。
    6. malloc()和calloc()函数返回的指针类型是void*，可以转换为任何类型的指针。
    7. malloc()和calloc()函数的返回值是NULL，表示分配内存失败。
    8. malloc()和calloc()函数的参数是unsigned int类型，表示要分配的内存块的大小。
    int rows = 3, cols = 3;
int **number = (int **)malloc(rows * sizeof(int *));
for (int i = 0; i < rows; i++) {
    number[i] = (int *)malloc(cols * sizeof(int));
}
// 初始化...
number[0][0] = 1; // 可以像二维数组一样访问
// 释放内存...
for (int i = 0; i < rows; i++) {
    free(number[i]);
}
free(number);

*/

int main()
{
    /*
      1. 二维数组声明时，第二维（列数）必须指定。
      2. 第一维（行数）可以省略，由初始化时的行数自动推断。
      3. 这是 C 语言的语法规定，目的是让编译器能正确计算每个元素的内存地址。
      4. 地址 = 基地址 + (i * 列数 + j) * sizeof(int).要访问 arr[i][j]
      i * 列数----可以跳到下一行的首地址
    */
    int number[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int *p = number[0];                                       // 指向一维数组的首地址
    int *p1 = number[1];                                      // 指向第二行的首地址
    int *p2 = number[2];                                      // 指向第三行的首地址
    printf("%d\n", sizeof(number[0]) / sizeof(number[0][0])); // 3
    printf("%d\n", sizeof(number) / sizeof(number[0]));       // 3

    for (int i = 0; i < 3; i++)
    {
        printf("%p ", p); // 1 4 7
        printf("%d \n", *p);
        p++;
    }
    printf("\n-------------------\n");
    printf("%d\n", number[0][0]);         // 1
    printf("%d\n", *number[0]);           // 1
    printf("%d\n", **number);             // 1
    printf("%d\n", *(number[0] + 1));     // 2
    printf("%d\n", *(*(number + 1) + 1)); // 5  等价于 number[1][1]， *(number[1] + 1))
    printf("%d\n", *(*(number + 2) + 2)); // 9  等价于 number[2][2]， *(number[2] + 2))
    printf("------------------\n");
    printf("%d\n", *(number[1] + 1)); // 5
    printf("%d\n", *(number[2] + 2)); // 9
    printf("%p\n", number);           // 3
    printf("%p\n", number[0]);        // 1
    printf("%p\n", number[1]);        // 4
    printf("%p\n", number[2]);        // 7
    printf("%p\n", number + 1);       // 2
    printf("%p\n", number + 2);       // 5

    return 0;
}