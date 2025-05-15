#include <stdio.h>
#include <ctype.h> // 用于字符处理函数

/*  scanf()函数的使用注意事项：
1.自动跳过前导空白字符：包括空格(' ')、制表符('\t')、换行符('\n')等

2.从第一个非空白字符开始读取：即数字'3'

3.遇到非数字字符停止读取：如空格、字母等

*/

// 清空输入缓冲区的函数
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // 读取并丢弃所有字符直到换行或文件结束
}

int main()
{
    int choice = 0;
    float pounds = 0.0;
    float kilograms = 0.0;
    const float CONVERSION_FACTOR = 0.453592f; // 定义转换系数为常量

    printf("Weight Conversion Calculator\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Exit\n");

    while (1)
    {
        printf("\nEnter your choice (1, 2 or 3): ");

        // 检查输入是否为整数
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer(); // 清除输入缓冲区中的剩余字符

        if (choice == 1)
        {
            printf("Enter weight in pounds: ");
            while (scanf("%f", &pounds) != 1 || pounds < 0)
            {
                printf("Invalid input. Please enter a positive number: ");
                clear_input_buffer();
            }
            clear_input_buffer();

            kilograms = pounds * CONVERSION_FACTOR;
            printf("%.2f pounds = %.2f kilograms\n", pounds, kilograms);
        }
        else if (choice == 2)
        {
            printf("Enter weight in kilograms: ");
            while (scanf("%f", &kilograms) != 1 || kilograms < 0)
            {
                printf("Invalid input. Please enter a positive number: ");
                clear_input_buffer();
            }
            clear_input_buffer();

            pounds = kilograms / CONVERSION_FACTOR;
            printf("%.2f kilograms = %.2f pounds\n", kilograms, pounds);
        }
        else if (choice == 3)
        {
            printf("Exiting the program.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}

// 使用fgets与sscanf的例子

/*
#include <stdio.h>
#include <stdbool.h>  // 用于bool类型

#define MAX_INPUT_LENGTH 100

// 函数：验证输入是否为纯数字
bool is_valid_number(const char *input, int *number) {
    char extra;
    // 尝试解析整数并检查是否有额外字符
    if (sscanf(input, "%d%c", number, &extra) == 1) {
        return true;  // 成功解析数字且没有多余字符
    }
    // 检查是否是因为有换行符或结束符
    if (sscanf(input, "%d%c", number, &extra) == 2) {
        if (extra == '\n' || extra == '\0') {
            return true;  // 数字后只有换行或结束符
        }
    }
    return false;  // 无效输入
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int number;

    while (true) {
        printf("请输入一个整数(输入q退出): ");

        // 读取用户输入
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("读取输入失败\n");
            continue;
        }

        // 检查是否要退出
        if (input[0] == 'q' && (input[1] == '\n' || input[1] == '\0')) {
            printf("程序退出\n");
            break;
        }

        // 验证输入是否为有效数字
        if (is_valid_number(input, &number)) {
            printf("您输入的有效数字是: %d\n", number);
        } else {
            printf("错误: 请输入纯数字，不要包含其他字符\n");
        }
    }

    return 0;
}

第二个例子
#include <stdio.h>
#include <string.h>

int main()
{
    int choice = 0;
    float pounds = 0.0;
    float kilograms = 0.0;
    char line[100];

    printf("Weight Conversion Calculator\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Exit\n");

    while (1)
    {
        printf("Enter your choice (1 or 2 or 3): ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("Input error.\n");
            continue;
        }
        // 尝试解析整数
        if (sscanf(line, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (choice == 1)
        {
            printf("Enter weight in pounds: ");
            if (!fgets(line, sizeof(line), stdin) || sscanf(line, "%f", &pounds) != 1) {
                printf("Invalid input. Please enter a number.\n");
                continue;
            }
            kilograms = pounds * 0.453592;
            printf("Weight in kilograms: %.2f\n", kilograms);
        }
        else if (choice == 2)
        {
            printf("Enter weight in kilograms: ");
            if (!fgets(line, sizeof(line), stdin) || sscanf(line, "%f", &kilograms) != 1) {
                printf("Invalid input. Please enter a number.\n");
                continue;
            }
            pounds = kilograms / 0.453592;
            printf("Weight in pounds: %.2f\n", pounds);
        }
        else if (choice == 3)
        {
            printf("Exiting the program.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}


*/