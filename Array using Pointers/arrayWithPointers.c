#include <stdio.h>
#define N 3
void sum(int arr1[N][N], int arr2[N][N], int sumMatrix[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            *(*(sumMatrix + i) + j) = *(*(arr1 + i) + j) + *(*(arr2 + i) + j);
        }
    }
}
void displayMatrix(int arr[N][N])
{
    int i, j;
    printf("Resulting matrix is:\n");
    for (i = 0; i < N; i++)
    {
        printf("\n");
        for (j = 0; j < N; j++)
        {
            printf(" %d", *(*(arr + i) + j));
        }
    }
}
int main()
{
    int arr1[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        arr2[N][N] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
        sumMatrix[N][N];
    sum(arr1, arr2, sumMatrix);
    displayMatrix(sumMatrix);
    return 0;
}
