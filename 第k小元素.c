#include <stdio.h>
#include <assert.h>


int Patation(int *arr,int low,int high)
{
    int tmp = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= tmp)
        {
            high--;
        }
        arr[low] = arr[high];
        while(low < high && arr[low] <= tmp)
        {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = tmp;
    return low;
}

int KMin(int *arr,int low,int high,int k)
{
    int par = Patation(arr,low,high);
    if(par == k-1)
    {
        return arr[par];
    }
    if(par < k-1 && par+1 <= high)
    {
        return KMin(arr,par+1,high,k);
    }
    if(par > k-1 && par-1 >= low)
    {
        return KMin(arr,low,par-1,k);
    }
    return -1;
}



int main()
{
    int arr[] = {4,2,1,4,3,5,6,8,4,2,31,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    for(k = 1; k <= len; k++)
    {
        printf("第%d 小的数为%d \n",k,KMin(arr,0,len-1,k));
    }
    return 0;
}
