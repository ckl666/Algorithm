#include <stdio.h>

void Sort(int *arr,int len,int i)
{
    if(i > len-2)
    {
        return ;
    }
    int j = 0;
    int flag = 1;
    for(j = len-1; j > i; j--)
    {
        if(arr[j] < arr[j-1])
        {
            arr[j] = arr[j-1] ^ arr[j];
            arr[j-1] = arr[j-1] ^ arr[j];
            arr[j] = arr[j-1] ^ arr[j];
            flag = 0;
        }
    }
    if(flag == 1)
    {
        return ;
    }
    Sort(arr,len,i+1);
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
    int arr[] = {3,2,1,3,4,5,6,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    Sort(arr,len,0);
    Show(arr,len);
}
