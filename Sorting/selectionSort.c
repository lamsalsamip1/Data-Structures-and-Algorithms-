/* SELECTION SORT

ALGORITHM:

1) Find the smallest element
2) Swap with leftmost component
3) Forget the first element and repeat

TIME COMPLEXITY:

-> (n-1)+(n-2)+(n-3)+...+1
-> O(n^2)

SPACE COMPLEXITY:

->O(1)

*/
#include <stdio.h>
#include <stdbool.h>
#define N 10
void selectionSort(int arr[], int length);
void display(int arr[], int length);
void swap(int *a, int *b);
int main()
{
    int arr[N] = {10, 1, 2, 3, 9, 8, 7, 5, 6, 4};
    printf("Array before sorting: ");
    display(arr, N);
    selectionSort(arr, N);
    printf("\nArray after sorting: ");
    display(arr, N);
    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int length)
{
    int i, j, min_index;
    for (i = 0; i < length - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < length; j++)
        {

            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
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