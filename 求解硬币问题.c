#include <stdio.h>

int GetSum(int *arr,int low,int high)
{
    int i = 0;
    int sum = 0;
    for(i = low; i <= high; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int MinCount(int *arr,int low,int high,int len)
{
    if(len == 2)
    {
        return arr[low] < arr[high]?low:high;
    }
    if(len == 1)
    {
        return low;
    }
    int n = len/3;
    int sum1 = GetSum(arr,low,low+n-1);
    int sum2 = GetSum(arr,low+n,low+2*n-1);
    if(sum1 > sum2)
    {
        return MinCount(arr,low+n,low+2*n-1,n);
    }
    else if(sum1 < sum2)
    {
        return MinCount(arr,low,low+n-1,n);
    }
    else
    {
        return MinCount(arr,low+2*n,high,len-2*n);
    }
    
}



int main()
{
    int arr[] = {1,1,1,1,1,1,1,0,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n",MinCount(arr,0,len-1,len));
    return 0;
}
