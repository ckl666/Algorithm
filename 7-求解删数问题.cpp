#include <iostream>
#include <string>

using namespace std;

int Min(string str,int start,int k)
{
    if(str.size() <= k+start)
    {
        return str.size();
    }
    else
    {
        char ch = 127;
        int i = 0;
        int index = -1;
        for(i = start; i <= start+k; i++)
        {
            if(ch > str[i])
            {
                ch = str[i];
                index = i;
            }
        }
        return index;
    }
}

void Fun(string &str,int k)
{
    int start = 0;
    while(k > 0)
    {
        int index = Min(str,start,k);
        str.erase(str.begin()+start,str.begin()+index);
        k = k-(index-start);
        start++;
    }
}


int main()
{
    string str;
    cin>>str;
    int k = 3;
    Fun(str,k);
    cout<<str<<endl;
    return 0;
}
