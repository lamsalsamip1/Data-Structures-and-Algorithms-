#include <iostream>
#define N 3
using namespace std;
void transpose(int arr[N][N], int trans[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            trans[i][j] = arr[j][i];
        }
    }
}
void addMatrix(int arr1[N][N], int arr2[N][N], int sum[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}
void displayMatrix(int arr[N][N])
{
    int i, j;
    cout << "\nResulting matrix is:" << endl;
    for (i = 0; i < N; i++)
    {
        cout << endl;
        for (j = 0; j < N; j++)
        {
            cout << " " << arr[i][j];
        }
    }
}
int main()
{
    int arr1[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        arr2[N][N] = {{1, 0, 1}, {0, 1, 0}, {0, 0, 1}},
        trans[N][N], sum[N][N];
    transpose(arr1, trans);
    addMatrix(trans, arr2, sum);
    displayMatrix(sum);
    return 0;
}