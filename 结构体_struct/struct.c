#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// 结构体 struct Student中student这个标签可以省略
/*
   理论总和： 20 + 4 + 4 + 1 = 29 字节
为什么实际是 32 字节？
  1. 这是因为结构体有内存对齐（padding），编译器会自动在成员之间或末尾补齐字节，使结构体整体大小是最大成员类型的整数倍（通常是4或8字节）。
  2.  结构体大小是 32 字节，因为编译器为了对齐，自动补齐了3个字节。
  3.  这样可以提高内存访问效率，是C语言结构体的常见行为。
*/
typedef struct Student
{

    char name[20];
    int age;
    float gpa;
    bool isFulltime;

} Student;

void printStudentInfo(Student *student);
void printStudentInfoAll(Student *student, int num);
int main()
{

    Student student1 = {"Spongebob", 25, 2.5, true};
    Student student2 = {"Patrick", 36, 2.0, false};
    Student student3 = {"Squidward", 48, 3.2, true};
    Student student4 = {0};
    /*
        //student4.name = "Sandy";
     在 C 语言中，结构体中的 char name[20]; 是一个字符数组，不能直接用 = 赋值字符串常量。
     "Sandy" 是一个字符串常量（const char *），不能直接赋值给字符数组。

    1.  char name[20] = "hello"; 只在定义时可以用。
    2.  后续赋值要用 strcpy(name, "hello");
    3.  不能直接 name = "hello";，这不是合法的 C 语法。
    */
    strcpy(student4.name, "Sandy"); // 不能直接 student4.name = "Sandy";
    student4.age = 25;
    student4.gpa = 3.5;
    student4.isFulltime = true;

    printf("%s\n", student4.name);
    printf("%d\n", student4.age);
    printf("%.2f\n", student4.gpa);
    printf("%s\n", (student4.isFulltime) ? "Yes" : "No");

    printf("---------以下是指针---------\n");
    /*
    1. 因为 Student *p = &student4; 的意思是让指针 p 指向变量 student4 的地址，这样 p 就可以通过 -> 操作符访问 student4 的成员。

    而 Student *p = student4; 是错误的，因为：
    1.  student4 是一个结构体变量，不是地址，不能直接赋值给指针类型。
    2.  指针变量必须保存地址（即 &student4），而不是结构体本身。
    总结：
    1. Student *p = &student4; 正确，p 指向 student4。
    2. Student *p = student4; 错误，类型不兼容，编译会报错。

    */

    Student *p = &student4;
    printf("%s\n", p->name);
    printf("%d\n", p->age);
    printf("%.2f\n", p->gpa);
    printf("%s\n", (p->isFulltime) ? "Yes" : "No");

    printf("---------以下循环打印---------\n");
    // 循环打印学生信息
    // 使用数组存储结构体， 数组的元素是Student结构体--类比 int student = [1,2,3,4]
    // 只不过数据类型由 int型 转为 Student结构体类型。本质一样，只是数据类型不同。
    Student students[] = {student1, student2, student3, student4};

    printf("students的大小是%d, students[0]的大小是%d\n", sizeof(students), sizeof(students[0]));
    printf("students的大小是%zu, students[0]的大小是%zu\n", sizeof(students), sizeof(students[0]));

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++)
    {
        printf("%s\n", students[i].name);
        printf("%d\n", students[i].age);
        printf("%.2f\n", students[i].gpa);
        printf("%s\n", (students[i].isFulltime) ? "Yes" : "No");
    }

    printf("----------以下使用指针来循环打印-----------\n");
    // 使用指针来循环打印学生信息
    // 定义一个指向 Student结构体 的 指针变量；

    /* 1.students[0]的地址是0000004B455FF960，students[1]的地址是0000004B455FF980，students[2]的地址是   0000004B455FF9A0，students[3]的地址是0000004B455FF9C0，
       2. 你看到的地址差是0x20（十六进制20）= 32（十进制），实际上正好是32字节。

    1. 你看到的“20”是十六进制，不是十进制。
    2. 0x20 十六进制等于 32 十进制，正好是你结构体的大小。
    3. 这说明每个结构体在内存中占用 32 字节，数组中每个元素的地址间隔就是 32 字节。

    1. 地址差 0x20（十六进制）就是 32（十进制）字节。
    2. 你的结构体大小确实是 32 字节，和地址间隔完全一致。
    3. 这说明结构体数组在内存中是连续存储的，每个元素占 32 字节。

    */
    Student *p_students = students;
    /*  p->age 实际上等价于 (*(p)).age，即“先解引用指针，再访问成员”。
    1.     p 保存了 s 的首地址。
    2.  结构体的每个成员在内存中都有固定偏移量（比如 age 在 name 后面）。
    3.  当你写 p->age，编译器会自动计算 p 指向的内存地址加上 age 的偏移量，去取出对应的值。
    4.  这和 s.age 是等价的，只不过 p->age 是通过指针间接访问。
    */

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++)
    {
        printf("student: %d of information\n", (i + 1));
        printf("students[%d]的地址是%p\n", i, &students[i]);
        printf("%s\n", p_students->name);
        printf("%d\n", p_students->age);
        printf("%.2f\n", p_students->gpa);
        printf("%s\n", (p_students->isFulltime) ? "Yes" : "No");
        printf("\n");
        p_students++; // 指针后移,让指针指向下一个Student结构体
    }
    printf("------使用函数打印------\n");
    printf("student的信息:\n");
    printStudentInfo(p); // p是指向Student4结构体的指针, Student *p = &student4;

    printf("------使用函数打印信息------\n");
    printf("student的信息:\n");
    Student *p2_students = students;
    printStudentInfoAll(p2_students, sizeof(students) / sizeof(students[0]));

    return 0;
}

void printStudentInfo(Student *student)
{
    printf("%s\n", student->name);
    printf("%d\n", student->age);
    printf("%.2f\n", student->gpa);
    printf("%s\n", (student->isFulltime) ? "Yes" : "No");
}

void printStudentInfoAll(Student *p_student, int num)
{

    for (int i = 0; i < num; i++)
    {
        printf("student: %d of information\n", (i + 1));
        // printf("students[%d]的地址是%p\n", i, &p_student[i]);
        printf("students[%d]的地址是%p\n", i, p_student); // p_student++，不能&p_student[i]，会导致重复计算地址
        printf("%s\n", p_student->name);
        printf("%d\n", p_student->age);
        printf("%.2f\n", p_student->gpa);
        printf("%s\n", (p_student->isFulltime) ? "Yes" : "No");
        printf("\n");
        p_student++; // 指针后移,让指针指向下一个Student结构体
    }
}