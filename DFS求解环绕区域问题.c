#include <stdio.h>

#define MAX 10

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

void DFS(int x,int y)
{
    if(x < 0 || y < 0 || x >= MAX || y>= MAX || map[x][y] == 'X')
    {
        return ;
    }
    map[x][y] = '*';
    int k = 0;
    for(k = 0; k < 4; k++)
    {
        if(x+H[k] >= 0 && x+H[k] <= MAX-1 && y+V[k] >= 0 && y+V[k] <= MAX-1 && map[x+H[k]][y+V[k]] == 'O')
        {
            DFS(x+H[k],y+V[k]);
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
        DFS(i,j);
    }
    j--;
    for(i = 0; i < MAX; i++)
    {
        DFS(i,j);
    }
    i--;
    for(j; j >= 0; j--)
    {
        DFS(i,j);
    }
    j++;
    for(i; i >= 0; i--)
    {
        DFS(i,j);
    }
    //Change();
}



/*
int DFS(int x,int y)
{
    if(x <= 0 || y <= 0 || x >= MAX || y>= MAX || map[x][y] == 'X')
    {
        return 1;
    }
    int k = 0;
    int flag = 0;
    map[x][y] = '*';
    for(k = 0; k < 4; k++)
    {
        if(x+H[k] < 0 || y+V[k] < 0 || x+H[k] > MAX-1 || y+V[k] > MAX-1)
        {
            flag = 1;
        }
        else if(map[x+H[k]][y+V[k]] == 'O')
        {
            if(DFS(x+H[k],y+V[k]) == 1)
            {
                flag = 1;
            }
        }
    }
    if(flag == 1)
    {
        return 1;
    }
    return 0;
}

void Change(char ch)
{
    int i = 0;
    for(i = 0;i < MAX; i++)
    {
        int j = 0;
        for(j = 0; j < MAX; j++)
        {
            if(map[i][j] == '*')
            {
                map[i][j] = ch;
            }
        }
    }
}

void Fun()
{
    int i = 0;
    for(i = 0; i < MAX; i++)
    {
        int j = 0;
        for(j = 0; j < MAX; j++)
        {
            if(DFS(i,j) == 1)
            {
                Change('O');
            }
            else
            {
                Change('X');
            }
        }
    }
}
*/

int main()
{
    Show();
    //printf("%d \n",DFS(2,4));
    Fun();
    Show();
    return 0;
}
