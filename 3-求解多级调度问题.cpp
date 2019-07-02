#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100
int m[MAX] = {0};         //可用的机器数

void min(int x,int n)
{
    int i = 0;
    int Min = MAX;
    int index = -1;
    for(i = 0; i < n; i++)
    {
        if(Min > m[i])
        {
            Min = m[i];
            index = i;
        }
    }
    m[index] += x;
}

int max(int n)
{
    int i = 0;
    int max = -1;
    for(i = 0; i < n; i++)
    {
        if(max < m[i])
        {
            max = m[i];
        }
    }
    return max;
}

int Fun(int work[],int n)
{
    while(n > 0)
    {
        min(work[n-1],3);
        n = n-1;
    }
    return max(3);
}

int main()
{
    int work[] = {2,14,4,16,6,5,3};
    int len = sizeof(work)/sizeof(work[0]);
    sort(work,work+len);
    int x = Fun(work,len);
    cout<<x<<endl;
    return 0;
}
