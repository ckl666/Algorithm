#include <stdio.h>
#include <queue>

#define INF 0x3f3f3f3f
#define MAX 20
#define N 7
using namespace std;



int H[] = {1,0,-1,0};
int V[] = {0,1,0,-1};

int Min = INF;
int best[MAX];          //存储路径，每次移动的方向
char map[][7] = {
    {'X','X','O','O','X','X','X'},
    {'X','X','X','O','X','X','X'},
    {'X','S','X','X','O','X','X'},
    {'X','X','X','O','O','E','X'},
    {'O','X','X','O','O','X','X'},
    {'O','O','X','X','X','X','X'},
    {'O','O','O','X','X','X','X'},
};

typedef struct node
{
    int count;      //步数
    int i;          //节点的坐标
    int j;          
    bool foot[N][N];
    int path[MAX];     //每次移动的方向 
}Node;

void Show(int n)
{

    printf("====================================\n");
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
}

void Change(int x,int y)
{
    int i = 0;
    if(Min >= INF)
    {
        return ;
    }
    for(i = 0; i < Min; i++)
    {
        map[x][y] = ' ';
        x += H[best[i]];
        y += V[best[i]];
    }
    printf("%d \n",Min);
}

void Fun(int x,int y,int n)
{
    Node e;
    queue<Node> qu;
    e.count = 0;
    e.i = 2;
    e.j = 1;
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            e.foot[i][j] = false;
        }
    }
    e.foot[e.i][e.j] = true;
    qu.push(e);
    while(!qu.empty())
    {
        e = qu.front();
        qu.pop();
        if(e.i == x && e.j == y)
        {
            if(e.count < Min)
            {
                Min = e.count;
                for(i = 0; i < e.count; i++)
                {
                    best[i] = e.path[i];
                }
            }
        }
        else
        {
            int k = 0;
            for(k = 0; k < 4; k++)
            {
                Node e1 = e;
                //剪枝
                if(e1.i+H[k] >= 0 && e1.i+H[k] < n && e1.j+V[k] >= 0 && e1.j+V[k] < n)
                {
                    if(e1.foot[e1.i+H[k]][e1.j+V[k]])
                    {
                        continue;
                    }
                    if(map[e1.i+H[k]][e1.j+V[k]] == 'X' || map[e1.i+H[k]][e1.j+V[k]] == 'E')
                    {
                        e1.i += H[k];
                        e1.j += V[k];
                        e1.foot[e1.i][e1.j] = true;
                        e1.path[e1.count] = k;
                        e1.count++;
                        if(e1.count < Min)
                        {
                            qu.push(e1);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n = 7;
    Show(n);
    Fun(3,5,n);
    Change(2,1);
    Show(n);
    return 0;
}
