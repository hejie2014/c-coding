#include <stdio.h>

/*
  // 字符串，可以有两种形式定义： char name[30]  或者 char *name
      1. char name[30]---(字符数组);
      2. char *name -----(字符指针);
*/

typedef int Number;
typedef char *String;
typedef char String3[30];
int main()
{

    Number x = 1;
    Number y = 2;
    Number z = x + y;

    // 对于字符串来说，我们需要用指针（或者字符数组）来定义，也就是地址
    String name = "he mu";          // typedef char *String;
    String3 name2 = "hello world!"; // typedef char String3[30];

    printf("%d\n", z);
    printf("%s\n", name);
    printf("%s\n", name2);

    return 0;
}