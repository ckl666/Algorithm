#include <stdio.h>

void Fun(int n)
{
    int f1 = 1;
    int f2 = 1;
    int f3 = 0;
    printf("%d %d ",f1,f2);
    int i = 3;
    for(i = 3; i <= n; i++)
    {
        f3 = f1+f2;
        printf("%d ",f3);
        f1 = f2;
        f2 = f3;
    }
    printf("\n");
} 

int main()
{
    int n = 10;
    Fun(n);
    return 0;
}
