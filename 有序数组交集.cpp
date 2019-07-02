#include <iostream>
#include <cassert>

using namespace std;

int Search(int *arr,int low,int high,int num)
{
    assert(arr != NULL);
    int mid = (low+high)/2;
    while(low < high)
    {
        if(arr[mid] == num)
        {
            return mid;
        }
        else if(arr[mid] < num)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        mid = (low+high)/2;
    }
    return mid;
}

//两个有序数组的交集
int *Intersection(int *arr1,int *arr2,int len1,int len2,int &lenArr)
{
    int len = len1 < len2?len1:len2;
    int *arr = new int[len];
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < len1 && j < len2)
    {
        int index = Search(arr2,j,len2-1,arr1[i]);
        if(arr2[index] == arr1[i])
        {
            arr[k++] = arr2[index];
            j = index+1;
        }
        else if(arr2[index] < arr1[i])
        {
            j = index+1;
        }
        else
        {
            j = index;
        }
        i++;
        if(i > len1)
        {
            break;
        }
        index = Search(arr1,i,len1-1,arr2[j]);
        if(arr1[index] == arr2[j])
        {
            arr[k++] = arr1[index];
            i = index+1;
        }
        else if(arr1[index] < arr2[j])
        {
            i = index+1;
        }
        else
        {
            i = index;
        }
        j++;
    }
    lenArr = k;
    return arr;

}

void Show(int *arr,int len)
{
    assert(arr != NULL);
    int i = 0;
    for(i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr1[] = {1,2,3,4,6,7};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {3,4,5,7,8,9,10};
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    int len = 0;
    int *arr = Intersection(arr1,arr2,len1,len2,len);
    Show(arr,len);
    return 0;
}
