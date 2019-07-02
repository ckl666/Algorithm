#include <stdio.h>
#include <assert.h>

void PostPre(int *s,int *e)
{
    int m = (*s+*e)/2;
    *e = m;
}

void PostEnd(int *s,int *e)
{
    int m = (*s + *e)/2;
    if((*s + *e)%2 != 0)
    {
        *s = m+1;
    }
    else
    {
        *s = m;
    }
}


int MidNum(int *arr1,int *arr2,int low1,int high1,int low2,int high2)
{
    int mid1 = (low1+high1)/2;
    int mid2 = (low2+high2)/2;
    if(low1==high1 && low2==high2)
    {
        return arr1[low1]<arr2[low2]?arr1[low1]:arr2[low2];
    }
    if(arr1[mid1] == arr2[mid2])
    {
        return arr1[mid1];
    }
    if(arr1[mid1] < arr2[mid2])
    {
        PostPre(&low2,&high2);
        PostEnd(&low1,&high1);
        return MidNum(arr1,arr2,low1,high1,low2,high2);
    }
    if(arr1[mid1] > arr2[mid2])
    {
        PostPre(&low1,&high1);
        PostEnd(&low2,&high2);
        return MidNum(arr1,arr2,low1,high1,low2,high2);
    }
}

int main()
{
    int arr1[] = {1,2,3,4,5,6,7,8};
    int arr2[] = {2,3,4,5,6,7,8,9};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("%d \n",MidNum(arr1,arr2,0,len1-1,0,len2-1));
    return 0;
}
