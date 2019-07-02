#include <stdio.h>

#define MAX 9

void Fun(char op[],int sum,int a[],int prevadd,int i)
{
    if(i == MAX)
    {
        if(sum == 100)
        {
            printf("%d",a[0]);
            int i = 0;
            for(i = 1; i < MAX; i++)
            {
                if(op[i] != ' ')
                {
                    printf("%c",op[i]);
                }
                printf("%d",a[i]);
            }
            printf("=100\n");
        }
        return ;
    }
    sum += a[i];
    op[i] = '+';
    Fun(op,sum,a,a[i],i+1);
    sum -= a[i];
    op[i] = '-';
    sum -= a[i];
    Fun(op,sum,a,-a[i],i+1);
    sum += a[i];
    op[i] = ' ';
    sum -= prevadd;
    int tmp;
    if(prevadd > 0)
    {
        tmp = prevadd*10+a[i];
    }
    else
    {
        tmp = prevadd*10-a[i];
    }
    sum += tmp;
    Fun(op,sum,a,tmp,i+1);
    sum -= tmp;
    sum += prevadd;
}



int main()
{
    int a[MAX] = {1,2,3,4,5,6,7,8,9};
    char op[MAX];
    Fun(op,a[0],a,a[0],1);
    return 0;
}
