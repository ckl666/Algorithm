#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int minpathlen = INF;

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

void Swap(int *arr,int i,int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int SolveTsp(int *arr,int **map,int i,int n)
{
    if(i >= n)
    {
        int sumpathlen = map[0][arr[0]];
        int j = 0;
        /*
        cout << 0 << " ";
        for(; j < n-1; j++)
        {
            sumpathlen += map[arr[j]][arr[j+1]];
            cout << arr[j] << " ";
        }
        cout << arr[j] <<" " <<0 <<"           "<< endl;
        */
        sumpathlen += map[arr[j]][0];
        //cout << sumpathlen << endl;
        if(minpathlen > sumpathlen)
        {
            minpathlen = sumpathlen;
        }
    }
    else
    {
        int j = i;
        for(; j < n; j++)
        {
            Swap(arr,i,j);
            SolveTsp(arr,map,i+1,n);
            Swap(arr,i,j);
        }
    }
}


int main()
{
    cout << "输入节点个数:";
    int size;
    cin >> size;
    int **map = SetMap(size);
    int *arr = new int[size];
    int i = 0;
    for(; i < size-1; i++)
    {
        arr[i] = i+1;
    }
    SolveTsp(arr,map,0,size-1);
    cout << minpathlen <<endl;
    return 0;
}
