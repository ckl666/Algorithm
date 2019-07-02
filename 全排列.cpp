#include <iostream>
#include <vector>

using namespace std;

void Insert(vector<int> s,int i,vector<vector<int> > &ps)
{
    vector<int> s1;
    vector<int>::iterator it;
    int j = 0;
    for(j = 0; j <= s.size(); j++)
    {
        s1 = s;
        it = s1.begin()+j;
        s1.insert(it,i);
        ps.push_back(s1);
    }
}

void Prem(int n,vector<vector<int> > &ps)
{
    vector<vector<int> > ps1;
    vector<int> s;
    s.push_back(1);
    ps.push_back(s);
    int i = 0;
    for(i = 2; i <= n; i++)
    {
        ps1.clear();
        int j = 0;
        for(j = 0; j < ps.size(); j++)
        {
            Insert(ps[j],i,ps1);
        }
        ps = ps1;
    }
}

void Show(vector<vector<int> > ps)
{
    vector<vector<int> >::reverse_iterator it;
    for(it = ps.rbegin(); it != ps.rend(); it++)
    {
        vector<int>::iterator sit;
        cout<<"{ ";
        for(sit = (*it).begin(); sit != (*it).end(); sit++)
        {
            cout<<*sit<<" ";
        }
        cout<<"}"<<endl;
    }
}

int main()
{
    vector<vector<int> > ps;
    Prem(3,ps);
    Show(ps);
    return 0;
}
