#include <iostream>
#include <queue>
#include <vector>

#define MAX 100
#define INF 0x3f3f3f3f

using namespace std;

int best[MAX];
int Min = INF;

int arr[][3] = {
    {1,2,3},
    {3,2,1},
    {2,3,2}
};    //存放重量
int brr[][3] = {
    {1,2,3},
    {5,4,2},
    {2,1,2}
};    //存放价格

typedef struct Node
{
    int i;              //当前零件的标号
    int x[MAX];         //当前零件选择的零售商标号
    int cost;           //当前选择的零件的总花费
    int w;              //当前的零件的总重量
    int lb;             //重量的下限值
    bool operator < (const Node &s)const
    {
        return lb > s.lb;
    }
}Node;

void Bound(Node &e,int n,int m)
{
    int sum = 0;
    int i = 0;
    for(i = e.i+1; i < n; i++)
    {
        int j = 0;
        int minm = INF;
        for(j = 0; j < m; j++)
        {
            if(minm > arr[i][j])
            {
                minm = arr[i][j];
            }
        }
        sum += minm;
    }
    e.lb = e.w+sum;
}

void Show(int m)
{
    int i = 0;
    for(i = 0; i < m; i++)
    {
        cout<<best[i]+1<<" ";
    }
    cout<<endl;
    cout<<Min<<endl;
}

int Fun(int C,int n,int m)
{
    Node e;
    priority_queue<Node> qu;
    e.i = -1;
    e.cost = 0;
    e.w = 0;
    int i = 0;
    Bound(e,n,m);
    qu.push(e);
    while(!qu.empty())
    {
        e = qu.top();
        qu.pop();
        if(e.i == n-1)
        {
            if(e.w < Min)
            {
                Min = e.w;
                for(i = 0; i < m; i++)
                {
                    best[i] = e.x[i];
                }
            }
        }
        else
        {
            for(i = 0; i < m; i++)
            {
                Node e1 = e;
                if(e1.cost+brr[e1.i+1][i] > C)
                {
                    continue;
                }
                e1.i++;
                e1.cost += brr[e1.i][i];
                e1.x[e1.i] = i;
                e1.w += arr[e1.i][i];
                Bound(e1,n,m);
                if(e1.lb < Min)
                {
                    qu.push(e1);
                }
            }
        }
    }
}

int main()
{
    int C = 7;
    Fun(C,3,3);
    Show(3);
    return 0;
}
