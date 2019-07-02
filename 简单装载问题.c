#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int min = 9999;
int op[MAX];

void Fun(int *w,int *x,int weight,int wsum,int i,int len,int count)
{
    if(wsum > weight)
    {
        return ;
    }
    if(i >= len)
    {
        if(weight == wsum && min > count)
        {
            min = count;
            int j = 0;
            for(j = 0; j < len; j++)
            {
                op[j] = x[j];
            }
        }
    }
    else
    {
        x[i] = 0;
        Fun(w,x,weight,wsum,i+1,len,count);
        x[i] = 1;
        Fun(w,x,weight,wsum+w[i],i+1,len,count+1);
    }
}

void Display(int *w,int *op,int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(op[i] == 1)
        {
            printf("第 %d 件物品 重量为 %d \n",i+1,w[i]);
        }
    }
    printf("共 %d 件 物品\n",min);
}

int main()
{
    int w[] = {5,2,6,4,3};
    int len = sizeof(w)/sizeof(w[0]);
    int *x = (int *)calloc(len,sizeof(int));
    Fun(w,x,10,0,0,len,0);
    Display(w,op,len);
    return 0;
}
