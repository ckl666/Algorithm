#include <stdio.h>
#include <assert.h>

#define MAX 100
#define max(x,y) (((x)>(y))?(x):(y))


int dp[MAX];

int Fun(int *arr,int len)
{
    int i = 0;
    dp[0] = arr[0];
    int m = dp[0];
    for(i = 1; i < len; i++)
    {
        dp[i] = max(dp[i-1]+arr[i],arr[i]);
        if(m < dp[i])
        {
            m = dp[i];
        }
    }
    return m;
}

void Show(int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ",dp[i]);
    }
    printf("\n");
}


int main()
{
    int arr[] = {1,2,3,-4,-3,3,-2,9,4,5,-8};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum = Fun(arr,len);
    printf("%d \n",sum);
    Show(len);
    return 0;
}
