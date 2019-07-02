#include <stdio.h>

#define MAX 10
#define N 4

int dp[MAX][MAX];   //dp[i][j] 表示0 0 到 i j的最短路径

int prevx[MAX];    //存移动的方向
int prevy[MAX];

//递推式
//边界条件 dp[i][0] = dp[i-1][0] + map[i][0]
//         dp[0][j] = dp[0][j-1] + map[0][j]
//dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + map[i][j]

int map[MAX][MAX] = {
    {1,3,5,9},
    {8,1,3,4},
    {5,0,6,1},
    {8,8,4,0}
};

/*
void Display()
{
    int i = N-1;
    int j = N-1;
    while(prevx[i] != -1)
    {
         printf("%d->",map[i][j]);
         i = prevx[i];
         j = prevy[j];
    }
    printf("%d\n",map[i][j]);
}
*/

int Fun()
{
    int i = 0;
    int j = 0;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = map[i][j];
                prevx[i] = -1;
                prevy[i] = -1;
            }
            else if(i == 0)
            {
                dp[i][j] = map[0][j] + dp[0][j-1];
                prevx[i] = 0;
                prevy[i] = j-1;
            }
            else if(j == 0)
            {
                dp[i][j] = map[i][0] + dp[i-1][0];
                prevx[i] = i-1;
                prevy[i] = 0;
            }
            else
            {
                if(dp[i][j-1] < dp[i-1][j])
                {
                    dp[i][j] = dp[i][j-1] + map[i][j];
                    prevx[i] = i;
                    prevy[i] = j-1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + map[i][j];
                    prevx[i] = i-1;
                    prevy[i] = j;
                }
            }
        }
    }
    return dp[N-1][N-1];
}

int main()
{
    int n = Fun();
    //Display();
    printf("%d \n",n);
    return 0;
}
