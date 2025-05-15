#include <stdio.h>
#include <string.h>
// 清空输入缓冲区的函数
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // 读取并丢弃所有字符直到换行或文件结束
}

int main()
{
    char line[100];
    char choice = '\0';
    float fahrenheit = 0.0;
    float celsius = 0.0;

    printf("Temperature Conversion Calculator\n");
    printf("C. Celsius to Fahrenheit\n");
    printf("F. Fahrenheit to Celsius\n");
    printf("E. Exit\n");
    while (1)
    {
        printf("Is the temperature in Celsius (C,c) or Fahrenheit (F,f) or Exit (E,e)? : ");
        // scanf(" %c", &choice); // 注意前面的空格，跳过空白字符

        // 检查输入是否为字符
        // 这句判断用户输入是否为一个字符。如果不是（比如输入了数字或其他非法字符），scanf 返回值不是 1，进入 if 语句块
        // getchar(); // 清除输入缓冲区中的换行符
        // 这里使用了一个小技巧，scanf("%c", &choice) 会读取一个字符，但如果输入中有空格或换行符，它们会被当作有效输入
        if (!fgets(line, sizeof(line), stdin))
        {
            printf("Input error.\n");
            continue;
        }
        // 去除换行符
        line[strcspn(line, "\n")] = '\0';

        // 检查输入长度，只允许单个字符
        if (strlen(line) != 1)
        {
            printf("Invalid input. Please enter only one character (C, F, or E).\n");
            continue;
        }
        choice = line[0];
        // clear_input_buffer(); // 清除输入缓冲区中的剩余字符

        if (choice == 'C' || choice == 'c')
        {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            // 清除输入缓冲区中的剩余字符
            clear_input_buffer();
            // 计算华氏温度
            // 公式：F = C * 9/5 + 32
            fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
            printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
        }
        else if (choice == 'F' || choice == 'f')
        {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            // 清除输入缓冲区中的剩余字符
            clear_input_buffer();
            // 计算摄氏温度
            // 公式：C = (F - 32) * 5/9
            celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
            printf("Temperature in Celsius: %.2f\n", celsius);
        }
        else if (choice == 'E' || choice == 'e')
        {
            printf("Exiting the program.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please enter C, F, or E.\n");
        }
    }

    return 0;
}

/*
// 这个程序是一个温度转换计算器，允许用户在摄氏度和华氏度之间进行转换。代码优化，解决多个输入的问题

#include <stdio.h>
#include <string.h>

int main()
{
    char line[100];
    char choice = '\0';
    float fahrenheit = 0.0;
    float celsius = 0.0;

    printf("Temperature Conversion Calculator\n");
    printf("C. Celsius to Fahrenheit\n");
    printf("F. Fahrenheit to Celsius\n");
    printf("E. Exit\n");
    while (1)
    {
        printf("Is the temperature in Celsius (C,c) or Fahrenheit (F,f) or Exit (E,e)? : ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("Input error.\n");
            continue;
        }
        // 去除换行符
        line[strcspn(line, "\n")] = '\0';

        // 检查输入长度，只允许单个字符
        if (strlen(line) != 1) {
            printf("Invalid input. Please enter only one character (C, F, or E).\n");
            continue;
        }
        choice = line[0];

        if (choice == 'C' || choice == 'c')
        {
            printf("Enter temperature in Celsius: ");
            if (!fgets(line, sizeof(line), stdin) || sscanf(line, "%f", &celsius) != 1) {
                printf("Invalid input. Please enter a number.\n");
                continue;
            }
            fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
            printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
        }
        else if (choice == 'F' || choice == 'f')
        {
            printf("Enter temperature in Fahrenheit: ");
            if (!fgets(line, sizeof(line), stdin) || sscanf(line, "%f", &fahrenheit) != 1) {
                printf("Invalid input. Please enter a number.\n");
                continue;
            }
            celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
            printf("Temperature in Celsius: %.2f\n", celsius);
        }
        else if (choice == 'E' || choice == 'e')
        {
            printf("Exiting the program.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please enter C, F, or E.\n");
        }
    }

    return 0;
}



*/