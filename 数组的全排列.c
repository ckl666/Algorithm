#include <stdio.h>

void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Show(int *a,int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void Fun(int *a,int i,int len)
{
    if(i >= len)
    {
        Show(a,len);
        return ;
    }
    int j = 0;
    for(j = i; j < len; j++)
    {
        //去除重复
        int k = 0;
        for(k = i; k < j; k++)
        {
            if(a[k] == a[j])
            {
                break;
            }
        }
        if(k >= j)
        {
            Swap(&a[i],&a[j]);
            Fun(a,i+1,len);
            Swap(&a[i],&a[j]);
        }
    }
}


int main()
{
    int arr[] = {1,1,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    Fun(arr,0,len);
    return 0;
}
