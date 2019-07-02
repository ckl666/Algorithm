#include <string.h>
#include <stdio.h>

#define MAX 100

int dp[MAX][MAX];

int Fun(int i,int j)
{
    if(dp[i][j] != 0)
    {
        return dp[i][j];
    }
    if(i == 1 || j == 1)
    {
        dp[i][j] = 1;
        return dp[i][j];
    }
    if(i < j)
    {
        dp[i][j] = Fun(i,i);
        return dp[i][j];
    }
    if(i == j)
    {
        dp[i][j] = Fun(i,j-1)+1;
        return dp[i][j];
    }
    if(i > j)
    {
        dp[i][j] = Fun(i-j,j)+Fun(i,j-1);
        return dp[i][j];
    }
}

void Show(int n,int k)
{
    int i = 0;
    int j = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= k; j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    int k = 5;
    memset(dp,0,sizeof(int)*MAX);
    Fun(n,k);
    Show(n,k);
    return 0;
}
