#include <stdio.h>

int main()
{

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

*/
    int rows = 3, cols = 3;
    // 动态分配二维数组
    // 1. 先分配行指针数组
    // 2. 再分配每一行的列数组
    // 3. 注意：二维数组的每一行的列数可以不同
    // 4. 释放内存时，先释放每一行的列数组，再释放行指针数组
    // rows 行数相当于一个二级指针，cols 列数相当于一个一级指针
    int **number = (int **)malloc(rows * sizeof(int *)); // number指针存储的是指向每一行一维数组的首地址
                                                         //  类似于  number[3] = {p1, p2, p3}，每个 p1、p2、p3 都是指向一维数组的指针
    // 申请每一行的内存，为每个行分配 cols 个 int 大小的内存
    // 注意：这里的 number[i] 是一个一级指针，指向每一行的数组

    for (int i = 0; i < rows; i++)
    {
        number[i] = (int *)malloc(cols * sizeof(int));
    }
    // 初始化...
    number[0][0] = 1; // 可以像二维数组一样访问
    // 释放内存...
    // 先释放每一行的列数组

    for (int i = 0; i < rows; i++)
    {
        free(number[i]); // number[i] 是一个一级指针，指向每一行的数组,有三个
    }
    free(number); // number 是一个二级指针，有一个

    return 0;
}