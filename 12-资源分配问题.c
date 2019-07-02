#include <stdio.h>

#define MAX 100

int arr[][MAX] = {
    {0},
    {0,3,7,9,12,13},
    {0,5,10,11,11,11},
    {0,4,6,11,12,12},
};

int dp[MAX][MAX];
int pnum[MAX][MAX];

void Fun(int n,int m)
{
    int i = 0;
    int j = 0;
    int s = 0;
    for(i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for(i = 1; i <= m; i++)
    {
        int maxf = 0;
        int maxj = 0;
        for(s = 0; s <= n; s++)
        {
            //选择前1-i个商店s个人的最大收益
            for(j = 0; j <= s; j++)
            {
                if(maxf < dp[i-1][s-j] + arr[i][j])
                {
                    maxf = dp[i-1][s-j] + arr[i][j];
                    maxj = j;
                }
            }
            pnum[i][s] = maxj;
            dp[i][s] = maxf;
        }
    }
}

void Show(int n,int m)
{
    while(m > 0)
    {
        printf("商店%d 分配的人数%d \n",m,pnum[m][n]);
        n = n-pnum[m][n];
        m--;
    }
}

int main()
{
    int n = 5;
    int m = 3;
    Fun(n,m);
    Show(n,m);
    printf("总收益:%d \n",dp[m][n]);
    return 0;
}
