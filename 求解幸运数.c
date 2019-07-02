#include <stdio.h>
#include <assert.h>


int Dec(int n)
{
    if(n != 0)
    {
        return Dec(n/10) + n%10;
    }
    else
    {
        return 0;
    }
}

int Bin(int n)
{
    if(n != 0)
    {
        return Bin(n/2) + n%2;
    }
    else
    {
        return 0;
    }
}

int LuckyNum(int n)
{
    if(n <= 0)
    {
        printf("\n");
        return 0;
    }
    if(Bin(n) == Dec(n))
    {
        printf("%d ",n);
        return LuckyNum(n-1) + 1;
    }
    else
    {
        return LuckyNum(n-1);
    }
}


int main()
{
    printf("%d \n",LuckyNum(10000));
    return 0;
}
