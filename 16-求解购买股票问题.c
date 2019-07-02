#include <stdio.h>

#define MAX 100

#define max(x,y) ((x)>(y)?(x):(y))
//逢低吸纳
//求下降的最长序列
int Fun(int arr[],int len)
{
    int i = 0;
    int j = 0;
    int max = 0;
    int dp[MAX];    //以i结尾的最长的下降子序列的长度
    for(i = 1; i < len; i++)
    {
        dp[i] = 1;
        for(j = 0; j < i; j++)
        {
            if(arr[i] < arr[j])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int ans = 0;
    for(i = 0; i < len; i++)
    {
        ans = ans>dp[i]?ans:dp[i];
    }
    return ans;
}

int main()
{
    int arr[] = {68,69,54,64,68,64,70,67,78,62,98,87};
    int len = sizeof(arr)/sizeof(arr[0]);
    int n = Fun(arr,len);
    printf("%d \n",n);
    return 0;
}
