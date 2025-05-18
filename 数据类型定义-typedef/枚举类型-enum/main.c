#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum State
{
    SUCCESS,
    FAILURE,
    PADDING
} State;
void connectState(State state);
int getState();
const char *stateInfo(State state);
int main()
{
    /*
  1. 因为C 语言中的枚举类型本质上就是整数类型（通常是 int）。
  你可以把一个整数赋值给枚举变量，编译器不会报错，但这样做是不安全的，可能导致逻辑错误
  2. 但不能赋字符串，因为字符串是 char * 类型，和整数/枚举类型完全不同，类型不兼容，编译器会报错。
  3. 枚举类型变量可以赋整数（因为本质是 int），但不能赋字符串。
  4. 推荐始终用枚举常量赋值，避免混淆和潜在错误。
  */

    // State state = "er";
    //  State state = SUCCESS;  SUCCESS是枚举类型的常量，不是字符串，编译器会报错，没有双引号。可以用int.
    // 枚举常量（如 SUCCESS）是整数，能赋值给枚举变量。
    // 字符串常量（如 "SUCCESS"）是字符串指针，不能赋值给枚举变量。

    // 设置随机种子，只需一次
    srand(time(NULL));

    State state = getState();
    printf("%d\n", state);
    connectState(state);
    printf("%s\n", stateInfo(state)); // 打印字符串，这里是地址，参数是字符串的首地址
    printf("%p\n", stateInfo(state)); // 打印地址

    return 0;
}
int getState()
{
    int state = rand() % 3; // 生成一个范围在0到2之间的随机数
    return state;
}
// 打印状态信息--注意参入参数的结构
const char *stateInfo(State state)
{
    static const char *info[] = {"SUCCESS", "FAILURE", "PADDING"};
    return info[state];
}
// 连接状态信息----注意参入参数的结构
void connectState(State state)
{

    switch (state)
    {
    case SUCCESS:
        printf("Connection was successful.\n");
        break;
    case FAILURE:
        printf("Could not connect.\n");
        break;
    case PADDING:
        printf("Connecting...\n");
        break;
    default:
        printf("Unknown state\n");
        break;
    }
}

/*
typedef enum Day
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} Day; // 默认从0开始

int main()
{

    Day today = MONDAY;
    printf("%d\n", today);
    if (today == SUNDAY || today == SATURDAY)
    {

        printf("It's the weekend(周末)\n");
    }
    else
    {

        printf("It's a weekday(工作日)\n");
    }

    return 0;
}

*/
