#include <iostream>

using namespace std;

const int NO_WAY = 0x3f3f3f3f;

void Show(int **map,int size)
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        int j = 0;
        for(j = 0; j < size; j++)
        {
            cout << map[i][j] << " ";
        }
        cout<< endl;
    }
}

int **SetMap(int size)
{
    int **map = new int* [size];
    int i = 0;
    for(i = 0; i < size; i++)
    {
        map[i] = new int [size];
    }
    //初始化
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
    //Show(map,size);
}

void ShowDistance(int *dis,int size)
{
    int i = 0;
    for(; i < size; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
}

void ShowPath(int *path,int k)
{
    cout << k << " ";
    while(path[k] != k)
    {
        cout << path[k] << " ";
        k = path[k];
    }
    cout << endl;
}

void Dijkstra(int **map,int size)
{
    int *dis = new int[size];
    int *path = new int[size];
    int *hashmap = new int[size];
    int i = 0;
    for(; i < size; i++)
    {
        dis[i] = NO_WAY;
        hashmap[i] = 0;
    }
    path[0] = 0;
    dis[0] = 0;
    int j = 0;      //表示节点
    int k = 0;      //控制循环
    i = 0;          //表示节点
    for(; k < size; k++)
    {
        hashmap[i] = 1;    
        for(j = 0; j < size; j++)
        {
            if(hashmap[j] == 0 && map[i][j] != 0 && dis[j] > dis[i] + map[i][j])
            {
                dis[j] = dis[i] + map[i][j];
                path[j] = i;
            }
        }
        int mins = NO_WAY;
        for(j = 0; j < size; j++)
        {
            if(hashmap[j] == 0 && mins > dis[j])
            {
                mins = dis[j];  //选择最短的路径
                i = j;
            }
        }
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
    int **map;
    cout << "输入节点数:";
    int size;
    cin >> size;
    map = SetMap(size);
    //Show(map,size);
    Dijkstra(map,size);
    return 0;
}

