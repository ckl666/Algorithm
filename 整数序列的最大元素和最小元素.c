#include <stdio.h>

void MergeCom(int *arr,int start,int end,int *max,int *min)
{   
    if(start == end)
    {
        *max = arr[start];
        *min = arr[start];
    }
    else
    {
        int max1,max2,min1,min2;
        int mid = (start+end)/2;
        MergeCom(arr,start,mid,&max1,&min1);
        MergeCom(arr,mid+1,end,&max2,&min2);
        *max = max1 > max2 ? max1:max2;
        *min = min1 < min2 ? min1:min2;
    }
}


int main()
{
    int arr[] = {2,3,1,3,41,2,4,5,66,22,12,3,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int max,min;
    MergeCom(arr,0,len-1,&max,&min);
    printf("%d %d \n",max,min);
    return 0;
}

