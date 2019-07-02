#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX 100
#define max(x,y) (((x)>(y))?(x):(y))
int dp[MAX][MAX];

//连续

int Fun(char *str1,char *str2,int lenStr1,int lenStr2)
{
     assert(str1 != NULL && str2 != NULL);
    int i = 0;
    int j = 0;
    int longest = 0;
    for(i = 0; i < lenStr1; i++)
    {
        dp[0][i] = 0;
    }
    for(j = 0; j < lenStr2; j++)
    {
        dp[j][0] = 0;
    }
    for(i = 1; i <= lenStr1; i++)
    {
        for(j = 1; j <= lenStr2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(longest < dp[i][j])
                {
                    longest = dp[i][j];
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return longest;
}

//非连续
/*
int Fun(char *str1,char *str2,int lenStr1,int lenStr2)
{
    assert(str1 != NULL && str2 != NULL);
    int i = 0;
    int j = 0;
    for(i = 0; i < lenStr1; i++)
    {
        dp[0][i] = 0;
    }
    for(j = 0; j < lenStr2; j++)
    {
        dp[j][0] = 0;
    }
    for(i = 1; i <= lenStr1; i++)
    {
        for(j = 1; j <= lenStr2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[lenStr1][lenStr2];
}

void CreatSub(int k,char *sub,char *str1,char *str2,int lenStr1,int lenStr2)
{
    int i = lenStr1;
    int j = lenStr2;
    int index = 0;
    assert(sub != NULL && str1 != NULL && str2 != NULL);
    while(k > 0)
    {
        if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1])
        {
            j--;
        }
        else
        {
            sub[k-1] = str1[i-1];
            j--;
            i--;
            k--;
        }
    }
}
*/

int main()
{
    char str1[] = "qpwek";
    char str2[] = "qwewwd";
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    int n = Fun(str1,str2,lenStr1,lenStr2);
    printf("%d \n",n);
    //char sub[MAX] = {0};
    //CreatSub(n,sub,str1,str2,lenStr1,lenStr2);
    //printf("%s\n",sub);
    return 0;
}
