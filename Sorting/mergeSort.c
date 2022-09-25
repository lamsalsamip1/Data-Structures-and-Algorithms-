/*
MERGE SORT: Divide and conquer, divide into smallest array and merge them by sorting

TIME COMPLEXITY : Best Case Complexity: O(n*log n)

                  Worst Case Complexity: O(n*log n)

                  Average Case Complexity: O(n*log n)

SPACE COMPLEXITY: O(n)
*/
#include <stdio.h>
#define N 10
void display(int arr[], int length);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);
int main()
{
    int arr[N] = {10, 1, 2, 3, 9, 8, 7, 5, 6, 4};
    printf("Array before sorting: ");
    display(arr, N);
    mergeSort(arr, 0, N - 1);
    printf("\nArray after sorting: ");
    display(arr, N);
    return 0;
}
void merge(int arr[], int p, int q, int r)
{

    int n1, n2, i, j, k;

    // Create two copies of the sub arrays
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1], M[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        M[j] = arr[q + j + 1];
    }

    // reset index
    i = j = 0;
    k = p;

    // sort and merge the arrays
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = M[j++];
        }
    }

    // leftover elements insert at last

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = M[j++];
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // merge the sorted sub arrays
        merge(arr, l, m, r);
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