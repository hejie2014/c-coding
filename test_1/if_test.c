#include <stdio.h>
#include <string.h>

void clear_input_buffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; // 读取并丢弃所有字符直到换行
}

int main()
{

    int choice = 0;
    float pounds = 0.0;
    float kilograms = 0.0;
    printf("Weight Conversion Calculator\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Exit\n");

    // 清空输入缓冲区的函数
    // 这个函数会读取并丢弃输入缓冲区中的所有字符，直到遇到换行符或文件结束符

    while (1)
    {
        printf("Enter your choice (1 or 2 or 3): ");
        scanf("%d", &choice);
        clear_input_buffer();
        // fgets(line, sizeof(line), stdin); // 读取一行输入
        // sscanf(line, "%d", &choice); // 从输入行中提取整数
        // printf("Enter your choice (1 or 2 or 3): ");
        // if (!fgets(line, sizeof(line), stdin) || sscanf(line, "%d", &choice) != 1) {
        //     printf("Invalid input. Please enter a number.\n");
        //     continue;

        // 这句判断用户输入是否为一个整数。如果不是（比如输入了字母或其他非法字符），scanf 返回值不是 1，进入 if 语句块
        // if (scanf("%d", &choice) != 1)
        // {
        //     // 清空输入缓冲区
        //     int c;
        //     while ((c = getchar()) != '\n' && c != EOF)
        //         ;
        //     printf("Invalid input. Please enter a number.\n");
        //     continue;
        // }

        if (choice == 1)
        {
            printf("Enter weight in pounds: ");
            scanf("%f", &pounds);
            kilograms = pounds * 0.453592;
            printf("Weight in kilograms: %.2f\n", kilograms);
        }
        else if (choice == 2)
        {
            printf("Enter weight in kilograms: ");
            scanf("%f", &kilograms);
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

// int main()
// {

//     char name[50] = "";
//     int i = 0;
//     printf("Enter your name: ");
//     fgets(name, sizeof(name), stdin);

//     printf("Address: %p\n", (void *)name);
//     printf("string content: ");
//     // 遍历字符串并打印每个字符
//     for (i = 0; i <= strlen(name); i++)
//     {
//         if (name[i] == '\0')
//         {
//             printf("\\0");
//         }
//         else if (name[i] == '\n')
//         {
//             printf("\\n");
//         }
//         else if (name[i] == '\t')
//         {
//             printf("\\t");
//         }
//         else if (name[i] == ' ')
//         {
//             printf("\\s");
//         }
//         else if (name[i] == '\\')
//         {
//             printf("\\\\");
//         }
//         else
//         {
//             printf("%c", name[i]);
//         }
//     }
//     printf("\n");
//     // Remove newline character from the end of the name
//     // name[strcspn(name, "\n")] = 0;
//     puts(name); // 自动添加换行符
//     printf("%s", name);
//     printf("Length of name: %zu\n", strlen(name));

//     name[strcspn(name, "\n")] = 0; // 移除换行符

//     if (strlen(name) > 0)
//     {
//         printf("Hello, %s", name);
//     }
//     else
//     {
//         printf("No name entered.\n");
//     }

//     return 0;
// }