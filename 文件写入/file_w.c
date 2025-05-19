#include <stdio.h>
#include <windows.h>

/*     二级指针（char **p）
1. *p++
    含义：先取 *p（即 p[0]，第一个指针），然后 p++（移动到下一个指针）。
适用场景：遍历指针数组。
    char *arr[] = {"Hello", "World", "!"};
    char **p = arr;
    printf("%s ", *p++); // 输出 "Hello"，p 现在指向 &arr[1]
    printf("%s ", *p++); // 输出 "World"，p 现在指向 &arr[2]
    printf("%s ", *p);   // 输出 "!"

2.(*p)++
    含义：先取 *p（第一个指针），然后对该指针指向的字符串进行 ++（修改字符）。
适用场景：修改指针指向的字符串内容。
    char str[] = "ABC";
    char *arr[] = {str, "World"};
    char **p = arr;
    printf("%c ", (*p)++); // 输出 'A'，但 str[0] 变成 'B'
    printf("%s ", *p);     // 输出 "BBC"（已被修改）
输出：
    A BBC
内存变化：
    初始：str = "ABC"
    (*p)++ 后：str = "BBC"

           三级指针（char ***p）
(1) *p++
含义：先取 *p（即 p[0]，第一个二级指针），然后 p++（移动到下一个二级指针）。
适用场景：遍历指针数组的数组。
        char *group1[] = {"Hello", "World"};
        char *group2[] = {"Foo", "Bar"};
        char **arr[] = {group1, group2};
        char ***p = arr;
        printf("%s ", **p++); // 输出 "Hello"，p 现在指向 &group2
        printf("%s ", **p);   // 输出 "Foo"
输出：
    Hello Foo

(2) (*p)++
含义：先取 *p（第一个二级指针），然后对该二级指针 ++（使其指向下一个指针）。
适用场景：修改二级指针的指向。

        char *group[] = {"Hello", "World", "!"};
        char **p = group;
        char ***pp = &p;
        printf("%s ", **pp);    // 输出 "Hello"
        (*pp)++;               // 使 p 指向 "World"
        printf("%s ", **pp);   // 输出 "World"
输出： *pp得到p的地址，开始p指向 group[0]的地址，p++后p指向group[1]的地址,
       下一个**pp,先解引用一次，得到p(二级指针)的值，再解引用一次，得到group[1]的首地址(一级指针)
        Hello World
内存变化；
        初始：p → "Hello"
        (*pp)++ 后：p → "World"


 ---------------------总结----------------------

总结对比
表达式	  运算顺序	            适用场景	                示例
*p++	先 *p，再 p++	      遍历数组	            char *p = arr; *p++;
(*p)++	先 *p，再 (*p)++	  修改指针指向的值	     char *p = arr; (*p)++;
**p++	先 **p，再 p++	      遍历指针数组	         char **p = arr; **p++;
(*p)++	先 *p，再 (*p)++	  修改二级指针指向	     char **p = arr; (*p)++;
***p++	先 ***p，再 p++	      遍历三级指针数组	     char ***p = arr; ***p++;
(*p)++	先 *p，再 (*p)++	  修改三级指针指向	     char ***p = arr; (*p)++;

char *text3[3] = {"A", "B", "C"};
char **pText = text3;
(*pText)++; // 让 text3[0] 从 "A" 变成 ""（指向下一个字符，实际是 '\0'）
printf("%s\n", *pText); // 输出空字符串

关键区别：
1.  *p++：移动指针（不修改指向的值）。
2.  (*p)++：修改指针指向的值（不移动指针）。
掌握这些区别，能避免指针操作中的常见错误！ 🚀

*/
int main()
{
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8

    // 文件写入
    FILE *pFile = fopen("C:\\Users\\peace\\Desktop\\output.txt", "w"); // 文件路径， 打开方式（w: 写入(再次写入会覆盖原本内容), a: 追加, r: 读取）
    /*
       fopen("output.txt", "w"),在当前文件下创建文件，使用的相对路径
       fopen("C:\\Users\\Administrator\\Desktop\\output.txt", "w"),在当前路径下创建文件，使用的绝对路径
         注意：windows下文件路径是反斜杠，linux下是斜杠，使用转义符“\”.
    */
    // 如果打开文件失败，返回空指针也就是NULL；进行判断
    // 定义写入的内容
    if (pFile == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    char *text3[3] = {"p(指针): Hello World!\n", "p(指针): 你好, 世界！\n", "p(指针): 加油，守护！\n"};
    char **pText = text3;
    int count = 0;
    for (int i = 0; i < sizeof(text3) / sizeof(text3[0]); i++)
    {
        // 使用pText[i]，来访问二维数组中的元素，pText[i]指的是每个字符串的首地址等价于*（pText + i）
        // fprintf(pFile, "%s", pText[i]);

        fprintf(pFile, "%s", *pText);
        printf("每%d次的地址(address)是: %p\n", count, *pText);
        *pText++;
        //  fprintf(pFile, "%s", pText[i]);
        //  printf("每%d次的地址(address)是: %p\n", count, pText[i]);
        count++;
        // (*pText)++; // 对指针进行一次解引用，得到指向第一个字符串的首地址，在进行加一操作，就会指向
        // 下一个字符串的首地址
        // 这个text3这个字符数组是一个二维数组，你可以将每个字符串看做一个整体，那么就是一个一维数组
        // 我们对这个pText指针进行一次解引用(仍然是一个指针，只是从二级指针降为一级指针)，就相当于，这个指针 指向一个一维数组，相对与数学中的降次。
        /*
          char (*pText)[50] = text3; // pText 是指向含50个char的数组的指针
                for (int i = 0; i < 3; i++) {
                 printf("%s", pText[i]);}
        */
    }
    char text4[][50] = {"p2(指针): Hello World!\n", "p2(指针): 你好, 世界！\n", "p2(指针): 加油，守护！\n"};
    /*
    1. 注意优先级 char (*pText2)[50]这是一个指向含50个char的数组的指针，本质是指针
    2.  而 char *pText2[50],这是一个含50个char指针的数组，本质是数组
    3.  这个[],与（）同级优先度高， * 优先级低于两者

    */
    char (*pText2)[50] = text4;
    count = 0;
    for (int i = 0; i < sizeof(text4) / sizeof(text4[0]); i++)
    {
        fprintf(pFile, "%s", pText2);
        printf("每%d次的地址(address)是: %p\n", count, pText2);
        pText2++;
        //  fprintf(pFile, "%s", pText[i]);
        //  printf("每%d次的地址(address)是: %p\n", count, pText[i]);
        count++;
    }
    printf("File written successfully!\n");
    fclose(pFile); // 关闭文件,不要忘记
    return 0;
}