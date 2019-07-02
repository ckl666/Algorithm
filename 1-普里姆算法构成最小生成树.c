#include <stdio.h>

#define MAX 10
#define INF 0x3f3f3f3f
#define N 5

//存放已找到顶点
//存放未找到的顶点
//存放图
//
//存放最短路径 每次添加一个节点就跟新最短路径
//
//

int map[MAX][MAX] = {
    {0,INF,3,INF,10},
    {INF,0,2,INF,INF},
    {3,2,0,INF,INF},
    {INF,5,INF,0,INF},
    {INF,INF,INF,3,0},
};

void Show(int closest[])
{
    int i = 0;
    for(i = 0; i < N; i++)
    {
        printf("(%d %d) ",i,closest[i]);
    }
    printf("\n");
}

void Prim(int v)
{
    int lowest[MAX];        //存放已选中的集合中的元素到未选择集合中元素的路径
    int closest[MAX];       //存放有公共边的两个顶点
    int i = 0;
    int j = 0;
    for(i = 0; i < N; i++)
    {
        lowest[i] = map[v][i];
        closest[i] = v;
    }
    for(i = 1; i < N; i++)   //表示顶点的个数
    {
        int k = -1;
        int minest = INF;
        for(j = 0; j < N; j++)  //表示顶点的下标
        {
            if(lowest[j] != 0 && minest > lowest[j])
            {
                minest = lowest[j];
                k = j;
            }
        }
        if(k == -1)
        {
            printf("非连通图\n");
            return;
        }
        lowest[k] = 0;
        //添加一个顶点后更新lowest closest
        for(j = 0; j < N; j++)
        {
            if(lowest[j] != 0 && lowest[j] > map[k][j])
            {
                lowest[j] = map[k][j];
                closest[j] = k;
            }
        }
    }
    Show(closest);
}


int main()
{
    Prim(0);
    return 0;
}
