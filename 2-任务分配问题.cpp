#include <iostream>
#include <queue>
#include <stdio.h>

#define MAX 10
#define INF 0x3f3f3f3f
using namespace std;

bool work[MAX] = {false};
int best[MAX];

int arr[MAX][MAX] = {
    {9,2,7,8},
    {6,4,3,7},
    {5,8,1,8},
    {7,6,9,4}
};
int Min = INF;

typedef struct Node
{
    int i;
    int x[MAX];
    bool work[MAX];
    int cost;
    int lb;
    bool operator < (const Node &s)const
    {
        return lb > s.lb;
    }
}Node;


void Show(int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("%d ",best[i]);
    }
    printf("\n最低成本为:%d \n",Min);
}

void Bound(Node &e,int n)
{
    int i = 0;
    int minsum = 0;
    for(i = e.i+1; i < n; i++)
    {
        int j = 0;
        int mina = INF;
        for(j = 0; j < n; j++)
        {
            if(!work[j] && arr[i][j] < mina)
            {
                mina = arr[i][j];
            }
        }
        minsum += mina;
    }
    e.lb = e.cost + minsum;
}


void Fun(int n)
{
    priority_queue<Node> qu;
    int i = 0;
    Node e;
    for(i = 0; i < n; i++)
    {
        e.work[i] = false;
    }
    e.i = -1;
    e.cost = 0;
    Bound(e,n);
    qu.push(e);
    while(!qu.empty())
    {
        e = qu.top();
        qu.pop();
        if(e.i == n-1)
        {
            if(Min > e.cost)
            {
                Min = e.cost;
                for(i = 0; i < n; i++)
                {
                    best[i] = e.x[i];
                }
            }
        }
        else
        {
            for(i = 0; i < n; i++)
            {
                if(e.work[i])
                {
                    continue;
                }
                Node e1 = e;
                e1.i++;
                e1.work[i] = true;
                e1.cost += arr[e1.i][i];
                e1.x[e1.i] = i;
                Bound(e1,n);
                if(Min > e1.lb)
                {
                    qu.push(e1);
                }
            }
        }
    }
}

int main()
{
    int n = 4;
    Fun(n);
    Show(n);
    return 0;
}
