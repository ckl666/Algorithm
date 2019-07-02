#include <queue>
#include <iostream>

using namespace std;

#define MAX 100
#define INF 0x3f3f3f3f

typedef struct Node
{
    int veo;
    int length;
    bool operator < (const Node &s)const
    {
        return length > s.length;
    }
}Node;

int prev[MAX] = {0};
int a[MAX][MAX] = {
    {0,INF,10,INF,30,100},
    {INF,0,4,INF,INF,INF},
    {INF,INF,0,50,INF,INF},
    {INF,INF,INF,0,INF,10},
    {INF,INF,INF,20,0,60},
    {INF,INF,INF,INF,INF,0}
};
int dist[MAX];

void DisplayPath(int k)
{
    int stack[MAX];
    int top = 0;
    stack[top++] = k;
    while(prev[k] != -1)
    {
        stack[top++] = prev[k];
        k = prev[k];
    }
    top--;
    while(top >= 0)
    {
        cout<<stack[top]<<" ";
        top--;
    }
}

void Display(int n)
{
    int i = 0;
    for(i = 1;i < n; i++)
    {
        if(dist[i] < INF)
        {
            cout<<"到顶点"<<i<<"的最短路径为"<<dist[i]<<"路径为";
            DisplayPath(i);
            cout<<endl;
        }
        else
        {
            cout<<"到顶点"<<i<<"没有路径"<<endl;
        }
    }
}



void Fun(int n)
{
    priority_queue<Node> qu;
    Node e;
    e.veo = 0;
    e.length = 0;
    qu.push(e);
    int i = 0;
    for(i = 0; i < n; i++)
    {
        dist[i] = INF;
    }
    prev[0] = -1;
    while(!qu.empty())
    {
        e = qu.top();
        qu.pop();
        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(i != e.veo && a[e.veo][i] < INF && e.length+a[e.veo][i] < dist[i])
            {
                Node s;
                dist[i] = e.length+a[e.veo][i];
                s.veo = i;
                s.length = dist[i];
                qu.push(s);
                prev[i] = e.veo;
            }
        }
    }
}


int main()
{
    int n = 6;
    Fun(n);
    Display(n);
    return 0;
}


