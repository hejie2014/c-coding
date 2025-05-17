#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    int *arr = (int *)malloc(num * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < num; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    arr = NULL; // 避免悬空指针
    return 0;
}