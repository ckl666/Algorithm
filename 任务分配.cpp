#include <iostream>
#include <vector>

#define MAX 4

using namespace std;

void Insert(vector<int> s,int i, vector<vector<int> > &ps)
{
    int j = 0;
    vector<int>::iterator it;
    vector<int> s1;
    for(j = 0; j <= s.size(); j++)
    {
        s1 = s;
        it = s1.begin()+j;
        s1.insert(it,i);
        ps.push_back(s1);
    }
}

void Prem(vector<vector<int> > &ps,int n)
{
    vector<int> s;
    vector<vector<int> > ps1;
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
    int arr[][MAX] = {{9,2,7,8},
                   {6,4,3,7},
                   {5,8,1,8},
                   {7,6,9,4}};
    vector<vector<int> >ps;
    Prem(ps,4);
    vector<int>::iterator it;
    int i = 0;
    int sum = 0;
    for(i = 0; i < ps.size(); i++)
    {
        int j = 0;
        sum = 0;
        for(j = 0; j < ps[i].size(); j++)
        {
            sum += arr[j][ps[i][j]-1];
        }
        ps[i].push_back(sum);
    }
    Show(ps);
    return 0;
}
