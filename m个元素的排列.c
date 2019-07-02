#include <stdio.h>

#define MAX 100

int op[MAX] = {0};
int NUM = 2;
int flag[MAX] = {0};

void Show()
{
    int i = 0;
    for(i = 0; i < NUM; i++)
    {
        printf("%d ",op[i]);
    }
    printf("\n");
}

void Fun(int a[],int tmp[],int len,int i,int m)
{
    if(i >= len)
    {
        if(m == NUM)
        {
            int j = 0;
            for(j = 0; j < NUM; j++)
            {
                op[j] = tmp[j];
            }
            Show();
        }
    }
    else
    {
        int j = 0;
        for(j = 0; j < len ;j++)
        {
            Fun(a,tmp,len,i+1,m);
            if(flag[j] == 0)
            {
                flag[j] = 1;
                tmp[m] = a[j];
                Fun(a,tmp,len,i+1,m+1);
                flag[j] = 0;
            }
        }
    }
}

int main()
{
    int a[] = {1,2,3};
    int len = sizeof(a)/sizeof(a[0]);
    int tmp[MAX];
    Fun(a,tmp,len,0,0);
    return 0;
}
