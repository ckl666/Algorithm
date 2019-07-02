#include <stdio.h>

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

void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Count(int *arr,int start,int end,int len)
{
    int par = Patation(arr,start,end);
    int i = 0; 
    int left = par-1;
    int right = par+1;
    for(i = par-1; i >= start; i--)
    {
        if(arr[i] == arr[par])
        {
            Swap(&arr[i],&arr[left]);
            left--;
        }
    }
    for(i = par+1; i <= end; i++)
    {
        if(arr[i] == arr[par])
        {
            Swap(&arr[i],&arr[right]);
            right++;
        }
    }
    if(right-left+1 > len/2)
    {
        return 1;
    }
    else
    {
        if(left > start)
        {
            return Count(arr,start,left,len);
        }
        if(right < end)
        {
            return Count(arr,right,end,len);
        }
    }
    return 0;
}

// 快排
void Num(int *arr,int start,int end)
{
    int par = Patation(arr,start,end);
    int i = 0; 
    int left = par-1;
    int right = par+1;
    for(i = par-1; i >= start; i--)
    {
        if(arr[i] == arr[par])
        {
            Swap(&arr[i],&arr[left]);
            left--;
        }
    }
    for(i = par+1; i <= end; i++)
    {
        if(arr[i] == arr[par])
        {
            Swap(&arr[i],&arr[right]);
            right++;
        }
    }
    if(left > start)
    {
        Num(arr,start,left);
    }
    if(right < end)
    {
        Num(arr,right,end);
    }
}

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
    int arr[] = {3,2,1,5,4,6,2,7,8,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    //Num(arr,0,len-1);
    printf("%d \n",Count(arr,0,len-1,len));
    Show(arr,len);
    return 0;
}
