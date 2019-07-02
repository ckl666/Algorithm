#include <stdio.h>
#include <assert.h>

int ArrMax(int *arr,int end)
{
    if(end > 0)
    {
        return arr[end] > ArrMax(arr,end-1)?arr[end]:ArrMax(arr,end-1);
    }
    else
    {
        return arr[0];
    }
}


int main()
{
    int arr[] = {2,1,3,4,1,5,6,7,-1};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n",ArrMax(arr,len-1));
    return 0;
}
