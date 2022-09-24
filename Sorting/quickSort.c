
/* Quick sort in C -> Divide and Conquer method, Unstable

TIME COMPLEXITY: 1) Best case -> O(n*logn)
                 2) Worst case -> O(n^2)
                 3) Average case -> O(n*logn)

SPACE COMPLEXITY: O(logn)


Note: Stable sorting algorithms preserve the relative order of equal elements,
      while unstable sorting algorithms don't. In other words,stable sorting
      maintains the position of two equals elements relative to one another.

*/
#include <stdio.h>
#define N 10
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
int main()
{
    int arr[N] = {10, 1, 2, 3, 9, 8, 7, 5, 6, 4};
    printf("Array before sorting: ");
    display(arr, N);
    quickSort(arr, 0, N - 1);
    printf("\nArray after sorting: ");
    display(arr, N);
    return 0;
}
int partition(int arr[], int low, int high)
{
    int i, j, pivot;
    i = low - 1;
    pivot = arr[high];

    for (j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int pi = partition(arr, low, high);

        // recursive call on left side of array
        quickSort(arr, low, pi - 1);

        // recursive call on right side of array
        quickSort(arr, pi + 1, high);
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