#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // 用于toupper函数

// 函数声明
void clear_input_buffer();
int getComputerChoice();
int getUserChoice();
void determineWinner(int userChoice, int computerChoice);
void displayChoices(int userChoice, int computerChoice);
void runGame();
char getPlayAgainChoice();

// 游戏选项常量
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main()
{
    // 初始化随机数种子(只需一次)
    srand(time(NULL));

    char choice;
    do
    {
        runGame();
        choice = getPlayAgainChoice();
    } while (choice != 'N'); // 只有当用户输入N/n时才退出

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}

// 获取计算机的选择
int getComputerChoice()
{
    return (rand() % 3) + 1; // 生成1-3的随机数
}

// 获取用户的选择
int getUserChoice()
{
    int choice = 0;
    int validInput;

    do
    {
        printf("\nChoose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice (1-3): ");

        validInput = scanf("%d", &choice);
        clear_input_buffer();

        if (validInput != 1 || choice < 1 || choice > 3)
        {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
        }
    } while (validInput != 1 || choice < 1 || choice > 3);

    return choice;
}

// 判断胜负
void determineWinner(int userChoice, int computerChoice)
{
    if (userChoice == computerChoice)
    {
        printf("It's a tie!\n");
        return;
    }

    if ((userChoice == ROCK && computerChoice == SCISSORS) ||
        (userChoice == PAPER && computerChoice == ROCK) ||
        (userChoice == SCISSORS && computerChoice == PAPER))
    {
        printf("Congratulations! You win!\n");
    }
    else
    {
        printf("Sorry, you lose. Better luck next time!\n");
    }
}

// 显示双方的选择
void displayChoices(int userChoice, int computerChoice)
{
    // 类似一个二维数组，将每个字符串看做一个整体。
    /*
       指针数组：     总存储空间 = 指针大小×4 + 各字符串实际长度
       二维字符数组： 总存储空间 = 4 × 9 = 36字节(固定)
       需要预先指定第二维的大小(最长字符串长度+1)--Scissors

     1.  choices 是一个数组，其元素是指针（内存地址）
     2.  choices[index] 取出的是第 index 个指针（即某个字符串的起始地址）
     3.  当传递给 printf 的 %s 格式时，它会从这个地址开始打印，直到遇到 '\0' 结束符

      1. choices[index] → 得到一个指针（地址）
         *choices[index] → 得到该指针指向的第一个字符--取内容
         choices[index][0] → 同上，得到第一个字符
      4. choices[index][1] → 得到第二个字符

      tip:
            这里 choices[userChoice][0] 实际上是一个 char，而不是字符串指针。
            %s 需要的是字符串地址，但你传入的是单个字符的值（如 'R'），这会导致未定义行为，
            很可能导致程序崩溃或异常退出。单个字符不能被当作字符串处理。单个字符使用%c。

    */
    const char *choices[] = {"", "Rock", "Paper", "Scissors"};
    printf("\nYou chose %s.\n", choices[userChoice]);
    printf("Computer chose %s.\n", choices[computerChoice]);
}

// 清空输入缓冲区
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// 运行游戏主逻辑
void runGame()
{
    printf("\n*** Welcome to Rock-Paper-Scissors Game! ***\n");

    int userChoice = getUserChoice();
    int computerChoice = getComputerChoice();

    displayChoices(userChoice, computerChoice);
    determineWinner(userChoice, computerChoice);
}

// 询问用户是否再玩一次
char getPlayAgainChoice()
{
    char choice;
    int validInput;

    do
    {
        printf("\nDo you want to play again? (y/n): ");
        validInput = scanf(" %c", &choice);
        clear_input_buffer();

        if (validInput != 1)
        {
            printf("Invalid input. ");
            continue;
        }

        choice = toupper(choice);

        if (choice != 'Y' && choice != 'N')
        {
            printf("Please enter 'y' or 'n'. ");
        }
    } while (validInput != 1 || (choice != 'Y' && choice != 'N'));

    return choice;
}