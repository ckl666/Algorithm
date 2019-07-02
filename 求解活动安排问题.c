#include <stdio.h>

#define MAX 100

typedef struct 
{
    int begin;
    int end;
}Action;

int N = 4;
int best[MAX] = {0};          //存放最优解
int x[MAX] = {0};             //存放临时解
int maxsum = 0;
Action ac[] = {{0,0},{1,3},{2,5},{4,8},{6,10}};

void Show()
{
    int i = 0;
    printf("最优解：");
    for(i = 1; i <= N; i++)
    {
        if(best[i] == 1)
        {
            printf("{%d,%d} ",ac[i].begin,ac[i].end);
        }
    }
    printf("\n");
}

void Swap(Action &a,Action &b)
{
    Action tmp = a;
    a = b;
    b = tmp;
}


void Fun(int i,int sum,int laste)
{
    if(i > N)
    {
        if(sum > maxsum)
        {
            maxsum = sum;
            int j = 0;
            for(j = 0; j < N; j++)
            {
                best[j] = x[j];
            }
        }
    }
    else
    {
        int j = 0;
        for(j = i; j <= N; j++)
        {
            Swap(ac[i],ac[j]);
            if(ac[j].begin > laste)
            {
                sum++;
                x[i] = 1;
                laste = ac[j].end;
                Fun(i+1,sum+1,ac[j].end);
            }
            else
            {
                Fun(i+1,sum,laste);
            }
            Swap(ac[i],ac[j]);
        }
    }
}




int main()
{
    Fun(1,0,0);    
    Show();
    return 0;
}
