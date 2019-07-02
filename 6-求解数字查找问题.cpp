#include <iostream>
#include <queue>
#include <vector>

#define MAX 100
#define INF 0x3f3f3f3f

using namespace std;

int Min = INF;

typedef struct Node
{
    int count;    //次数
    long long x;      //基数 
}Node;


void Fun(int x,int num)
{
    Node e;
    queue<Node> qu;
    e.count = 0;
    e.x = x;
    qu.push(e);
    while(!qu.empty())
    {
        e = qu.front();
        qu.pop();
        Node e1 = e;
        if(e.count < 10)
        {
            if((e.x*4+3)%num == 0 || (e.x*8+7)%num == 0)
            {
                e.count++;
                if(e.count < Min)
                {
                    Min = e.count;
                }
            }
            else
            {
                Node e1 = e;
                e1.x = (e.x*4+3)%num;
                e1.count++;
                if(e1.count < Min)
                {
                    qu.push(e1);
                }
                Node e2 = e;
                e2.x = (e.x*8+7)%num;
                e2.count++;
                if(e2.count < Min)
                {
                    qu.push(e1);
                }
            }
        }
    }
}
//所需的空间是指数级的，循环的次数过多会使程序挂掉

int main()
{
    Fun(1000000,1000000007);
    if(Min < INF)
    {
        cout<<"最少的次数为"<<Min<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}
