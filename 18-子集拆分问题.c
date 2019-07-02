#include <stdio.h>

#define MAX 39
//[1-n] 划分为两个集合使得集合元素的和相等

int dp[MAX][MAX]; //dp[n][m] 表示n个元素拆分和为m的个数
int count = 0;

int Sum(int n)
{
    int i = 0;
    int sum = 0;
    for(i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
//动态规划 O(n^3)
//O(n*mid) = O(n*n*(n-1)/4) = O(n^3)
int Fun(int n,int mid)
{
    int i = 0;
    int j = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= mid; j++)
        {
            if(j == i)
            {
                dp[i][j] = dp[i-1][j] + 1;
            }
            else if(j > i)
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][mid];
}

int main()
{
    int n = 7;
    if(Sum(n) % 2 != 0)
    {
        printf("%d \n",0);
    }
    else
    {
        int s = Fun(n,Sum(n)/2);
        printf("%d \n",s/2);
    }
    return 0;
}


//回溯算法 O(2^n)
/*
void Fun(int i,int n,int sum,int mid)
{
    if(i == n)
    {
        if(mid == sum)
        {
            count++;
        }
    }
    else
    {
        sum += i;
        Fun(i+1,n,sum,mid);
        sum -= i;
        Fun(i+1,n,sum,mid);
    }
}

int main()
{
    int n = 8;
    if(Sum(n) % 2 != 0)
    {
        printf("%d \n",count);
    }
    else
    {
        int mid = Sum(n)/2;
        Fun(1,n,0,mid);
        printf("%d \n",count);
    }
    return 0;
}
*/
