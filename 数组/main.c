#include <stdio.h>

int main()
{

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numbers1[] = {64, 65, 66, 67, 68, 69, 70, 71, 72, 73};
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        printf("%c ", numbers1[i]);
    }
    printf("\n");
    int arr[200];

    for (int i = 0; i < 200; i++)
    {
        arr[i] = i + 1;
    }
    // 打印数组的地址
    for (int i = 0; i < 200; i++)
    {

        /*
          如果你发现 printf("%d:", arr[i]); 打印的值在终端没有显示，通常不是这句代码的问题，而是因为你后面紧跟着 printf("%c |", arr[i]);，而 arr[i] 的值在 1~13 时，%c 会输出不可见的控制字符（如换行、回车、清屏等），这些字符会影响终端的显示效果，导致你看不到前面的数字。
          例如：

          arr[9] = 10，%c 打印的是换行符，会导致终端换行。
          arr[12] = 13，%c 打印的是回车符，光标回到行首，覆盖前面的内容。
          解决方法：
            只打印数字，或者只在 arr[i] 是可见字符时才打印 %c，否则用点或空格代替：
                printf("%d:", arr[i]);
                if (arr[i] >= 32 && arr[i] <= 126)
                     printf("%c |", arr[i]);
                else
                     printf(". |"); // 用点代替不可见字符

        */

        // printf("%p ", (void *)&arr[i]); 打印数组的地址
        // printf("%p ", (void *)(arr + i)); // 打印数组的地址
        printf("%d:", arr[i]); // 打印数组的值

        // 比如 10 是换行符，11、12、13 是其他控制符，屏幕上不会显示出来
        printf("%c |", arr[i]);
        if (i % 10 == 9)
        {
            printf("\n");
        }
    }
    printf("%caaaa", 0);
    return 0;
}

// int main()
// {

//     char name[] = "hello";
//     char *p = name;      // 指针指向字符串的首地址
//     char *p1 = name + 1; // 指针指向字符串的第二个字符
//     char *p2 = name + 2; // 指针指向字符串的第三个字符
//     char *p3 = name + 3; // 指针指向字符串的第四个字符

//     /*
//     1.  "hello" 实际上在内存中是：{'h', 'e', 'l', 'l', 'o', '\0'}，长度为 6。
//     2.  name[0] 到 name[4] 分别是 'h'、'e'、'l'、'l'、'o'。
//     3.  name[5] 是自动添加的字符串结束符 '\0'。

//     */

//     printf("%c\n", name[4]); // 打印字符串的最后一个字符
//     printf("%c\n", name[5]); // 打印字符串的结束符
//     printf("%s\n", p);       // hello
//     printf("%s\n", p1);      // ello
//     printf("%s\n", p2);      // llo
//     printf("%s\n", p3);      // lo
//     printf("%c\n", *p);      // h
//     printf("%c\n", *p1);     // e
//     printf("%c\n", *p2);     // l
//     printf("%c\n", *p3);     // l

//     return 0;
// }