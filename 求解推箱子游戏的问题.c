#include <stdio.h>

#define MAX 6


int H[] = {0,1,0,-1};
int V[] = {1,0,-1,0};

void Show(char map[][MAX])
{
    printf("================\n");
    int i = 0;
    int j = 0;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
}

void Fun(int x,int y,char map[][MAX])
{
    int k = 0;
    for(k = 0; k < 4; k++)
    {
        if(x+H[k] >= 0 && x+H[k] < MAX && y+V[k] >= 0 && y+V[k] < MAX)
        {
            if(map[x+H[k]][y+V[k]] == '*')
            {
                if(x+2*H[k] >= 0 && x+2*H[k] < MAX && y+V[k] >= 0 && y+V[k] < MAX)
                {
                    if(map[x+2*H[k]][y+2*V[k]] == '@')
                    {
                        Show(map);
                    }
                    else if(map[x+2*H[k]][y+2*V[k]] == '.')
                    {
                        map[x][y] = ' ';
                        map[x+H[k]][y+V[k]] = ' ';
                        map[x+2*H[k]][y+2*V[k]] = '*';
                        Fun(x+H[k],y+V[k],map);
                        map[x+H[k]][y+V[k]] = '*';
                        map[x+2*H[k]][y+2*V[k]] = '.';
                    }
                }
            }
            if(map[x+H[k]][y+V[k]] == '.')
            {
                map[x][y] = ' ';
                Fun(x+H[k],y+V[k],map);
                map[x][y] = '.';
            }
        }
    }
}

int main()
{
    char map[MAX][MAX] = {
        {'.','.','.','#','.','.'},
        {'.','.','.','.','.','.'},
        {'#','*','#','#','.','.'},
        {'.','.','#','.','#','.'},
        {'.','.','X','.','.','.'},
        {'.','@','#','.','.','.'}
    };
    Show(map);
    Fun(4,2,map);
    return 0;
}
