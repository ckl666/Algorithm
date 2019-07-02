#include <stdio.h>

#define MAX 100
#define INF 0x3f3f3f3f

int dp[MAX]; //dp[i]  表示从0-i的最少步数
int prev[MAX];

int Fun(int arr[],int len)
{
    int i = 0;
    int j = 0;
    dp[0] = 0;
    prev[0] = -1;
    for(i = 1; i <= len; i++)
    {
        int min = INF;
        for(j = 0; j < i; j++)
        {
            if(arr[j] >= i-j && min > dp[j]+1)
            {
                min = dp[j] + 1;
                prev[i] = j;
            }
        }
        if(min >= INF)
        {
            return -1;
        }
        else
        {
            dp[i] = min;
        }
    }
    return dp[len];
}

/*
//贪心算法
int Fun(int arr[],int len)
{
    int i = 0;
    int j = len;
    int k = 0;
    prev[0] = 0;
    while(j > 0)
    {
        int max = -1;
        for(i = j-1; i >= 0; i--)
        {
            if(arr[i] >= j-i)
            {
                max = i;
            }
        }
        if(max != -1)
        {
            prev[k++] = max;
            j = max;
        }
        else
        {
            return -1;
        }
    }
    return k;
}


void Show(int arr[],int n)
{
    int k = 0;
    while(k < n)
    {
        printf("%d ",prev[k]);
        k++;
    }
    printf("\n");
}
*/

int main()
{
    int arr[] = {2,0,1,1,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int n = Fun(arr,len);
    printf("%d \n",n);
    //Show(arr,n);
    return 0;
}
