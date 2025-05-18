#include <stdio.h>
#include <string.h>
/*
     补充一下：最好不用strlen[name[0] - 1] = '\0';，因为如果用户没有输入任何内容，或者输入正好填满缓冲区，最后一个字符可能不是 \n，这样会错误地删除有效字符。
1.不用 names[0][strlen(names[0]) - 1] = '\0'; 的原因是：
            这种写法只有在字符串最后一个字符一定是\n时才安全。

详细解释:
1. strlen(names[0]) 得到的是字符串实际长度（不包括\0）。
2. names[0][strlen(names[0]) - 1] 是最后一个字符的位置。
3. 如果用户输入的内容正好填满缓冲区（比如输入24个字符，fgets 只读24个字符，不会读入\n），
    那么最后一个字符不 是\n，而是用户输入的内容。
4. 这时直接用 names[0][strlen(names[0]) - 1] = '\0'; 会错误地删除有效字符。

推荐使用：
1. 你可以使用 strcspn 函数来查找字符串中第一个出现的换行符的位置，然后将其替换为 \0。
2. strcspn(names[0], "\n") 返回的是第一个出现的换行符的位置，所以可以安全地将其替换为 \0。
3. 这样做的好处是，无论用户输入什么内容，都会正确地去掉换行符，而不会影响其他有效字符。
4. 另外，strcspn 函数的好处是，它会返回第一个出现的换行符的位置，所以即使用户输入的内容中没有换行符，也不会出错。
   names[i][strcspn(names[i], "\n")] = '\0'; // 去掉换行符
*/
int main()
{
    char names[3][25] = {0};

    // printf("Enter a name: ");
    // fgets(names[0], sizeof(names[0]), stdin);

    /*
     1. 这是因为你用了 fgets(names[0], sizeof(names[0]), stdin); 读取一行输入后，又调用了一次 getchar();。

    2. fgets 会把你输入的内容（包括回车\n）都读进 names[0]，缓冲区已经清空。
    3. 这时再调用 getchar();，程序会等待你再输入一次回车，因为输入缓冲区已经没有内容了。
    4. 所以你需要按两次回车，程序才会继续执行并打印结果。
     getchar(); // 清除输入缓冲区中的换行符
    */
    // 输入字符串
    for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++)
    {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // 去掉换行符
        printf("You entered: %s\n", names[i]);
    }
    printf("\n-----------\n");
    // 打印输入的名字
    for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++)
    {
        printf("Name %d: %s\n", i + 1, names[i]);
    }

    return 0;
}