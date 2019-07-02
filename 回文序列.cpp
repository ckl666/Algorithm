#include <iostream>
#include <vector>

#define BIG 1000000

using namespace std;

bool IsPal(vector<int> vec)
{
    int i = 0;
    int len = vec.size();
    for(i = 0; i < len/2; i++)
    {
        if(vec[i] != vec[len-i-1])
        {
            return false;
        }
    }
    return true;
}

int Palindrome(vector<int> vec)
{
    int i = 0;
    if(IsPal(vec))
    {
        return 0;
    }
    int min = BIG;
    for(i = 0; i < vec.size()-1; i++)
    {
        vector<int> tmp(vec);
        int a = tmp[i];
        int b = tmp[i+1];
        tmp.erase(tmp.begin()+i);
        tmp.erase(tmp.begin()+i);
        tmp.insert(tmp.begin()+i,(a+b));
        int count = Palindrome(tmp)+1;
        if(min > count)
        {
            min = count;
        }
    }
    return min;
}


int main()
{
    int arr[] = {1,1,1,3,1,1,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec;
    int i = 0;
    for(i = 0; i < len; i++)
    {
        vec.push_back(arr[i]);
    }
    cout<<Palindrome(vec)<<endl;
    return 0;
}
