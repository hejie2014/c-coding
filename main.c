#include <stdio.h>

int add(int a, int b);
// Function prototype for add functioneb

int main()
{
    printf("%d\n", 3);         // Call the printf function with argument 3
    printf("%d\n", add(1, 2)); // Call the add function with arguments 1 and 2
    //  Call the add function with arguments 1 and 2
    printf("Hello, World!\n");
    return 0;
}
// This is a simple C program that prints "Hello, World!" to the console.
// It includes the standard input-output library and defines the main function.
int add(int a, int b)
{
    return a + b;
}