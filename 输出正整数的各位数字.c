#include <stdio.h>

int Print(int n)
{
    if(n != 0)
    {
        Print(n/10);
        printf("%d ",n%10);
    }
}

int main()
{
    Print(123345);
    printf("\n");
    return 0;
}
