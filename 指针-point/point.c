#include <stdio.h>
#include <Windows.h>

void birthday(int age);
void birthday2(int *pAge);
int main()
{
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8
    // SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8
    int age = 25;
    int *pAge = &age; // 将age的地址赋值给指针变量pAge

    // 打印age和pAge的值
    printf("You are %d years old.\n", age);
    printf("You are %d years old.\n", *pAge);

    // 打印age和pAge的地址
    printf("The address of age is %p.\n", &age);
    // printf("The address of pAge is %p.\n", &pAge); // 错误使用，这是指针变量的地址，我们需要的是他的值
    printf("The value(address of age-age的地址) of pAge is %p.\n", pAge);
    printf("The address of pAge is %p.\n", &pAge);

    // 调用birthday_传值--函数
    printf("----------调用birthday函数-----------\n");
    birthday(age);
    printf("---------------------\n");
    printf("执行birthday函数后,You are %d years old.\n", age);
    printf("执行birthday函数后,Your address is %p.\n", &age);

    // 调用birthday2--传地址函数
    printf("\n");
    printf("----------调用birthday2函数-----------\n");
    birthday2(pAge);
    printf("---------------------\n");
    printf("执行birthday2函数后,You are %d years old.\n", age);
    // 地址始终没有改变，一直是刚开始的 age 的地址
    printf("执行birthday2函数后,Your address is %p.\n", &age);

    return 0;
}

void birthday(int age) // 这个函数是值传递
{
    // 这是值传递， 只是对age变量的拷贝，也就是复制，不会改变主函数的age
    age++;
    printf("函数中的age值: Your age after birthday is %d.\n", age);
    printf("函数中的age地址: Your address after birthday is %p.\n", &age);
}

void birthday2(int *pAge) // 这个函数是引用传递
{
    // 这是引用传递，会改变主函数中的age
    (*pAge)++;
    printf("函数中的age值: Your age after birthday is %d.\n", *pAge);
    printf("函数中的age地址: Your address after birthday is %p.\n", pAge);
}