#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void Show(int *w,int len,int *op)
{
    int i = 0;
    printf("=========================\n");
    printf("{ ");
    for(i = 0; i < len; i++)
    {
        if(op[i] == 1)
        {
            printf("%d ",w[i]);
        }
    }
    printf("}\n");
}


void Fun(int *w,int len,int *op,int i,int W,int sum)
{
    if(sum > W)
    {
        return ;
    }
    if(i >= len)
    {
        int i = 0;
        if(W == sum)
        {
            Show(w,len,op);
        }
    }
    else
    {
        op[i] = 0;
        Fun(w,len,op,i+1,W,sum);
        op[i] = 1;
        Fun(w,len,op,i+1,W,sum+w[i]);
    }
}


int main()
{
    int w[] = {11,13,24,7};
    int len = sizeof(w)/sizeof(w[0]);
    int *op = calloc(len,sizeof(int));
    int W = 31;
    Fun(w,len,op,0,W,0);
    return 0;
}
