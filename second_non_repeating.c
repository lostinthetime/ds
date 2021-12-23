#include <stdio.h>

void secondNonRepeating(int arr[], int n)
{
    int non[n];
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] != arr[j] && i != j)
            {
                flag++;
            }
        }
        if (flag == n - 1)
        {
            non[pos] = arr[i];
            pos++;
        }
    }
    printf("%d", non[1]);
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
    secondNonRepeating(arr, n);
}