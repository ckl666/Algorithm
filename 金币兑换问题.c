#include <stdio.h>

#define MAX 10

int arr[] = {1,2,5};

int a[MAX];

void Display(int n)
{
    int i = 0;
    for(i = 0; i < n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}


void Fun(int sum,int k)
{
    if(sum == 0)
    {
        Display(k);
    }
    else
    {
        int i = 0;
        for(i = 0; i < 3; i++)
        {
            if(k == 0)
            {
                if(sum-arr[i] >= 0)
                {
                    a[k] = arr[i];
                    Fun(sum-arr[i],k+1);
                }
            }
            else
            {
                if(sum-arr[i] >= 0 && a[k-1] <= arr[i])
                {
                    a[k] = arr[i];
                    Fun(sum-arr[i],k+1);
                }
            }
        }
    }
}

int main()
{
    Fun(MAX,0);
    return 0;
}
