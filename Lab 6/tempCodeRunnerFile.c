#include <stdio.h>
void towerOfHanoi(int n, char from, char to, char aux);
int main()
{
    int num;
    printf("Enter the number of disks:");
    scanf("%d", &num);
    towerOfHanoi(num, 'A', 'C', 'B');
    return 0;
}
void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
        printf("Move disk 1 from tower %c to tower %c\n", from, to);
    else
    {
        towerOfHanoi(n - 1, from, aux, to);
        printf("Move disk %d from tower %c to tower %c\n", n, from, to);
        towerOfHanoi(n - 1, aux, to, from);
    }
}