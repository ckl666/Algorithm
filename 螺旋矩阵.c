#include <stdio.h>
#include <assert.h>

#define N 10


void HelixArr(int k,int start,int end,int arr[][N])
{
    if(start > end)
    {
        return ;
    }
    int i = start;
    int j = start;
    while(j <= end)
    {
        arr[i][j++] = k++;
    }
    j--;
    i++;
    while(i <= end)
    {
        arr[i++][j] = k++;
    }
    j--;
    i--;
    while(j >= start)
    {
        arr[i][j--] = k++;
    }
    j++;
    i--;
    while(i > start)
    {
        arr[i--][j] = k++;
    }
    HelixArr(k,start+1,end-1,arr);
}

/*
void HelixArr(int n,int arr[][N])
{
    int m = 0;
    int k = 1;
    int j = 0;
    int i = 0;
    while(k <= n*n)
    {
        while(j < n-m)
        {
            arr[i][j++] = k++;
        }
        i++;
        j--;
        while(i < n-m)
        {
            arr[i++][j] = k++;
        }
        j--;
        i--;
        while(j >= m)
        {
            arr[i][j--] = k++;
        }
        j++;
        i--;
        while(i > m)
        {
            arr[i--][j] = k++;
        }
        i++;
        j++;
        m++;
    }
}
*/

void Show(int arr[][N],int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        int j = 0;
        for(j = 0; j < n; j++)
        {
            printf("%5d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[N][N];
    //HelixArr(N,arr);
    HelixArr(1,0,N-1,arr);
    Show(arr,N);
    return 0;
}
