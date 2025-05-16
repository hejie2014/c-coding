#include <stdio.h>
#include <Windows.h> // for sleep-windows
// #include <unistd.h>  // for sleep-linux/mac

int main()
{

    for (int i = 10; i >= 0; i--)
    {

        printf("%d\n", i);
        Sleep(1000); // sleep for 1000 milliseconds (1 second) - Windows
        // sleep(1);  // sleep for 1 second - Linux
    }
    printf("happy new year\n");

    return 0;
}