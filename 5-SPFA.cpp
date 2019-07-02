#include <iostream>
#include <queue>

/*
0 4 -6 6 0 0 0
0 0 1 0 7 0 0
0 0 0 0 6 4 0
0 0 2 0 0 5 0
0 0 0 0 0 0 6
0 0 0 0 1 0 -8
0 0 0 0 0 0 0
*/

using namespace std;

const int NO_WAY = 0x3f3f3f3f;

typedef struct Node
{
    int index;
    int weight;
    struct Node *next;
}Node;

void ShowDistance(int *dis,int size)
{
    int i = 0;
    for(; i < size; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
}

void ShowPath(int *path,int key)
{
    cout << key << " ";
    while(path[key] != key)
    {
        cout << path[key] << " ";
        key = path[key];
    }
    cout << endl;
}

Node *SetMap(int size)
{
    Node *exec = new Node[size];
    int i = 0;
    for(; i < size; i++)
    {
        Node *p = &exec[i];
        p->index = i;
        p->next = NULL;
        int j = 0;
        for(; j < size; j++)
        {
            int data;
            cin >> data;
            if(data != 0)
            {
                Node *node = new Node;
                node->weight = data;
                node->index = j;
                node->next = NULL;
                p->next = node;
                p = node;
            }
        }
    }
    return exec;
}

void ShowMapExecl(Node *exec,int size)
{
    int i = 0;
    for(; i < size; i++)
    {
        Node *p = exec[i].next;
        while(p != NULL)
        {
            cout << p->weight << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void SPFA(Node *exec,int size)
{
    queue<Node> qu;
    int *dis = new int[size];
    int *path = new int[size];
    int *visit = new int[size];
    int i = 0;
    for(; i < size; i++)
    {
        dis[i] = NO_WAY;
        //visit[i] = 0;
    }
    path[0] = 0;
    visit[0] = 1;
    dis[0] = 0;
    qu.push(exec[0]);
    while(!qu.empty())
    {
        Node node = qu.front();
        qu.pop();
        Node *p = node.next;
        while(p != NULL)
        {
            if(dis[p->index] > dis[node.index] + p->weight)
            {
                dis[p->index] = dis[node.index] + p->weight;
                path[p->index] = node.index;
            }
            if(visit[p->index] == 0)
            {
                visit[p->index] = 1;
                qu.push(exec[p->index]);
            }
            p = p->next;
        }
    }
    ShowDistance(dis,size);
    for(i = 0; i < size; i++)
    {
        ShowPath(path,i);
    }
    delete []visit;
    delete []dis;
    delete []path;
    delete []exec;
}

int main()
{
    cout << "输入节点数:";
    int size;
    cin >> size;
    Node *exec = SetMap(size);
    //ShowMapExecl(exec,size);
    SPFA(exec,size);
    return 0;
}
