#include <iostream>
#include <algorithm>

#define MAX 100
int a[MAX] = {92,83,71};
int b[MAX] = {95,87,74};

using namespace std;

void Fun(int n)
{
    sort(a,a+n);
    sort(b,b+n);
    int i = 0;
    int left1 = 0;
    int right1 = n-1;
    int left2 = 0;
    int right2 = n-1;
    int count  = 0;
    while(right1 >= left1)
    {
        if(a[right1] < b[right2])
        {
            count--;
            right2--;
            left1++;
        }
        else if(a[right1] > b[right2])
        {
            count++;
            right1--;
            right2--;
        }
        else
        {
            if(a[left1] > b[left2])
            {
                count++;
                left1++;
                left2++;
            }
            else if(a[left1] < b[left2])
            {
                count--;
                left1++;
                right2--;
            }
        }
    }
    cout<<count*200<<endl;
}


int main()
{
    Fun(3);
    return 0;
}
