#include <stdio.h>

#define MAX 100

int dp[MAX][MAX];

void Fun(int n,int k)
{
    int i = 0;
    int j = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= k; j++)
        {
            if(i == 1 || j == 1)
            {
                dp[i][j] = 1;
            }
            if(i < j)
            {
                dp[i][j] = dp[i][i];
            }
            if(i == j)
            {
                dp[i][j] = dp[i][j-1]+1;
            }
            if(i > j)
            {
                dp[i][j] = dp[i-j][j] + dp[i][j-1];
            }
        }
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
    Fun(n,k);
    Show(n,k);
    return 0;
}
