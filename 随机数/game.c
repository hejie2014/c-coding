#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_input_buffer();
int getComputerChoice();
int getUserChoice();
int getWinner(int userChoice, int computerChoice);
void gameInformation(int userChoice, int computerChoice);
int main()
{

    srand(time(NULL)); // 设置随机数种子

    printf("*** welcome to Rock-Paper-Scissors game! ***\n");

    int userChoice = getUserChoice();
    int computerChoice = getComputerChoice();
    gameInformation(userChoice, computerChoice);
    getWinner(userChoice, computerChoice);

    return 0;
}

int getComputerChoice()
{

    return (rand() % 3) + 1; // 生成一个范围在1到3之间的随机数
}
int getUserChoice()
{
    int choice = 0;
    do
    {
        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        clear_input_buffer(); // 清空输入缓冲区

    } while (choice < 1 || choice > 3);

    return choice;
}
int getWinner(int userChoice, int computerChoice)
{
    if (userChoice == computerChoice)
    {
        printf("It's a tie!\n");
    }
    else if (userChoice == 1 && computerChoice == 3)
    {
        printf("You win! Rock crushes Scissors.\n");
    }
    else if (userChoice == 2 && computerChoice == 1)
    {
        printf("You win! Paper covers Rock.\n");
    }
    else if (userChoice == 3 && computerChoice == 2)
    {
        printf("You win! Scissors cuts Paper.\n");
    }
    else
    {
        printf("You lose!\n");
    }
}

void gameInformation(int userChoice, int computerChoice)
{

    switch (userChoice)
    {
    case 1:
        printf("You chose Rock.\n");
        break;
    case 2:
        printf("You chose Paper.\n");
        break;
    case 3:
        printf("You chose Scissors.\n");
        break;
    }
    switch (computerChoice)
    {
    case 1:
        printf("Computer chose Rock.\n");
        break;
    case 2:
        printf("Computer chose Paper.\n");
        break;
    case 3:
        printf("Computer chose Scissors.\n");
        break;
    }
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
} // 清空输入缓冲区