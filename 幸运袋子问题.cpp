#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

#define MAX 100
int count = 0;
set<vector<int> > se;

void Count(int arr[],int x[],int n)
{
    int i = 0;
    vector<int> ve;
    for(i = 0; i < n; i++)
    {
        if(x[i] == 1)
        {
            ve.push_back(arr[i]);
        }
    }
    se.insert(ve);
}


void Judge(int x[],int arr[],int n)
{
    int i = 0;
    int sum = 0;
    int mul = 1;
    for(i = 0; i < n; i++)
    {
        if(x[i] == 1)
        {
            sum += arr[i];
            mul *= arr[i];
        }
    }
    if(sum > mul)
    {
        Count(arr,x,n);
    }
}

void Fun(int i,int n,int arr[],int x[])
{
    if(i >= n)
    {
        Judge(x,arr,n);
    }
    else
    {
        x[i] = 1;
        Fun(i+1,n,arr,x);
        x[i] = 0;
        Fun(i+1,n,arr,x);
    }
}



int main()
{
    int arr[] = {1,1,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int *x = (int *)malloc(sizeof(int)*len);
    Fun(0,len,arr,x);
    printf("%d \n",se.size());
    return 0;
}
