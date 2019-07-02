#include <vector>
#include <iostream>

using namespace std;

int PSet(vector<vector<int> > &ps,int n)
{
    vector<vector<int> > ps1;
    int i = 1;
    for(i = 1; i <= n; i++)
    {
        ps1 = ps;
        int j = 0;
        for(j = 0; j < ps1.size(); j++)
        {
            ps1[j].push_back(i);
        }
        for(j = 0; j < ps1.size(); j++)
        {
            ps.push_back(ps1[j]);
        }
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
    vector<vector<int> > ps;
    vector<int> s;
    ps.push_back(s);
    PSet(ps,3);
    Show(ps);
    return 0;
}
