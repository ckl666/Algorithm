#include <stdio.h>
#include <assert.h>

#define min -100000

void Solve(int *arr,int low,int high,int *max1,int *max2)
{
    assert(arr != NULL && max1 != NULL && max2 != NULL);
    if(low == high)
    {
        *max1 = arr[low];
        *max2 = min; 
    }
    else
    {
        int mid = (low + high)/2;
        int ml1,ml2;
        Solve(arr,low,mid,&ml1,&ml2);
        int mh1,mh2;
        Solve(arr,mid+1,high,&mh1,&mh2);
        *max1 = ml1>mh1 ? ml1:mh1;
        int tmp1 = ml1 < mh1 ? ml1 : mh1;
        int tmp2 = ml2 > mh2 ? ml2 : mh2;
        *max2 = tmp1 > tmp2 ? tmp1 : tmp2;
    }
}



int main()
{
    int arr[] = {2,3,4,1,2,6,3,2,7,8};
    int len = sizeof(arr)/sizeof(arr[0]);
    int max1;
    int max2;
    Solve(arr,0,len-1,&max1,&max2);
    printf("%d %d \n",max1,max2);
    return 0;
}
