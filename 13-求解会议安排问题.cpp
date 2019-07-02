#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 100

using namespace std;


typedef struct Node
{
    int begin;
    int end;
    bool operator < (const Node &s) const
    {
        return end < s.end;
    }
}Node;

int dp[MAX];
int prev[MAX];

int Fun(Node e[],int n)
{
    int i = 0;
    dp[0] = e[0].end-e[0].begin;
    prev[0] = -1;
    int j = 0;
    for(i = 1; i < n; i++)
    { 
        for(j = i-1; j >= 0; j--)
        {
            if(e[i].begin >= e[j].end)
            {
                if(dp[i-1] > dp[j]+e[i].end-e[i].begin)
                {
                    dp[i] = dp[i-1];
                    prev[i] = -2;
                }
                else
                {
                    dp[i] = dp[j]+e[i].end-e[i].begin;
                    prev[i] = j;
                }
                break;
            }
        }
        if(j <= 0)
        {
            if(dp[i-1] > e[i].end-e[i].begin)
            {
                prev[i] = -2;
                dp[i] = dp[i-1];
            }
            else
            {
                prev[i] = -1;
                dp[i] = e[i].end-e[i].begin;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        cout<<prev[i]<<" ";
    }
    cout<<endl;
    return dp[n-1];
}

void Display(Node e[],int n)
{
    n--;
    while(n != -1)
    {
        while(prev[n] == -2)
        {
            n--;
        }
        if(n >= 0)
        {
            cout<<'['<<e[n].begin<<','<<e[n].end<<']'<<endl;
            n = prev[n];
        }
    }
}

int main()
{
    Node e[] = {
        {1,4},
        {3,5},
        {0,6},
        {5,7},
        {3,8},
        {5,9},
        {6,10},
        {8,11},
        {8,12},
        {2,13},
        {12,15}
    };
    int len = sizeof(e)/sizeof(e[0]);
    sort(e,e+len);
    int m = Fun(e,len);
    Display(e,len);
    cout<<m<<endl;
    return 0;
}
