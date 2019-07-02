#include <stdio.h>


int KMin(int *a,int n,int *b,int m,int k)
{
    if(k <= 0)
    {
        return -1;
    }
    if(n == 0)
    {
        return b[k-1];
    }
    if(k == 1)
    {
        return a[0] <= b[0]?a[0]:b[0];
    }
    int numa = (n > k/2)?k/2:n;
    int numb = k-numa;
    if(a[numa-1] < b[numb-1])
    {
        return KMin(&a[numa],n-numa,b,m,k-numa);
    }
    if(a[numa-1] > b[numb-1])
    {
        return KMin(a,n,&b[numb],m-numb,k-numb);
    }
    if(a[numa-1] == b[numb-1])
    {
        return a[numa-1];
    }
}



int main()
{
    int arr1[] = {1,2,3,4,5,6,7,8};
    int arr2[] = {4,5,6,7,8,9,10,10,11,11};
    int len1 =sizeof(arr1)/sizeof(arr1[0]);
    int len2 =sizeof(arr2)/sizeof(arr2[0]);
    int k = 1;
    for(k = 1; k <= len1+len2; k++)
    {
        printf("第%d 小的数为 %d \n",k,KMin(arr1,len1,arr2,len2,k));
    }
    return 0;
}
