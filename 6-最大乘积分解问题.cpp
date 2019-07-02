#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

#define MAX 100

vector<int> best;

bool Judge(int a,int b)
{
    int i = 0;
    for(i = 0; i < best.size(); i++)
    {
        if(best[i] == a || best[i] == b)
        {
            return true;
        }
    }
    return false;
}


void Fun(int n)
{
    if(n < 0)
    {
        return ;
    }
    if(n <= 4 &&  n > 0)
    {
        best.push_back(n/2+1);
        best.push_back(n-(n/2+1));
        return ;
    }
    best.push_back(n);
    int k = 0;
    while(k < best.size())
    {
        n = best[k];
        best.erase(best.begin()+k);
        if(n <= 4)
        {
            best.insert(best.begin()+k,n);
            k++;
            continue;
        }
        int a = 0;
        int b = 0;
        a = n/2+1;
        b = n-a;
        while(b >= 1)
        {
            if(a*b > n && !Judge(a,b))
            {
                best.push_back(a);
                best.push_back(b);
                break;
            }
            a++;
            b--;
        }
        if(b < 1)
        {
            best.insert(best.begin()+k,n);
            k++;
        }
    }
}

void Show()
{
    int i = 0;
    for(i = 0; i < best.size(); i++)
    {
        cout<<best[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n = 16;
    Fun(4);
    Show();
    best.clear();
    Fun(3);
    Show();
    best.clear();
    Fun(2);
    Show();
    best.clear();
    Fun(1);
    Show();
    best.clear();
    Fun(n);
    Show();
    best.clear();
    return 0;
}
