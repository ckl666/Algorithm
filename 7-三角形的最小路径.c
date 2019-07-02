#include <stdio.h>

#define MAX 100
#define N 6

#define min(x,y) (((x)>(y))?(y):(x))


int arr[N][N] = {
    {1,0,0,0,0,0},
    {3,2,0,0,0,0},
    {1,5,3,0,0,0},
    {4,8,6,4,0,0},
    {6,4,3,5,7,0},
    {2,4,3,4,5,8}
};

int dp[N][N];

int Fun()
{
    int i = 0;
    int j = 0;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = arr[0][0];
            }
            else if(j == 0)
            {
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else if(i == j)
            {
                dp[i][j] = dp[i-1][j-1]+arr[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + arr[i][j];
            }
        }
    }
}

void Show()
{
    int i = 0;
    int j = 0;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%-5d ",dp[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Fun();
    Show();
    return 0;
}
