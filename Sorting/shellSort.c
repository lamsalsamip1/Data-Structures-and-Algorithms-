/*

SHELL SORT : Divide by interval and compare elements, reduce interval till it reaches 1.

TIME COMPLEXITY -> Best case, Average case = O(nlogn)
                   Worst case -> O(n^2)


SPACE COMPLEXITY -> O(1)

Better than bubble sort because the closer the file is to the sorted order, more efficient it becomes.
*/

#include <stdio.h>
#define N 10
void shellSort(int arr[], int length);
void display(int arr[], int length);
int main()
{
    int arr[N] = {10, 1, 2, 3, 9, 8, 7, 5, 6, 4};
    printf("Array before sorting: ");
    display(arr, N);
    shellSort(arr, N);
    printf("\nArray after sorting: ");
    display(arr, N);
    return 0;
}

void shellSort(int arr[], int length)
{
    int interval, i, j, temp;
    for (interval = length / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < length; i++)
        {
            temp = arr[i];
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval)
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}
void display(int arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}