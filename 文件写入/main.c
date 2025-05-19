#include <stdio.h>

int main()
{

    // 文件写入
    FILE *pFile = fopen("C:\\Users\\peace\\Desktop\\output.txt", "w"); // 文件路径， 打开方式（w: 写入(再次写入会覆盖原本内容), a: 追加, r: 读取）
    /*
       fopen("output.txt", "w"),在当前文件下创建文件，使用的相对路径
       fopen("C:\\Users\\Administrator\\Desktop\\output.txt", "w"),在当前路径下创建文件，使用的绝对路径
         注意：windows下文件路径是反斜杠，linux下是斜杠，使用转义符“\”.
    */

    // 如果打开文件失败，返回空指针也就是NULL；进行判断
    // 定义写入的内容
    char text[] = "Hello World!\n你好, 世界！\n";
    char text2[][30] = {"Hello World!\n", "你好, 世界！\n", "加油，守护！"};
    if (pFile == NULL)
    {

        printf("Error opening file!\n");
        return 1;
    }
    fprintf(pFile, "%s", text); // 指向文件的地址， 格式化字符串， 字符串的首地址

    // 使用 for 循环打印一个二维数组
    for (int i = 0; i < sizeof(text2) / sizeof(text2[0]); i++)
    {
        fprintf(pFile, "%s", text2[i]);
    }

    //
    char *text3[3] = {"p(指针): Hello World!\n", "p(指针): 你好, 世界！\n", "p(指针): 加油，守护！"};
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
        // 我们对这个pText指针进行一次解引用(仍然是一个指针，只是从二级指针降为一级指针)，就相当于，这个指针指向一个一维数组，相对与数学中的降次。
        /*
          char (*pText)[50] = text3; // pText 是指向含50个char的数组的指针
                for (int i = 0; i < 3; i++) {
                 printf("%s", pText[i]);
}

        */
    }

    printf("File written successfully!\n");
    fclose(pFile); // 关闭文件,不要忘记

    return 0;
}