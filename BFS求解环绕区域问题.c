#include <stdio.h>

#define MAX 10

typedef struct 
{
    int x;
    int y;
    int pre;
}queue;

int map[MAX][MAX] = {
    {'X','X','X','X','O','X','X','X','X','X'},
    {'X','O','O','X','O','X','X','X','X','X'},
    {'X','O','O','X','O','O','X','X','X','X'},
    {'X','O','O','O','X','O','X','O','X','X'},
    {'X','X','X','X','X','O','X','X','X','X'},
    {'X','X','X','X','X','O','X','X','X','X'},
    {'X','X','X','X','O','X','X','X','X','X'},
    {'X','X','X','X','X','X','X','X','X','X'},
    {'X','X','X','X','O','X','X','X','X','X'},
    {'X','X','X','X','X','O','X','O','X','X'}
};

int H[] = {-1,0,1,0,};
int V[] = {0,1,0,-1};

void Show()
{
    printf("================================= \n");
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

void BFS(int x,int y)
{
    int front = 0;
    int tail = 0;
    if(map[x][y] == 'X')
    {
        return;
    }
    queue qu[MAX];
    qu[tail].x = x;
    qu[tail].y = y;
    tail++;
    while(front != tail)
    {
        x = qu[front].x;
        y = qu[front].y;
        front++;
        if(map[x][y] == 'O')
        {
            map[x][y] = '*';
        }
        int k = 0;
        for(k = 0; k < 4; k++)
        {
            if(map[x+H[k]][y+V[k]] == 'O')
            {
                qu[tail].x = x+H[k];
                qu[tail].y = y+V[k];
                tail++;
            }
        }
    }
}

void Change()
{
    int i = 0;
    int j = 0;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            if(map[i][j] == 'O')
            {
                map[i][j] = 'X';
            }
            else if(map[i][j] == '*')
            {
                map[i][j] = 'O';
            }
        }
    }
}

void Fun()
{
    int i = 0;
    int j = 0;
    for(j = 0; j < MAX; j++)
    {
        BFS(i,j);
    }
    j--;
    for(i = 0; i < MAX; i++)
    {
        BFS(i,j);
    }
    i--;
    for(j; j >= 0; j--)
    {
        BFS(i,j);
    }
    j++;
    for(i; i >= 0; i--)
    {
        BFS(i,j);
    }
    Change();
}


int main()
{
    Show();
    Fun();
    Show();
    return 0;
}
