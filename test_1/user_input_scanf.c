#include <stdio.h>
#include <string.h> // strlen 函数需要包含这个头文件
int main()
{
    // 提供一个默认值，防止未初始化变量的使用
    int age = 0;
    float gpa = 0.0f;

    // '' 是一个无效的字符常量。C语言规定，字符常量必须包含** exactly one character**（或转义序列，如'\n'）。而''表示“没有字符”，因此编译器会报错
    char grade = '\0'; // 这里使用'\0'表示空字符

    //"" 是一个合法的字符串字面量，它包含一个隐式的'\0'（即{'\0'}）。因此，以下代码是合法的：
    char name[50] = "";
    // 使用 scanf 函数从标准输入读取数据
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    printf("Enter your grade: ");
    scanf(" %c", &grade); // 注意前面的空格，用于跳过前面的换行符

    getchar(); // 读取并丢弃回车
    printf("Enter your name: ");
    // 只能读取第一个单词，它会以空格、回车或Tab为分隔符，只读取第一个单词（遇到空白字符就停止），不会读取整行。使用fegts 函数可以读取整行
    // scanf("%s", name);
    // 注意这里没有使用&，因为name是一个数组名，代表数组的首地址
    // 注意：在使用 scanf 函数时，必须确保输入的数据类型与变量的类型匹配，否则可能会导致未定义的行为
    // 例如，如果输入一个字符串而变量是整数类型，scanf 函数将无法正确解析输入，可能导致程序崩溃或输出错误的值
    // 另外，scanf 函数不会检查输入的长度，因此如果输入的字符串超过了数组的大小，可能会导致缓冲区溢出
    // 这可能会导致程序崩溃或输出错误的值
    fgets(name, sizeof(name), stdin); // 读取整行输入，包括空格
    // 注意：fgets 函数会将换行符也读入到字符串中，因此如果需要去掉换行符，可以使用以下代码：
    // name[strcspn(name, "\n")] = '\0'; // 去掉换行符
    // 也可以使用下面的代码来去掉换行符
    // name[strlen(name) - 1] = '\0'; // 去掉换行符
    // 推荐也可以使用下面的代码来去掉换行符,如果用户没有输入任何内容，或者输入正好填满缓冲区，最后一个字符可能不是 \n，这样会错误地删除有效字符。
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
    {
        name[len - 1] = '\0';
    }
    printf("%s\n", name);
    printf("%d\n", age);
    printf("%.2f\n", gpa);
    printf("%c\n", grade);

    return 0;
}