#include <stdio.h>
#define N 3
void transpose(int arr[N][N], int trans[N][N]);
void display(int arr[N][N]);
int main()
{
    int arr[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        trans[N][N];
    transpose(arr, trans);
    printf("Transpose of matrix:\n");
    display(trans);
}
void transpose(int arr[N][N], int trans[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            *(*(trans + i) + j) = *(*(arr + j) + i);
        }
    }
}
void display(int arr[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        printf("\n");
        for (j = 0; j < N; j++)
        {
            printf(" %d", *(*(arr + i) + j));
        }
    }
}