#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Merge(int *arr,int low,int mid,int high)
{
    assert(arr != NULL);
    int *tmp = (int *)malloc(sizeof(int)*(high-low+1));
    assert(tmp != NULL);
    int i = low;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }
    while(i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while(j <= high)
    {
        tmp[k++] = arr[j++];
    }
    int len = k;
    for(i = low, k = 0; k < len; k++,i++)
    {
        arr[i] = tmp[k];
    }
    free(tmp);
}

//非递归

void MergePass(int *arr,int gap,int len)
{
    int low = 0;
    int mid = low+gap-1;
    int high = mid+gap;
    while(high < len)
    {
        Merge(arr,low,mid,high);
        low = high+1;
        mid = low+gap-1;
        high = mid+gap;
    }
    if(mid < len-1)
    {
        high = len-1;
        Merge(arr,low,mid,high);
    }
}


void MergeSort(int *arr,int len)
{
    int i = 1;
    for(i = 1; i < len; i *= 2)
    {
        MergePass(arr,i,len);
    }
}





//递归
/*
void MergeSort(int *arr,int low,int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}
*/
void Show(int *arr,int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {3,2,1,4,5,2,3,4,1,};
    int len = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,len);
    Show(arr,len);
    return 0;
}
