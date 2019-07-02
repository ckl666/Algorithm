#include <stdio.h>


//分治法
int MaxSum(int *arr,int len)
{
    
}




//O(n)
/*
int MaxSum(int *arr,int len)
{
    int max = arr[0];
    int sum = arr[0];
    int i = 0;
    for(i = 1; i < len; i++)
    {
        if(sum <= 0 && arr[i] > sum)
        {
            sum = arr[i];
        }
        else if(sum > 0)
        {
            sum += arr[i];
        }
        if(max < sum)
        {
            max = sum;
        }
    }
    return max;
}
*/

int main()
{
    int arr[] = {1,1,-2,-3,3,-5,2,1-1,3,-7,4,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n",MaxSum(arr,len));
    return 0;
}
