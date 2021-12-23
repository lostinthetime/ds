#include <stdio.h>

int size = 0;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int arr[], int size, int i)
{
    if (size == 1)
    {
        printf("Single Element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && arr[l] > arr[largest])
        {
            largest = l;
        }
        if (r < size && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, size, largest);
        }
    }
}

void insert(int arr[], int data)
{
    if (size == 0)
    {
        arr[0] = data;
        size += 1;
    }
    else
    {
        arr[size] = data;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(arr, size, i);
        }
    }
}

void deleteElement(int arr[], int data)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (data == arr[i])
        {
            break;
        }
    }
    swap(&arr[i], &arr[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[10];

    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printf("Max-Heap array: ");
    printArray(array, size);

    deleteElement(array, 4);

    printf("After deleting an element: ");

    printArray(array, size);
}