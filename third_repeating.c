#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void thirdRepeating(int arr[], int n)
{
    int last = 0;
    int count = 0;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[j + 1] && arr[j + 1] != last)
            {
                if (count == 2)
                {
                    val = arr[j];
                }

                count++;
            }
        }
    }
    printf("%d", val);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }
    sort(arr, n);
    thirdRepeating(arr, n);
}