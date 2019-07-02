#include <stdio.h>
#include <assert.h>

#define MAX 100
#define max(x,y) ((x)>(y)?(x):(y))

int dp[MAX][MAX]; 

/*
int Fun(int *w,int *v,int len,int W)
{
    assert(w != NULL && v != NULL);
    int i = 0;
    int r = 0;   //dp[i][r]  表示剩余r重量是前i个物品的最优价值
    for(i = 0; i <= len; i++)
    {
        dp[i][0] = 0;
    }
    for(r = 0; r <= W; r++)
    {
        dp[0][r] = 0;
    }
    for(i = 1; i <= len; i++)
    {
        for(r = 0; r <= W; r++)
        {
            if(r < w[i])
            {
                dp[i][r] = dp[i-1][r];
            }
            else
            {
                dp[i][r] = max(dp[i-1][r],dp[i][r-w[i]]+v[i]);
            }
        }
    }
    return dp[len][W];
}
*/

//滚动数组
int Fun(int *w,int *v,int len,int W)
{
    assert(w != NULL && v != NULL);
    int i = 0;
    int r = 0;   //dp[i][r]  表示剩余r重量是前i个物品的最优价值
    for(i = 0; i <= len; i++)
    {
        dp[i][0] = 0;
    }
    for(r = 0; r <= W; r++)
    {
        dp[0][r] = 0;
    }
    for(i = 1; i <= len; i++)
    {
        for(r = 0; r <= W; r++)
        {
            if(r < w[i])
            {
                dp[i%2][r] = dp[(i+1)%2][r];
            }
            else
            {
                dp[i%2][r] = max(dp[(i+1)%2][r],dp[i%2][r-w[i]]+v[i]);
            }
        }
    }
    return dp[len%2][W];
}



int main()
{
    int w[] = {2,2,6,5,4};
    int v[] = {6,3,5,4,6};
    int len = sizeof(w)/sizeof(w[0]);
    int W = 10;
    int m = Fun(w,v,len,W);
    printf("%d \n",m);
    return 0;
}
