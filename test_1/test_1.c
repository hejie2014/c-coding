#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool is_raining = true;
    float temperature = -10.5;
    int num1 = 1;
    int num2 = 10;
    int num3 = 100;

    printf("%3d\n", num1);
    printf("%3d\n", num2);
    printf("%3d\n", num3);
    printf("%-5d\n", num1);
    printf("%-5d\n", num2);
    printf("%-5d\n", num3);

    printf("temperature = %.2f°\n", temperature);
    if (is_raining)
    {
        printf("It's raining.\n");
    }
    else
    {
        printf("It's not raining.\n");
    }

    return 0;
}