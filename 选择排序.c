#include <stdio.h>

void SelectSort(int *arr,int len,int i)
{
    if(i > len-2)
    {
        return ;
    }
    int j = 0;
    int k = i;
    for(j = i+1; j < len; j++)
    {
        if(arr[j] < arr[k])
        {
            arr[j] = arr[k] ^ arr[j];
            arr[k] = arr[k] ^ arr[j];
            arr[j] = arr[k] ^ arr[j];
        }
    }
    SelectSort(arr,len,i+1);
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
    int arr[] = {2,1,3,7,8,3,99,11,6,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    SelectSort(arr,len,0);
    Show(arr,len);
    return 0;
}
