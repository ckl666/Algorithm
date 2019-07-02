#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100
#define N 5
#define INF 0x3f3f3f3f

//并查集查找时间复杂度位log n
//并查集实现
typedef struct Node
{
    int node;       //编号
    int rank;       //节点对应的秩（表示树的深度）
    int parent;     //双亲节点
}Node;

typedef struct Erge
{
    int u;          //边链接的一个顶点
    int v;          //边链接的第二个顶点
    int w;          //边的权值
    //按权值升序排列
    bool operator <(const Erge &s)const
    {
        return w>s.w;
    }
}Erge;

int map[MAX][MAX] = {
    {0,INF,3,INF,10},
    {INF,0,2,INF,INF},
    {3,2,0,INF,INF},
    {INF,5,INF,0,INF},
    {INF,INF,INF,3,0},
};

//返回并查集的根节点
static int FindNode(vector<Node> &node,int x)
{
    if(node[x].node == node[x].parent)
    {
        return x;
    }
    else
    {
        return FindNode(node,node[x].parent);
    }
}

bool SetNode(vector<Node> &node,int x,int y)
{
    if(x >= node.size() || y >= node.size())
    {
        return false;
    }
    if(node[x].rank > node[y].rank)
    {
        node[y].parent = x;
    }
    else
    {
        node[x].parent = y;
        if(node[x].rank == node[y].rank)
        {
            node[x].rank++;
        }
    }
    return true;
}

void Init(priority_queue<Erge> &erge,vector<Node> &node)
{
    int i = 0;
    int j = 0;
    Erge e;
    Node n;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < i; j++)
        {
            e.u = i;
            e.v = j;
            e.w = map[i][j];
            erge.push(e);
        }
        n.parent = i;
        n.node = i;
        n.rank = 1;
        node.push_back(n);
    }
}

void Kruskal(priority_queue<Erge> &erge,vector<Node> &node)
{
    while(!erge.empty())
    {
        Erge er = erge.top();
        int u = FindNode(node,er.u);
        int v = FindNode(node,er.v);
        if(u != v)
        {
            SetNode(node,u,v);
            cout << "("<< u <<","<< v <<")"<<endl;
        }
        erge.pop();
    }
}

int main()
{
    vector<Node> node;
    priority_queue<Erge> erge;
    Init(erge,node);
    Kruskal(erge,node);
    return 0;
}
