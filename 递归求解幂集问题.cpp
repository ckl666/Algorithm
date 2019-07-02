#include <iostream>
#include <vector>

using namespace std;

void Insert(int n,vector<vector<int> > &ps)
{
    int i = 0;
    vector<vector<int> > ps1;
    ps1 = ps;
    for(i = 0; i < ps1.size(); i++)
    {
        ps1[i].push_back(n);
    }
    for(i = 0; i < ps1.size(); i++)
    {
        ps.push_back(ps1[i]);
    }
}


void PSet(vector<vector<int> > &ps,int i,int n)
{
    if(i <= n)
    {
        Insert(i,ps);
        PSet(ps,i+1,n);
    }
}

void Show(vector<vector<int> > ps)
{
    int i = 0;
    for(i = 0; i < ps.size(); i++)
    {
        cout<<"{ ";
        int j = 0;
        for(j = 0; j < ps[i].size(); j++)
        {
            cout<<ps[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
}

int main()
{
    vector<vector<int> >ps;
    vector<int> s;
    ps.push_back(s);
    PSet(ps,1,3);
    Show(ps);
    return 0;
}
