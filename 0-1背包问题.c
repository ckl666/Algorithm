#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 100

int maxv = -1;
int op[MAX];

void Show(int *x,int *w,int *v,int len,int value)
{
    printf("================================================\n");
    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(x[i] == 1)
        {
            printf("第 %d 件物品,重量 %d,价值%d \n",i+1,w[i],v[i]);
        }
    }
    printf("总价值为 %d \n",value);
}


void Fun(int *x,int *w,int *v,int i,int sum,int value,int len,int weight)
{
    if(sum > weight)
    {
        return ;
    }
    if(i >= len)
    {
        if(maxv < value)
        {
            maxv = value;
            int j = 0;
            for(j = 0; j < len; j++)
            {
                op[j] = x[j];
            }
        }
    }
    int j = 0;
    for(j = i; j < len; j++)
    {
        x[j] = 0;
        Fun(x,w,v,i+1,sum,value,len,weight);
        x[j] = 1;
        sum += w[i];
        value += v[i];
        Fun(x,w,v,i+1,sum,value,len,weight);
    }
}



int main()
{
    int w[] = {0,5,3,2,1};
    int v[] = {0,4,4,3,1};
    int len = sizeof(w)/sizeof(w[0]);
    int *x = (int *)calloc(len,sizeof(int));
    assert(x != NULL);
    Fun(x,w,v,0,0,0,len,6); 
    Show(op,w,v,len,maxv);
    return 0;
}
