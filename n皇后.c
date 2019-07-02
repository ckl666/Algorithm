#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

#define N 4

void Show(int *p)
{
    int i = 0;
    for(i = 0; i < N; i++)
    {
        printf("%d ",p[i]+1);
    }
    printf("\n");
}

bool Place(int j,int k,int *p)
{
    int i = 0;
    for(i = 0; i < k; i++)
    {
        if(p[i] == j || abs(p[i]-j) == abs(k-i))    //列数相减，行数相减
        {
            return false;
        }
    }
    return true;
}


void Fun(int i,int *p)
{
    if(i >= N)
    {
        Show(p);
        return;
    }
    else
    {
        int j = 0;
        for(j = 0; j < N; j++)
        {
            if(Place(j,i,p))
            {
                p[i] = j;
                Fun(i+1,p);
            }
        }
    }
}

int main()
{
    int p[N];
    Fun(0,p);
    return 0;
}
