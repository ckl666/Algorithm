#include <stdio.h>

#define MAX 10

bool Judge(int n)
{
    int i = 0;
    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}



int main()
{
    return 0;
}
