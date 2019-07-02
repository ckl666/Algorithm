#include <stdio.h>
#include <assert.h>

int ReverseNum(int *arr,int len)
{
    assert(arr != NULL);
    int count = 0;
    int i = 0;
    for(i = 0; i < len; i++)
    {
        int j = 0;
        for(j = i+1; j < len; j++)
        {
            if(arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[] = {1,2,4,1,2,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n",ReverseNum(arr,len));
    return 0;
}
