#include <stdio.h>
#include <ctype.h>  // 用于tolower函数
#include <string.h> // 用于strlen函数
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

double celsius_to_fahrenheit(double c)
{
    return (c * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double f)
{
    return (f - 32.0) * 5.0 / 9.0;
}

int main()
{
    const char *str = "123 45.6 hello";
    int a;
    float b;
    char c[10];
    sscanf(str, "%d %f %s", &a, &b, c);
    int len = strlen(c);                                      // 从字符串解析
    printf("a = %d, b = %.2f, c = %s\n, %d\n", a, b, c, len); // 输出解析结果

    char choice = '\0';
    double fahrenheit = 0.0;
    double celsius = 0.0;
    char input[100];
    int invalid_attempts = 0;

    printf("Temperature Conversion Calculator\n");
    printf("C. Celsius to Fahrenheit\n");
    printf("F. Fahrenheit to Celsius\n");
    printf("E. Exit\n");

    while (1)
    {
        printf("\nEnter your choice (C/F/E): ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            continue;
        }
        input[strcspn(input, "\n")] = '\0'; // 去除换行符
        //  检查输入长度，只允许单个字符
        //" %c"与"%c"有区别，这个格式字符串会跳过所有的空白字符（包括空格、制表符和换行符），直到遇到第一个非空白字符为止
        if (sscanf(input, "%c", &choice) != 1 ||
            strlen(input) != 1)
        {
            // 检查输入是否为单个字符
            printf("Invalid input. Please enter only one character (C, F, or E).\n");
            invalid_attempts++;
            continue;
        }
        choice = tolower(choice); // 统一转为小写

        if (choice == 'c')
        {
            printf("Enter temperature in Celsius: ");
            if (fgets(input, sizeof(input), stdin) == NULL ||
                sscanf(input, "%lf", &celsius) != 1)
            {
                printf("Invalid temperature value.\n");
                continue;
            }
            fahrenheit = celsius_to_fahrenheit(celsius);
            printf("%.2f°C = %.2f°F\n", celsius, fahrenheit);
        }
        else if (choice == 'f')
        {
            printf("Enter temperature in Fahrenheit: ");
            if (fgets(input, sizeof(input), stdin) == NULL ||
                sscanf(input, "%lf", &fahrenheit) != 1)
            {
                printf("Invalid temperature value.\n");
                continue;
            }
            celsius = fahrenheit_to_celsius(fahrenheit);
            printf("%.2f°F = %.2f°C\n", fahrenheit, celsius);
        }
        else if (choice == 'e')
        {
            printf("Exiting the program.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please enter C, F, or E.\n");
            invalid_attempts++;
        }

        // 重置无效尝试计数
        if (choice == 'c' || choice == 'f')
        {
            invalid_attempts = 0;
        }

        // 多次错误后重新显示菜单
        if (invalid_attempts >= 3)
        {
            printf("\nTemperature Conversion Calculator\n");
            printf("C. Celsius to Fahrenheit\n");
            printf("F. Fahrenheit to Celsius\n");
            printf("E. Exit\n");
            invalid_attempts = 0;
        }
    }

    return 0;
}