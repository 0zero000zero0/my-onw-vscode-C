#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int max(int *a, int n)
{
    int max_element = a[0];
    int i = 0;
    for (i = 0; i != n; i++)
    {
        if (max_element < a[i])
        {
            max_element = a[i];
        }
    }
    return max_element;
}

int main()
{
    int i;
    int n;

    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    printf("最大值为%d", max(a, n));
    free(a);
    system("pause");
    return 0;
}