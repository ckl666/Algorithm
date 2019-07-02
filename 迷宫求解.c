#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int H[] = {0,1,0,-1};
int V[] = {1,0,-1,0};

char map[MAX][MAX]={{'X','X','X','X','X','X','X','X','X','X'},
                    {'X','O','X','O','O','O','X','X','X','X'},
                    {'X','O','O','O','O','O','X','X','X','X'},
                    {'X','X','O','X','X','X','X','X','X','X'},
                    {'X','O','O','O','O','X','X','X','X','X'},
                    {'X','O','X','X','O','X','X','X','X','X'},
                    {'X','O','X','X','O','O','X','X','X','X'},
                    {'X','O','X','X','X','O','O','O','X','X'},
                    {'X','O','O','O','O','O','X','O','O','X'},
                    {'X','X','X','X','X','X','X','X','X','X'}
                    };

void Show()
{
    printf("============================\n");
    int i = 0;
    for(i = 0; i < MAX; i++)
    {
        int j = 0;
        for(j = 0; j < MAX; j++)
        {
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
}


//深度优先
void DFS(int x,int y)
{
    if(x == MAX-2 && y == MAX-2)
    {
        map[MAX-2][MAX-2] = ' ';
        Show();
        return;
    }
    int k = 0;
    for(k = 0; k < 4; k++)
    {
        if(x>0 && y>0 && map[x][y] == 'O')
        {
            map[x][y] = ' ';
            DFS(x+V[k],y+H[k]);
            map[x][y] = 'O';
        }
    }
}

//广度优先
typedef struct
{
    int x;
    int y;
    int pre;
}queue;

queue qu[MAX*MAX] = {0};
int front = 0;
int tail = 0;

/*
 
char map[MAX][MAX]={{'X','X','X','X','X','X','X','X','X','X'},
                    {'X','O','X','O','O','O','X','X','X','X'},
                    {'X','O','O','O','O','O','X','X','X','X'},
                    {'X','X','O','X','X','X','X','X','X','X'},
                    {'X','O','O','O','O','X','X','X','X','X'},
                    {'X','O','X','X','O','X','X','X','X','X'},
                    {'X','O','X','X','O','O','X','X','X','X'},
                    {'X','O','X','X','X','O','O','O','X','X'},
                    {'X','O','O','O','O','O','X','O','O','X'},
                    {'X','X','X','X','X','X','X','X','X','X'}
                    };
 */
void Display(int front)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            if(map[i][j] == '*')
            {
                map[i][j] = 'O';
            }
        }
    }
    int k = front;
    while(k != -1)
    {
        map[qu[k].x][qu[k].y] = ' ';
        k = qu[k].pre;
    }
    Show();
}

void BFS(int x,int y)
{
    int now = -1;
    qu[tail].x = x;
    qu[tail].y = y;
    qu[tail].pre = -1;
    tail++;
    while(front != tail)
    {
        x = qu[front].x;
        y = qu[front].y;
        now = front;
        front++;
        if(x == MAX-2 && y == MAX-2)
        {
            Display(now);
        }
        int k = 0;
        for(k = 0; k < 4; k++)
        {
            if(map[x+V[k]][y+H[k]] == 'O')
            {
                map[x+V[k]][y+H[k]] = '*';
                qu[tail].x = x+V[k];
                qu[tail].y = y+H[k];
                qu[tail].pre = now;
                tail++;
            }
        }
    }
}


int main()
{
    Show();
    DFS(1,1);
    //BFS(1,1);
    //Show();
    return 0;
}
