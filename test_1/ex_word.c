#include <stdio.h>
#include <string.h> // strlen 函数需要包含这个头文件

int main()
{

    char noun[50] = "";
    char verb[50] = "";
    char adjective1[50] = "";
    char adjective2[50] = "";
    char adjective3[50] = "";

    printf("Enter an adjective (description): ");
    fgets(adjective1, sizeof(adjective1), stdin);
    // 注意：fgets 函数会将换行符也读入到字符串中，因此如果需要去掉换行符，可以使用以下代码：
    adjective1[strcspn(adjective1, "\n")] = '\0'; // 去掉换行符

    printf("Enter a noun (animal or person): ");
    fgets(noun, sizeof(noun), stdin);
    noun[strcspn(noun, "\n")] = '\0'; // 去掉换行符

    printf("Enter an adjective (description): ");
    fgets(adjective2, sizeof(adjective2), stdin);
    adjective2[strcspn(adjective2, "\n")] = '\0'; // 去掉换行符

    printf("Enter a verb (ending w/ -ing): ");
    fgets(verb, sizeof(verb), stdin);
    verb[strcspn(verb, "\n")] = '\0'; // 去掉换行符

    printf("Enter an adjective (description): ");
    fgets(adjective3, sizeof(adjective3), stdin);
    adjective3[strcspn(adjective3, "\n")] = '\0'; // 去掉换行符

    // printf("%s\n", adjective1);
    // printf("%s\n", noun);
    // printf("%s\n", adjective2);
    // printf("%s\n", verb);
    // printf("%s\n", adjective3);
    printf("\nI with %s is %s friend.\n", noun, adjective1);
    printf("I see a %s thing.\n", adjective2);
    printf("I feel %s.\n", verb);
    printf("I am %s.\n", adjective3);

    return 0;
}