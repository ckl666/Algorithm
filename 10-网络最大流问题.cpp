#include <iostream>

using namespace std;

const int MAX = 100;
const int INF = 0x3f3f3f3f;

int path[MAX];
int maxflow = 0;
//网络流的容量
//当前的流量
//迭代两点之间的增广路径 当前的流量小于容量时表示此路通
void ShowPath(int key)
{
    cout << key << " ";
    while(path[key] != -1)
    {
        cout << path[key] << " ";
        key = path[key];
    }
    cout << endl;
}

void ChangeFlow(int **flow,int key,int minflow)
{
    while(path[key] != -1)
    {
        flow[path[key]][key] += minflow;
        key = path[key];
    }
}


int **SetCapacityFlow(int size)
{
    int **tmp = new int *[size];
    int i = 0;
    for(i = 0; i < size; i++)
    {
        tmp[i] = new int[size];
    }
    int j = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            int data;
            cin >> data;
            tmp[i][j] = data;
        }
    }
    return tmp;
}

//no:当前下标 des:网络流量汇总节点  cap:当前网络的所有节点之间的容量
//flow: 当前节点的流量，minflow:增广路径上的最小的剩余网络，size:当前网络节点数
//hashmap:查找增广路径过程中，已经包含的节点
void MaxFlow(int no,int des,int **cap,int **flow,int minflow,int size,int *hashmap)
{
    if(no == des)
    {
        //修改当前的流量值
        ShowPath(des);
        ChangeFlow(flow,des,minflow);
        maxflow += minflow;
    }
    else
    {
        int i = 0;
        //递归求增广路径
        for(i = 0; i < size; i++)
        {
            if(hashmap[i] == 1)
            {
                continue;
            }
            if(cap[no][i] > 0 && cap[no][i] > flow[no][i])
            {
                int tmp = (cap[no][i]-flow[no][i]) > minflow ? minflow:(cap[no][i]-flow[no][i]);
                path[i] = no;
                int k = i;
                //修改该增广路径下最小的流量值
                while(path[k] != -1)
                {
                    tmp = cap[path[k]][k]-flow[path[k]][k] > tmp ? tmp : (cap[path[k]][k]-flow[path[k]][k]);
                    k = path[k];
                }
                hashmap[i] = 1;
                MaxFlow(i,des,cap,flow,tmp,size,hashmap);
                hashmap[i] = 0;
            }
        }
    }
}

int main()
{
    cout << "输如节点数:";
    int size;
    cin >> size;
    cout << "=========容量========="<<endl;
    int **cap = SetCapacityFlow(size);
    cout << "=========流量========="<<endl;
    int **flow = SetCapacityFlow(size);
    int minflow = INF;
    int *hashmap = new int[size];
    path[0] = -1;
    hashmap[0] = 1;
    MaxFlow(0,size-1,cap,flow,minflow,size,hashmap);
    cout << "最大流量:" << maxflow <<endl;
    return 0;
}
