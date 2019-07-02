#include <iostream>

using namespace std;

const int NO_WAY = 0x3f3f3f3f;

void ShowDistance(int *dis,int size)
{
    int i = 0;
    for(; i < size; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
}

void ShowPath(int *path,int key)
{
    cout << key << " ";
    while(path[key] != key)
    {
        cout << path[key] << " ";
        key = path[key];
    }
    cout << endl;
}

int **SetMap(int size)
{
    int **map = new int *[size];
    int i = 0;
    for(; i < size; i++)
    {
        map[i] = new int[size];
    }

    for(i = 0; i < size; i++)
    {
        int j = 0;
        for(; j < size; j++)
        {
            int data;
            cin >> data;
            map[i][j] = data;
        }
    }
    return map;
}

void Bellman_ford(int **map, int size)
{
    int *dis = new int[size];
    int *path = new int[size];
    int i = 0;
    for(; i < size; i++)
    {
        dis[i] = NO_WAY;
    }
    path[0] = 0;
    dis[0] = 0;
    int k = 0;
    while(k < size)
    {
        for(i = 0; i < size; i++)
        {
            int j = 0;
            for(; j < size; j++)
            {
                if(map[i][j] != 0 && dis[j] > dis[i] + map[i][j])
                {
                    dis[j] = dis[i] + map[i][j];
                    path[j] = i;
                }
            }
        }
        k++;
    }
    ShowDistance(dis,size);
    for(i = 0; i < size; i++)
    {
        ShowPath(path,i);
    }
    for(i = 0; i < size; i++)
    {
        delete[]map[i];
    }
    delete[]map;
    delete[]dis;
    delete[]path;
}

int main()
{
    cout << "输入节点数:";
    int size;
    cin >> size;
    int  **map = SetMap(size);
    Bellman_ford(map,size);
    return 0;
}
