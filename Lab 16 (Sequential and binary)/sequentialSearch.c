#include <stdio.h>
#define N 5
int linearSearch(int arr[], int length, int key);
int main()
{
    int arr[N] = {1, 2, 3, 4, 5}, result, input;
    printf("Enter element to search: ");
    scanf("%d", &input);
    result = linearSearch(arr, N, input);
    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", result + 1);
}
int linearSearch(int arr[], int length, int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == arr[i])
            return i;
    }
    return -1;
}