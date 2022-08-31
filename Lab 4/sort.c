#include <stdio.h>
#define N 5
void sort(int arr[N]);
void display(int arr[N]);
int main()
{
    int arr[N] = {5, 3, 1, 2, 4};
    printf("Array before sorting : ");
    display(arr);
    sort(arr);
    printf("\nArray after sorting : ");
    display(arr);
    return 0;
}
void sort(int arr[N])
{
    int i, j, temp;
    for (i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (*(arr + j) > *(arr + (j + 1)))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + (j + 1));
                *(arr + (j + 1)) = temp;
            }
        }
    }
}
void display(int arr[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf(" %d", *(arr + i));
    }
}