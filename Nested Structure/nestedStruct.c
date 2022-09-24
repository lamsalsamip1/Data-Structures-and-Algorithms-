#include <stdio.h>
#define N 5
struct employee
{
    int eid;
    char name[20];
    struct address
    {
        char district[25];
        char country[30];
    } A;
};
int main()
{
    struct employee E[N];
    for (int i = 0; i < N; i++)
    {
        printf("Enter employee ID, Name and Address(District and
               Country) :\n ");
                          scanf("%d%s%s%s", &E[i].eid, E[i].name, E[i].A.district,
                                E[i].A.country);
    }
    printf("*****STORED INFORMATION IS********\n");
    printf("ID\tName\t\tAddress\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t%s\t\t%s,%s\n", E[i].eid, E[i].name, E[i].A.district,
               E[i].A.country);
    }
    return 0;
}
