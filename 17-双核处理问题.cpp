#include <stdio.h>
#include <algorithm>

using namespace std;

bool my_operator(const int a,const int b)
{
    return a > b;
}

int Fun(int arr[],int len)
{
    int M1 = 0;
    int M2 = 0;
    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(M1 < M2)
        {
            M1 += arr[i];
        }
        else
        {
            M2 += arr[i];
        }
    }
    return M1 > M2 ? M1 : M2;
}

int main()
{
    int arr[] = {3072,3072,7168,3072,1024};
    int len = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+len,my_operator);
    printf("%d \n",Fun(arr,len));
    return 0;
}
