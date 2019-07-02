#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define min(x,y) ((x)>(y)?(y):(x))
const int INF = 0x3f3f3f3f;
//TSP 旅行推销原问题：
//要求每个城市访问一边，最终回到起点城市
int **SetMap(int size)
{
    int **map = new int *[size];
    int i = 0;
    for(; i < size; i++)
    {
        map[i] = new int[size];
    }
    int j = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            int data;
            cin >> data;
            map[i][j] = data;
        }
    }
    return map;
}

int SolveTsp(set<int> &V,int **map,int i)
{
    int minpathlen = INF;
    if(V.size() == 0)
    {
        return map[0][i];
    }
    else
    {
        set<int>::iterator it;
        for(it = V.begin();it != V.end(); ++it)
        {
            set<int> tmpV = V;
            int j = *it;
            tmpV.erase(j);
            int pathlen = SolveTsp(tmpV,map,j) + map[j][i];
            minpathlen = min(minpathlen,pathlen);
        }
    }
    return minpathlen;
}

int main()
{
    cout << "输入节点个数:";
    int size;
    cin >> size;
    int **map = SetMap(size);
    int i = 1;
    set<int> V;
    for(i = 1; i < size; i++)
    {
        V.insert(i);
    }
    int minpathlen = SolveTsp(V,map,0);
    cout << minpathlen <<endl;
    return 0;
}
