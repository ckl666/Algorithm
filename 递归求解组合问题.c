#include <stdio.h>

#define MAX 100

int a[MAX];
int k;
int n;
void Disp()
{
    int i = 0;
    printf("{ ");
    for(i = 0; i < k; i++)
    {
        printf("%d ",a[i]);
    }
    printf("}\n");
}

void Comb(int n,int k)
{
    if(k == 0)
    {
        Disp();
    }
    else
    {
        int i = 0;
        for(i = k; i <= n; i++)
        {
            a[k-1] = i;
            Comb(i-1,k-1);
        }
    }
}

int main()
{
    n = 5;
    k = 3;
    Comb(n,k);
    return 0;
}
