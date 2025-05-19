#include <stdio.h>

int main()
{
    char *strs[] = {"Hello", "World"};
    char **p = strs;

    printf("%s\n", *p); // 输出 "Hello"
    // (*p)++;            // 让 p[0] 指向 "ello"（修改指针的指向）
    // printf("%s ", *p); // 输出 "ello"

    for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
    {
        printf("%s\n", *p); // 输出 "Hello"
        *p++;
    }
    // 使用 (*p)++
    printf("------------------------\n");

    char *strs2[] = {"Hello", "World"};
    char **p2 = strs2;
    for (int i = 0; i < sizeof(strs2) / sizeof(strs2[0]); i++)
    {
        printf("p2: %s ", *p2); // 输出 "Hello"
        printf("p2: %p\n", *p2);
        (*p2)++;
    }
    /*
      输出结果：
        Hello
        Hello
        World
        ------------------------
        p2: Hello p2: 00007FF722674000
        p2: ello p2: 00007FF722674001
    */

    printf("---------------三级指针-----------------\n");

    char *strs3[] = {"Hello", "World", "he", "df", "qr"};
    char **p3 = strs3;
    char ***p4 = &p3;
    for (int i = 0; i < sizeof(strs3) / sizeof(strs3[0]); i++)
    {
        printf("p4: %s ", **p4); // 输出 "Hello"
        printf("p4: %p\n", **p4);
        (*p4)++; // 对p4进行解引用，得到指针p3，在对p3进行自增，(p3是指向一个指针数组) p3指向下一个字符串
        // p -----> strs{1, 2, 3, 4, 5} 这个1-5都是指针。

        // (**p4)++; // 这样会让 *p3 指向下一个字符，不是下一个字符串
        /*
        1. p4 是一个指向指针的指针，即 char ***p4 = &p3;。
        2. *p4++ 实际上是让 p4 这个三级指针自增，p4 只指向了 p3 这一块内存，自增后它就不再指向有效的指针了。
        3. 这样，循环第一次后，p4 已经不再指向 p3，**p4 变成了野指针，导致循环第二次就出错或提前结束。

        如果你想用三级指针遍历，应该只用二级指针遍历字符串数组，三级指针一般用于函数参数传递，很少直接用于遍历。
        */
    }
    return 0;
}