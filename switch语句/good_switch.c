#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    char operator = '\0';
    double num1 = 0.0;
    double num2 = 0.0;
    double result = 0.0;
    char line[100];

    while (1)
    {
        // 严格输入第一个数字
        while (1)
        {
            printf("Enter the first number: ");
            if (!fgets(line, sizeof(line), stdin))
            {
                printf("Input error.\n");
                continue;
            }
            char extra;
            if (sscanf(line, "%lf %c", &num1, &extra) == 1) //" %c"表示跳过换行符
            {
                break; // 只输入了一个合法数字
            }
            else
            {
                printf("Invalid input. Please enter a valid number.\n");
            }
        }

        // 输入操作符
        printf("Enter the operator (+, -, *, /): ");
        if (!fgets(line, sizeof(line), stdin) || sscanf(line, " %c", &operator) != 1)
        {
            printf("Invalid input. Please enter an operator.\n");
            continue;
        }

        // 严格输入第二个数字
        while (1)
        {
            printf("Enter the second number: ");
            if (!fgets(line, sizeof(line), stdin))
            {
                printf("Input error.\n");
                continue;
            }
            char extra;
            if (sscanf(line, "%lf %c", &num2, &extra) == 1)
            {
                break; // 只输入了一个合法数字
            }
            else
            {
                printf("Invalid input. Please enter a valid number.\n");
            }
        }

        // 计算结果
        switch (operator)
        {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            else
            {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
        }
        printf("Do you want to continue? (y/n): ");
        char choice;
        if (!fgets(line, sizeof(line), stdin) || sscanf(line, " %c", &choice) != 1)
        {
            break;
        }
        if (choice != 'y' && choice != 'Y')
        {
            break; // 退出循环
        }
    }

    return 0;
}

// #include <stdio.h>

// void clear_input_buffer()
// {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF)
//         ; // 读取并丢弃所有字符直到换行或文件结束
// }

// int main()
// {

//     char operator = '\0';
//     double num1 = 0.0;
//     double num2 = 0.0;
//     double result = 0.0;

//     while (1)
//     {
//         printf("Enter the first number: ");
//         while (scanf("%lf", &num1) != 1)
//         {
//             printf("%lf", num1);
//             printf("Invalid input. Please enter a number.\n");
//             clear_input_buffer();
//         }
//         printf("%lf", num1);
//         clear_input_buffer(); // 清除输入缓冲区中的换行符
//         printf("Enter the operator (+, -, *, /): ");
//         scanf(" %c", &operator);
//         clear_input_buffer(); // 清除输入缓冲区中的换行符

//         printf("Enter the second number: ");
//         while (scanf("%lf", &num2) != 1)
//         {
//             printf("Invalid input. Please enter a number.\n");
//             clear_input_buffer();
//         }
//         clear_input_buffer(); // 清除输入缓冲区中的换行符

//         // 计算结果

//         switch (operator)
//         {
//         case '+':
//             result = num1 + num2;
//             printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
//             break;
//         case '-':
//             result = num1 - num2;
//             printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
//             break;
//         case '*':
//             result = num1 * num2;
//             printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
//             break;
//         case '/':
//             if (num2 == 0)
//             {
//                 printf("Error: Division by zero is not allowed.\n");
//             }
//             else
//             {
//                 result = num1 / num2;
//                 printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
//             }

//             break;
//         default:
//             printf("Error: Invalid operator.\n");
//             break;
//         }
//         printf("Do you want to continue? (y/n): ");
//         char choice;
//         scanf(" %c", &choice);
//         clear_input_buffer(); // 清除输入缓冲区中的换行符
//         if (choice != 'y' && choice != 'Y')
//         {
//             break; // 退出循环
//         }
//     }

//     return 0;
// }
