#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 100

int maxv = 0;
int best[MAX] = {0};

/*
typedef struct 
{
    int i;
    int w;
    int v;
    int ub;
    int x[MAX];
}Node;
*/


typedef struct Node
{
    int i;
    int w;
    int v;
    int ub;
    int x[MAX];
    bool operator <(const Node &s)const
    {
        return ub<s.ub;
    }
}Node;


void Show(int len,int w[],int v[])
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(best[i] == 1)
        {
            printf("重量：%d    价值：%d\n",w[i],v[i]);
        }
    }
    printf("总价值:%d \n",maxv);
}


void bound(Node &e,int w[],int v[],int len,int W)
{
    int sumw = e.w;
    int sumv = e.v;
    int i = e.i+1;
    while(sumw <= W && i<= len)
    {
        sumw += w[i];
        sumv += v[i];
        i++;
    }
    if(i <= len)
    {
        e.ub = sumv +(W-sumw)*w[i]/v[i];
    }
    else
    {
        e.ub = sumv;
    }
}

void EnQueue(priority_queue<Node> &qu,Node e,int n)
{
    int i = 0;
    if(e.i == n)
    {
        if(maxv < e.v)
        {
            maxv = e.v;
            for(i = 0; i < n; i++)
            {
                best[i] = e.x[i];
            }
        }
    }
    qu.push(e);
}
/*
void EnQueue(queue<Node> &qu,Node e,int n)
{
    int i = 0;
    if(e.i == n)
    {
        if(maxv < e.v)
        {
            maxv = e.v;
            for(i = 0; i < n; i++)
            {
                best[i] = e.x[i];
            }
        }
    }
    qu.push(e);
}
*/

void Fun(int w[],int v[],int len,int W)
{
    Node e,el,er;
    e.i = -1;
    e.w = 0;
    e.v = 0;
    priority_queue<Node> qu;
    bound(e,w,v,len,W);
    EnQueue(qu,e,len);
    while(!qu.empty())
    {
        e = qu.top();
        qu.pop();
        el = e;
        if(el.w+w[el.i+1] <= W)
        {
            el.i++;
            el.w += w[el.i];
            el.v += v[el.i];
            el.x[el.i] = 1;
            bound(el,w,v,len,W);
            EnQueue(qu,el,len);
        }
        er = e;
        er.i++;
        er.x[er.i] = 0;
        bound(er,w,v,len,W);
        if(er.ub > maxv)
        {
            EnQueue(qu,er,len);
        }
    }
}
/*
void Fun(int w[],int v[],int len,int W)
{
    Node e,el,er;
    e.i = -1;
    e.w = 0;
    e.v = 0;
    queue<Node> qu;
    bound(e,w,v,len,W);
    EnQueue(qu,e,len);
    while(!qu.empty())
    {
        e = qu.front();
        qu.pop();
        el = e;
        if(el.w+w[el.i+1] <= W)
        {
            el.i++;
            el.w += w[el.i];
            el.v += v[el.i];
            el.x[el.i] = 1;
            bound(el,w,v,len,W);
            EnQueue(qu,el,len);
        }
        er = e;
        er.i++;
        er.x[er.i] = 0;
        bound(er,w,v,len,W);
        if(er.ub > maxv)
        {
            EnQueue(qu,er,len);
        }
    }
}
*/
int main()
{
    int v[] = {45,25,25};
    int w[] = {16,15,15};
    int len = sizeof(w)/sizeof(w[0]);
    int W = 30;
    Fun(w,v,len,W);
    Show(len,w,v);
    return 0;
}
