#include <algorithm>
#include <iostream>
#include <queue>

#define max(a,b) (((a)>(b))?(a):(b))
#define MAX 100

using namespace std;

typedef struct Node
{
    int n;       //编号
    bool group;   //组
    int time;   //a b 的较短的时间
    bool operator < (const Node &s)const
    {
        return time < s.time;       //升序
    }
}Node;

int best[MAX];

int Fun(int a[],int b[],int len)
{
    Node e[MAX];
    int i = 0;
    for(i = 0; i < len; i++)
    {
        e[i].n = i;
        e[i].group = (a[i] <= b[i]);
        e[i].time = a[i] <= b[i] ? a[i] : b[i];
    }
    sort(e,e+len);
    int k = len-1;
    int j = 0;
    for(i = 0; i < len; i++)
    {
        if(e[i].group)
        {
            best[j++] = e[i].n;
        }
        else
        {
            best[k--] = e[i].n;
        }
    }
    int f1 = 0,f2 = 0;
    for(i = 0; i < len; i++)
    {
        f1 += a[best[i]];
        f2 = max(f1,f2) + b[best[i]];
    }
    return f2;
}

void Show(int len,int f2)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        cout<<best[i]+1<<" ";
    }
    cout<<endl;
    cout<<f2<<endl;
}


int main()
{
    int a[] = {5,12,4,8};
    int b[] = {6,2,14,7};
    int len = sizeof(a)/sizeof(a[0]);
    int f2 = Fun(a,b,len);
    Show(len,f2);
    return 0;
}
