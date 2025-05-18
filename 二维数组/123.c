#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char get_valid_char_input(const char *prompt, const char *valid_chars)
{
    char input;
    bool valid = false;

    do
    {
        printf("%s", prompt);
        scanf(" %c", &input);
        input = toupper(input);

        // 检查输入是否有效
        for (const char *c = valid_chars; *c; c++)
        {
            if (input == *c)
            {
                valid = true;
                break;
            }
        }

        if (!valid)
        {
            printf("Invalid input. Please try again.\n");
        }
    } while (!valid);

    return input;
}

int main()
{
    // 示例使用
    char guess = get_valid_char_input("Enter your choice (A/B/C/D): ", "ABCD");
    printf("You chose: %c\n", guess);

    return 0;
}