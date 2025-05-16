#include <stdio.h>

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // 读取并丢弃所有字符直到换行或文件结束
}

int main()
{

    char operator = '\0';
    double num1 = 0.0;
    double num2 = 0.0;
    double result = 0.0;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    clear_input_buffer(); // 清除输入缓冲区中的换行符
    // 读取操作符
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator); // 注意前面的空格，跳过空白字符
    clear_input_buffer();
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    clear_input_buffer(); // 清除输入缓冲区中的换行符
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
    return 0;
}