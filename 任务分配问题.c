#include <stdio.h>

#define MAX 100
#define INF 9999


int best[MAX] = {0};
int min = INF;
int a[MAX][MAX] = {
                {0,0,0,0,0},
                {0,9,2,7,8},  
                {0,6,4,3,7},  
                {0,5,8,1,8},  
                {0,7,6,9,4}  
            };
void Fun(int i,int *x,int len,int cost,bool work[])
{
    if(i > len)
    {
        if(cost < min)
        {
            int j = 0;
            for(j = 1; j <= len; j++)
            {
                best[j] = x[j];
            }
            min = cost;
        }
    }
    else
    {
        int j = 0;
        for(j = 1; j <= len; j++)
        {
            if(!work[j]) 
            {
                work[j] = true;
                x[i] = j;
                Fun(i+1,x,len,cost+a[i][j],work);
                work[j] = false;
                x[i] = 0;
            }
        }
    }
    
}

void Show(int len)
{
    int i = 0;
    for(i = 1; i <= len; i++)
    {
        printf("第%d 人分配了任务 %d \n",i,best[i]);
    } 
    printf("价值最小为%d \n",min);
}


int main()
{
    int n = 4;
    int x[MAX] = {0};
    bool work[MAX] = {false};
    Fun(1,x,n,0,work);
    Show(n);
    return 0;
}
