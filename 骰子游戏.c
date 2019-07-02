#include <stdio.h>
#include <assert.h>

int Fun(int n)
{
    if(n > 0)
    {
        return Fun(n-1)+Fun(n-2)+Fun(n-3)+Fun(n-4)+Fun(n-5)+Fun(n-6);
    }
    else if(n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//
int main()
{
    printf("%d \n",Fun(2));
    return 0;
}
