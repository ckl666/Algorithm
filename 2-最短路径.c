#include <stdio.h>

#define MAX 100
#define INF 0x3f3f3f3f

int map[][MAX] = {
    {0,2,4,3,0,0,0,0,0,0},
    {0,0,0,0,7,4,0,0,0,0},
    {0,0,0,0,3,2,4,0,0,0},
    {0,0,0,0,6,2,5,0,0,0},
    {0,0,0,0,0,0,0,3,4,0},
    {0,0,0,0,0,0,0,6,3,0},
    {0,0,0,0,0,0,0,3,3,0},
    {0,0,0,0,0,0,0,0,0,3},
    {0,0,0,0,0,0,0,0,0,4},
    {0,0,0,0,0,0,0,0,0,0}
};

int x[MAX];
int prev[MAX];

//无重叠部分
int Fun(int s,int n)
{
    int i = 0;
    int min = INF;
    int pr;
    if(s == 0)
    {
        x[s] = 0;
        prev[s] = -1;
        return x[s];
    }
    for(i = 0; i < n; i++)
    {
        if(map[i][s] != 0)
        {
            int dist = map[i][s] + Fun(i,n);
            if(min > dist)
            {
                min = dist; 
                pr = i;
            }
        }
    }
    prev[s] = pr;
    x[s] = min;
    return x[s];
}

void Show(int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
}

void ShowPrev(int e)
{
    while(prev[e] != -1)
    {
        printf("%d ",e);
        e = prev[e];
    }
    printf("%d \n",e);
}

int main()
{
    int n = 10;
    int i = 0;
    for(i = 0; i < n; i++)
    {
        prev[i] = -1;
    }
    printf("%d \n",Fun(n-1,n));
    Show(n);
    ShowPrev(n-1);
    return 0;
}
