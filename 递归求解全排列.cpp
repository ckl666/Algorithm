#include <iostream>
#include <vector>

using namespace std;

void Insert(vector<vector<int> > &ps,int i,vector<int> s)
{
    vector<int>::iterator it;
    vector<int> s1;
    int j = 0;
    for(j = 0; j <= s.size(); j++)
    {
        s1 = s;
        it = s1.begin()+j;
        s1.insert(it,i);
        ps.push_back(s1);
    }
}

void PSet(vector<vector<int> > &ps,int i,int n)
{
    vector<vector<int> > ps1;
    if(i <= n)
    {
        int j = 0;
        for(j = 0; j < ps.size(); j++)
        {
            Insert(ps1,i,ps[j]);
        }
        ps = ps1;
        PSet(ps,i+1,n);
    }
}

void Show(vector<vector<int> >ps)
{
    vector<vector<int> >::reverse_iterator it;
    for(it = ps.rbegin(); it != ps.rend(); it++)
    {
        cout<<"{ ";
        vector<int>::iterator sit;
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
    vector<int> s;
    s.push_back(1);
    ps.push_back(s);
    PSet(ps,2,4);
    Show(ps);
    return 0;
}
