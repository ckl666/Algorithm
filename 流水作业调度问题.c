#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 0x3f3f3f3f

int Min = INF;

typedef struct
{
    int M1;
    int M2;
}Time;

Time best[MAX];

void Swap(Time *a,Time *b)
{
    Time tmp = *a;
    *a = *b;
    *b = tmp;
}

void Show(int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("%d %d\n",best[i].M1,best[i].M2);
    }
    printf("最少的时间为:%d \n",Min);
}


void Count(Time arr[],int n)
{
    int f2[MAX] = {0};
    int i = 0;
    int f1 = 0;
    f2[0] = arr[0].M1;
    for(i = 0; i < n-1; i++)
    {
        f1 += arr[i].M1;
        f2[i+1] = f1+arr[i+1].M1 > f2[i]+arr[i].M2 ? f1+arr[i+1].M1 : f2[i]+arr[i].M2;
    }
    if(Min > f2[i]+arr[i].M2)
    {
        Min = f2[i] + arr[i].M2;
        for(i = 0; i < n; i++)
        {
            best[i] = arr[i];
        }
    }
}

void Fun(Time arr[],int i,int n)
{
    if(i >= n)
    {
        Count(arr,n);
    }
    else
    {
        int j = 0;
        for(j = i; j < n; j++)
        {
            Swap(&arr[i],&arr[j]);
            Fun(arr,i+1,n);
            Swap(&arr[i],&arr[j]);
        }
    }
}

int main()
{
    Time arr[] = {{5,6},{12,2},{4,14},{8,7}};
    int len = sizeof(arr)/sizeof(arr[0]);
    Fun(arr,0,len);
    Show(len);
    return 0;
}
