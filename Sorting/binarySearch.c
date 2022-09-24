// Implementation of binary search

#include <stdio.h>
#define N 5
int binarySearch(int arr[], int length, int key);
int main()
{
    int arr[N] = {1, 2, 3, 4, 5}, result, input;
    printf("Enter element to search: ");
    scanf("%d", &input);
    result = binarySearch(arr, N, input);
    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", result + 1);
}
int binarySearch(int arr[], int length, int key)
{
    int low = 0, hi = length - 1, mid;
    while (low <= hi)
    {
        mid = (low + hi) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
        {
            hi = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
