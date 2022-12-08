#ifndef MY_HEAD
#define MY_HEAD

//选择排序
void selective_sort_double(double *arr, int length)
{
    int t = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}
void selective_sort_int(int *arr, int length)
{
    int t = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}
//冒泡排序
void bubble_sort_double(int *a, int n)
{
    int k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
}

void bubble_sort_int(int *a, int n)
{
    int k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
}

void swap_int(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_double(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

int add_int(int a, int b)
{
	return a + b;
}

int sub_int(int a, int b)
{
	return a - b;
}

int calc_int(int (*fp)(int, int), int a, int b)//函数指针作为参数
{
	return (*fp)(a, b);
}

int (*select_int(char op))(int, int)//返回函数指针
{
	switch (op)
	{
	case '+':
		return add;
		break;
	case '-':
		return sub;
		break;
	}
}

#endif