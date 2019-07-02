#include <queue>
#include <iostream>
#include <vector>
#include <stdlib.h>

#define MAX 100
using namespace std;

int H[] = {1,0,-1,0};
int V[] = {0,1,0,-1};

typedef struct Node
{
    int x;
    int y;
    int dist;
}Node;

int CDist(vector<Node> e,int x,int y)
{
    int i = 0;
    int sum = 0;
    for(i = 0; i < e.size(); i++)
    {
        sum += abs(x-e[i].x);
        sum += abs(y-e[i].y);
    }
    return sum;
}

Node Fun(vector<Node> &e)
{
    Node node = e[0];
    while(true)
    {
        int k = 0;
        for(k = 0; k < 4; k++)
        {
            int newdist = CDist(e,node.x+H[k],node.y+V[k]);
            if(newdist < node.dist)
            {
                node.dist = newdist;
                node.x += H[k];
                node.y += V[k];
                break;
            }
        }
        if(k >= 4)
        {
            return node;
        }
    }
}

int main()
{
    vector<Node> e;
    int x,y,n;
    cout<<"输入商店数:";
    cin>>n;
    while(n > 0)
    {
        cin>>x>>y;
        Node node;
        node.x = x;
        node.y = y;
        e.push_back(node);
        n--;
    }
    e[0].dist = CDist(e,e[0].x,e[0].y);
    Node node = Fun(e);
    cout<<"最佳位置:"<<node.x<<" "<<node.y<<endl;
    cout<<"总距离为:"<<node.dist<<endl;
    return 0;
}
