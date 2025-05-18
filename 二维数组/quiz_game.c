#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8
    char questions[][100] = {
        "What is the largest planet(行星) in the solar system?",
        "What is the hottest planet(行星) in the solar system?",
        "What planet has the most moons(卫星)?",
        "What is the smallest planet(行星) in the solar system?",
    };
    char answers[][100] = {"A. Jupiter: 木星\nB. Saturn: 土星\nC. Uranus: 天王星\nD. Neptune: 海王星",
                           "A. Mercury: 水星\nB. venus: 金星\nC. Mars: 火星\nD. Earth: 地球",
                           "A. Earth: 地球\nB. Mars: 火星\nC. Jupiter: 木星\nD. Saturn: 土星",
                           "A. Mercury: 水星\nB. Venus: 金星\nC. Mars: 火星\nD. Pluto: 冥王星"};
    char answer_key[] = {'A', 'B', 'D', 'D'};

    int question_count = sizeof(questions) / sizeof(questions[0]);
    int guess = '\0';
    int score = 0;

    printf("*** QUIZ GAME ***\n");

    for (int i = 0; i < question_count; i++)
    {

        printf("\n%s\n", questions[i]);
        printf("\n%s\n", answers[i]);
        printf("Enter your choice: ");
        scanf(" %c", &guess);

        guess = toupper(guess);

        if (guess == answer_key[i])
        {
            printf("CORRECT!\n");
            score++;
        }
        else
        {
            printf("WRONG!\n");
            printf("Result: %c\n", answer_key[i]);
        }
        // printf("\n%c\n", answer_key[0]);
    }
    printf("\nYour score is %d out of %d points\n", score, question_count);
    return 0;
}