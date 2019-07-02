#include <stdio.h>

#define MAX 100
//取数组子序列之和等于sum的子序列的个数
int dp[MAX][MAX]; //dp[i][j] //包含和为j的前 i个元素和为sum 的个数


int Fun(int arr[],int len,int sum)
{
    int i = 0;
    int j = 0;
    for(j = 0; j <= sum; j++)
    {
        dp[0][j] = 0;
    }
    for(i = 1; i <= len; i++)
    {
        dp[i][0] = 0;
    }
    for(i = 1; i <= len; i++)
    {
        for(j = 1; j <= sum; j++)
        {
            if(j > arr[i])
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i]];
            }
            else if(j == arr[i])
            {
                dp[i][j] = dp[i-1][j] + 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[len][sum];
}

int main()
{
    int arr[] = {0,5,5,10,2,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum = 15;
    int n = Fun(arr,len,sum);
    printf("%d \n",n);
    return 0;
}
