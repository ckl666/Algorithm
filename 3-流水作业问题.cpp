#include <iostream>
#include <queue>

#define MAX 10
#define max(x,y) (((x)>(y))?(x):(y))
#define INF 0x3f3f3f3f

using namespace std;

int a[] = {5,12,4,8};
int b[] = {6,2,14,7};
int Min = INF;
int best[MAX];

typedef struct Node
{
    int i;
    int x[MAX];
    bool work[MAX];
    int f1;
    int f2;
    int lb;
    bool operator<(const Node &s)const
    {
        return lb > s.lb;
    }
}Node;

void Show(int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        cout<<best[i]+1<<" ";
    }
    cout<<endl;
    cout<<"最短时间为:"<<Min<<endl;
}

void bound(Node &e,int n)
{
    int i = 0;
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        if(e.work[i])
        {
            sum += b[i];
        }
    }
    e.lb = e.f2+sum;
}

void Fun(int n)
{
    priority_queue<Node> qu;
    Node e;
    int i = 0;
    e.i = -1;
    e.f1 = 0;
    e.f2 = 0;
    for(i = 0; i < n; i++)
    {
        e.work[i] = false;
    }
    bound(e,n);
    qu.push(e);
    while(!qu.empty())
    {
        e = qu.top();
        qu.pop();
        if(e.i == n-1)
        {
            if(Min > e.f2)
            {
                Min = e.f2;
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
                e1.x[e1.i] = i;
                e1.f1 += a[i];
                e1.f2 = max(e.f2,e1.f1) + b[i];
                bound(e1,n);
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
