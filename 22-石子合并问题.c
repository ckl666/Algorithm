#include <stdio.h>

#define MAX 100
#define INF 0x3f3f3f3f

#define min(x,y) ((x)>(y)?(y):(x))

//未完成
//
int dp[MAX][MAX];  //dp[i][j]表示i到j堆的最优消耗 

int Weight(int i,int j,int arr[])
{
    int sum = 0;
    while(i <= j)
    {
        sum += arr[i++];
    }
    return sum;
}

int Fun(int arr[],int len)
{
    int i = 0;
    int j = 0;
    int k = 0;
    for(i = 0; i < len; i++)
    {
        j = i+v
        for(j = i; j < len; j++)
        {
            if(i == j)
            {
                dp[i][j] == 0;
            }
            else
            {
                int Min = INF;
                for(k = i; k < j; k++)
                {
                    if(Min > dp[i][k]+dp[k+1][j] + Weight(i,j,arr))
                    {
                        Min = dp[i][k]+dp[k+1][j] + Weight(i,j,arr);
                    }
                }
                dp[i][j] = Min; 
            }
        }
    }
    return dp[0][len-1];
}

int main()
{
    int arr[] = {13,7,8,16,21,4,18};
    int len = sizeof(arr)/sizeof(arr[0]);
    int n = Fun(arr,len);
    printf("%d \n",n);
    return 0;
}

