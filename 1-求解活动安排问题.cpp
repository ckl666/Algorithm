#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

typedef struct Node
{
    int start;
    int end;
    bool operator < (const Node &s)const
    {
        return end > s.end;
    }
}Node;

void Init(priority_queue<Node> &qu)
{
    int n;
    cout<<"输入活动数:";
    cin>>n;
    Node node;
    int s,e;
    while(n > 0)
    {
        cin>>s>>e;
        node.start = s;
        node.end = e;
        qu.push(node);
        n--;
    }
}

void Fun(priority_queue<Node> qu)
{
    int i = 0;
    int preed = 0;
    Node node;
    int len = qu.size();
    int count = 0;
    for(i = 0; i < len; i++)
    {
        node = qu.top();
        qu.pop();
        if(preed < node.start)
        {
            count++;
            cout<<node.start<<" "<<node.end<<endl;
            preed = node.end;
        }
    }
    cout<<count<<endl;
}

int main()
{
    priority_queue<Node> qu;
    Init(qu);
    Fun(qu);
    return 0;
}
