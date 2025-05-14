#include <stdio.h>
#include <math.h>

int main()
{
    double radius = 0.0f;
    double area = 0.0f;
    double surface_area = 0.0f;
    double volume = 0.0f;
    const double PI = 3.14159265358979323846;
    // 提供一个默认值，防止未初始化变量的使用

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    // 计算圆的面积
    area = PI * pow(radius, 2); // πr^2 ,pow 函数的第一个参数是底数，第二个参数是指数
    printf("\nThe area of the circle is: %lf\n", area);
    printf("The area of the circle is: %.2lf\n", area);               // %.2lf 表示保留两位小数,四舍五入
    printf("科学计数法(e)The area of the circle is: %e\n", area);     // %e 表示科学计数法
    printf("The area of the circle is: %g\n", area);                  // %g 表示自动选择浮点数格式，去掉多余的0
    printf("The area of the circle is: %g\n", 0.0000000000000000001); // %g 表示自动选择浮点数格式，去掉多余的0

    // 计算圆的表面积
    surface_area = 4 * PI * pow(radius, 2); // 4πr^2
    printf("The surface area of the sphere is: %.2lf\n", surface_area);

    // 计算圆的体积
    volume = (4.0 / 3.0) * PI * pow(radius, 3); // (4/3)πr^3
    printf("The volume of the sphere is: %.2lf\n", volume);

    // 计算圆的周长
    double circumference = 2 * PI * radius; // 2πr
    printf("The circumference of the circle is: %.2lf\n", circumference);

    return 0;
}