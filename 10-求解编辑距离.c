#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX 100

int Min(int a,int b,int c)
{
    a = a>b?b:a;
    a = a>c?c:a;
    return a;
}

int Fun(char *str1,char *str2)
{
    assert(str1 != NULL && str2 != NULL);
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    int dp[MAX][MAX] = {0}; //dp[i][j] 表示str1 取前i个str2 取前j 个时最小的替换次数
    int i = 0;
    int j = 0;
    for(i = 0; i <= lenStr1; i++)
    {
        dp[i][0] = i;
    }
    for(i = 0; i <= lenStr2; i++)
    {
        dp[0][i] = i;
    }
    for(i = 1; i <= lenStr1; i++)
    {
        for(j = 1; j <= lenStr2; j++)
        {
            if(str1[i-1] ==str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = Min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1;
            }
        }
    }
    return dp[lenStr1][lenStr2];
}


int main()
{
    char str1[] = "qwerqw";
    char str2[] = "qwfriqw";
    int max = Fun(str1,str2);
    printf("%d \n",max);
    return 0;
}
