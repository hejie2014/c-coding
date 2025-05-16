#include <stdio.h>
#include <string.h>

int main()
{
    char name[50] = "";
    int age = 0;
    size_t len = 0;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0'; // 移除换行符
    len = strlen(name);
    printf("Length of name: %zu\n", len);
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Hello, %s\n", name);
    printf("You are %d years old.\n", age);

    return 0;
}