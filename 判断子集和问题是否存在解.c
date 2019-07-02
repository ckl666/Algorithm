#include <stdio.h>

bool Fun(int *w,int sum,int i,int len,int W)
{
    if(sum > W)
    {
        return false;
    }
    if(i >= len)
    {
        if(sum == W)
        {
            return true;
        }
    }
    else
    {
        if(Fun(w,sum+w[i],i+1,len,W))
        {
            return true;
        }
        return Fun(w,sum,i+1,len,W);
    }
    return false;
}

int main()
{
    int w[] = {11,13,24,7};
    int len = sizeof(w)/sizeof(w[0]);
    int W = 7;
    printf("W = %d  %s\n",W,Fun(w,0,0,len,W)?"存在解":"不存在解");
    W = 15;
    printf("W = %d  %s\n",W,Fun(w,0,0,len,W)?"存在解":"不存在解");
    W = 31;
    printf("W = %d  %s\n",W,Fun(w,0,0,len,W)?"存在解":"不存在解");
    W = 18;
    printf("W = %d  %s\n",W,Fun(w,0,0,len,W)?"存在解":"不存在解");
    return 0;
}
