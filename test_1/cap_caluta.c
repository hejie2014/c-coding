#include <stdio.h>
#include <math.h>

int main()
{
    // 复利计算器
    double principal = 0.0;     // 本金
    double rate = 0.0;          // 年利率
    int years = 0.0;            // 年数
    int compound_frequency = 0; // 复利频率
    double amount = 0.0;        // 最终金额
    double interest = 0.0;      // 利息

    printf("Compound Interest Calculator\n");

    printf("\nEnter the principal amount (p): ");
    scanf("%lf", &principal);

    printf("Enter the annual interest rate % (r): ");
    scanf("%lf", &rate);
    rate = rate / 100; // 将百分比转换为小数

    printf("Enter the number of years (t): ");
    scanf("%d", &years);

    printf("Enter the # of times that interest is compounded per year (n): ");
    scanf("%d", &compound_frequency);
    // 计算复利公式 A = P(1 + r/n)^(nt)
    // 其中 A 是最终金额，P 是本金，r 是年利率，n 是每年复利的次数，t 是年数

    amount = principal * pow((1 + rate / compound_frequency), compound_frequency * years);
    interest = amount - principal; // 利息 = 最终金额 - 本金

    printf("The amount after %d years is: $%.2lf\n", years, amount);
    printf("The interest earned is: %.2lf\n", interest);

    interest = amount * rate; // 之后利息 = 最终金额 * 年利率
    printf("\nAmount: %.2lf\nRate: %.2f\n", amount, rate);
    printf("\nThe after interest: amount * rate = %.2lf\n", interest);

    return 0;
}