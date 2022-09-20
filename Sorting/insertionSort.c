/*

INSERTION SORT -> LIKE SORTING CARDS IN HAND, ASSUME FIRST ELEMENT IS SORTED AND INSERT ACCORDINGLY

TIME COMPLEXITY -> Best case = O(n)
                   Worst case = (n-1)+(n-2)+...+3+2+1=(n-1)*n/2
                              -> O(n^2)

SPACE COMPLEXITY -> O(1)

Better than bubble sort because the closer the file is to the sorted order, more efficient it becomes.
*/

#include <stdio.h>
#define N 10
void insertionSort(int arr[], int length);
void display(int arr[], int length);
int main()
{
    int arr[N] = {10, 1, 2, 3, 9, 8, 7, 5, 6, 4};
    printf("Array before sorting: ");
    display(arr, N);
    insertionSort(arr, N);
    printf("\nArray after sorting: ");
    display(arr, N);
    return 0;
}

void insertionSort(int arr[], int length)
{
    int i, key, j;
    for (i = 1; i < length; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && key < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
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