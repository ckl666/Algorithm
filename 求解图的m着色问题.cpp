#include <stdio.h>

#define MAX 100

int a[MAX][MAX] = {
    {0,1,1,1},
    {1,0,0,1},
    {1,0,0,0},
    {1,1,0,0}
};
int clen = 3;     //颜色数
int n = 4;    //顶点数
int count  = 0;

void Show(int way[])
{
    int i = 0;
    printf("=========================\n");
    for(i = 0; i < n; i++)
    {
        printf("顶点%d 着颜色 %d \n",i+1,way[i]);
    }
    //printf("%d \n",count);
}

bool Judge(int color[],int way[],int k,int i)
{
    int j = 0;
    for(j = 0; j < n; j++)
    {
        if(a[j][i] == 1 && way[j] == color[k])
        {
            return false;
        }
    }
    return true;
}

void Fun(int i,int color[],int way[])
{
    if(i >= n)
    {
        Show(way);
        count++;
    }
    else
    {
        int j = 0;
        for(j = 0; j < clen; j++)
        {
            if(Judge(color,way,j,i))
            {
                way[i] = color[j];
                Fun(i+1,color,way);     
            }
            way[i] = 0;
        }
    }
}

int main()
{
    int color[] = {1,2,3};
    int way[MAX] = {0};
    Fun(0,color,way);
    printf("共%d 种着色方案\n",count);
    return 0;
}
