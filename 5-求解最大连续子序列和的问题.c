#include <stdio.h>
#include <assert.h>

#define MAX 100

int Fun(int *arr,int len)
{
    assert(arr != NULL);
    int sum = arr[0];
    int i = 0;
    int max = sum;
    for(i = 1; i < len; i++)
    {
        if(sum < 0 && arr[i] > sum)
        {
            sum = arr[i];
        }
        else if(sum >= 0)
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

int main()
{
    int arr[] = {-1,3,4,5,-6,-3,-5,8,9,-1,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum = Fun(arr,len);
    printf("%d \n",sum);
    return 0;
}
