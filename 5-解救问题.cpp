#include <iostream>
#include <queue>
#include <vector>

#define MAX 100
using namespace std;

//四个方向
int H[] = {1,0,-1,0};
int V[] = {0,1,0,-1};

typedef struct Node
{
    int x;
    int y;
    int life;           //血条
    bool foot[MAX][MAX];
}Node;

void Show(int n,vector<vector<char> > map)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool Fun(int x,int y,int n,vector<vector<char> > map)
{
    Node e;
    queue<Node> qu;
    e.x = x;
    e.y = y;
    e.life = 2;
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            e.foot[i][j] = false;
        }
    }
    e.foot[e.x][e.y] = true;
    qu.push(e);
    while(!qu.empty())
    {
        e = qu.front();
        qu.pop();
        int k = 0;
        for(k = 0; k < 4; k++)
        {
            Node e1 = e;
            if(e1.x+H[k] >= 0 && e1.x+H[k] < n && e1.y+V[k] >= 0 && e1.y+V[k] <n)
            {
                if(e1.foot[e1.x+H[k]][e1.y+V[k]] || (map[e1.x+H[k]][e1.y+V[k]] == 'd' && e1.life <= 1) ||map[e1.x+H[k]][e1.y+V[k]] == 'k')
                {
                    continue;
                }
                else if(map[e1.x+H[k]][e1.y+V[k]] == 'a')
                {
                    return true;
                }
                else if(map[e1.x+H[k]][e1.y+V[k]] == 'd' && e1.life > 1)
                {
                    e1.life--; 
                }
                e1.x += H[k];
                e1.y += V[k];
                e1.foot[e1.x][e1.y] = true;
                qu.push(e1);
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char> > map;
    int n;
    char ch;
    cout<<"输入地图的大小:";
    cin>>n;
    vector<char> vec;
    int i = 0;
    int j = 0;
    for(i = 0;i < n; i++)
    {
        for(j = 0;j < n; j++)
        {
            cin>>ch;
            vec.push_back(ch);
        }
        map.push_back(vec);
        vec.clear();
    }
    Show(n,map);
    if(Fun(0,0,n,map))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
