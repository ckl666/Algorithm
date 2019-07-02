#include <stdio.h>
#include <assert.h>

#define MAX 100
#define max(x,y) (((x)>(y))?(x):(y))

int Fun(int arr[],int len)
{
    assert(arr != NULL);
    int i = 0;
    int j = 0;
    int ans = 1;
    int dp[MAX] = {0};     //dp[i]表示以a[i]结尾的最长上升序列的长度
    for(i = 0; i < len; i++)
    {
        dp[i] = 1;
        for(j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    for(i = 0; i < len; i++)
    {
        ans = max(ans,dp[i]);
    }
    return ans;
}


/*
int Fun(int arr[],int len)
{
    assert(arr != NULL);
    int i = 0;
    int max = 1;
    int dp[MAX] = {0};
    dp[0] = arr[0];
    for(i = 1; i < len; i++)
    {
        if(arr[i] > dp[max-1])
        {
            dp[max++] = arr[i];
        }
        else
        {
            int j = max-1;
            for(j = 0; j < max; j++)
            {
                if(dp[j] >= arr[i])
                {
                    dp[j] = arr[i];
                    break;
                }
            }
        }
    }
    return max;
}
*/


int main()
{
    int arr[] = {1,2,3,4,6,2,3,4,1,2,3,4,5,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    int max = Fun(arr,len);
    printf("%d \n",max);
    return 0;
}
