#include <stdio.h>

void reverse(int *arr, int i, int j)
{
    if (j <= i)
        return;

    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
    reverse(arr, i + 1, j - 1);
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

    reverse(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}