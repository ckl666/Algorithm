#include <stdio.h>

#define MAX 100

int op[MAX];

void Show(int *w,int len)
{
    printf("===================================\n");
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("物品 %d 在第 %d 个船上，重量为 %d\n",i+1,op[i]+1,w[i]);
    }
}

void Fun(int weight,int rw,int lw,int *x,int *w,int w1,int w2,int i,int len)
{
    if(i >= len)
    {
        if(rw <= w1 && lw <= w2)
        {
            int j = 0;
            for(j = 0; j < len; j++)
            {
                op[j] = x[j];
            }
            Show(w,len);
        }
    }
    else
    {
        x[i] = 0;
        Fun(weight,rw,lw+w[i],x,w,w1,w2,i+1,len);
        x[i] = 1;
        Fun(weight,rw+w[i],lw,x,w,w1,w2,i+1,len);
    }
}



int main()
{
    int w[] = {10,40,40};
    int w1 = 50,w2 = 50;
    int len = sizeof(w)/sizeof(w[0]);
    int x[MAX];
    Fun(100,0,0,x,w,w1,w2,0,len);
    return 0;
}
