#include <iostream>

using namespace std;

const int NO_WAY = 0x3f3f3f3f;

//打印距离
void ShowDistance(int **dis,int size)
{
    int i = 0;
    for(; i < size; i++)
    {
        int j = 0;
        for(; j < size; j++)
        {
//            cout << "从" << i << "到" << j << "距离为:" << dis[i][j] << endl;
            cout << dis[i][j] << " "; 
        }
        cout << endl;
    }
}

//打印路径
void ShowPath(int **path,int size)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            int k = j;
            cout << k << " ";
            while(path[i][k] != -1)
            {
                cout << path[i][k] << " ";
                k = path[i][k];
            }
            cout << endl;
        }
    }
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

void Floyed(int **map,int size)
{   
    int **dis = new int*[size];
    int i = 0;
    for(; i < size; i++)
    {
        dis[i] = new int[size];
    }
    int **path = new int*[size];
    for(i = 0; i < size; i++)
    {
        path[i] = new int[size];
    }
    int k = 0;
    int j = 0;
    // 初始化dis 和 path ;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(i != j && map[i][j] == 0)
            {
                dis[i][j] = NO_WAY;
            }
            else
            {
                dis[i][j] = map[i][j];
            }
            if(i == j)
            {
                path[i][j] = -1;
            }
            else
            {
                path[i][j] = i;
            }
        }
    }
    for(;k < size; k++)
    {
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    cout << "=================================" << endl;
    ShowDistance(dis,size);
    cout << "=================================" << endl;
    ShowPath(path,size);
}


int main()
{
    cout << "输入节点数:";
    int size;
    cin >> size;
    int **map = SetMap(size);
    Floyed(map,size);
    return 0;
}
