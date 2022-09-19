/*  BUBBLE SORT

Time complexity:

1) Normal bubble sort -> (n-1)*(n-1)
                      -> (n-1)^2
                      ->n^2-2n+1
                      = O(n^2) (Worst case)

2) Optimized bubble sort (with swapped variable & i-length-1):
                      -> (n-1)+(n-2)+(n-3)+...(n-k)
                      = O(n^2)

Space complexity = O(1) for normal, O(2) for optimized
*/
#include <stdio.h>
#include <stdbool.h>
#define N 10
void bubbleSort(int arr[], int length);
void display(int arr[], int length);
int main()
{
    int arr[N] = {10, 1, 2, 3, 9, 8, 7, 5, 6, 4};
    printf("Array before sorting: ");
    display(arr, N);
    bubbleSort(arr, N);
    printf("\nArray after sorting: ");
    display(arr, N);
    return 0;
}
void bubbleSort(int arr[], int length)
{
    int i, j, temp;
    bool switched = true;
    for (i = 0; i < length - 1 && switched == true; i++)
    {
        switched = false;
        for (j = 0; j < length - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                switched = true;
            }
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