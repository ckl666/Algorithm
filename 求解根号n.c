#include <stdio.h>


int SqrtN(int n)
{
    int i = 0;
    for(i = 1; i <= n; i++)
    {
        if(i*i <= n && (i+1)*(i+1) > n)
        {
            return i;
        }
    }
}

int main()
{
    int i = 1;
    for(i = 1; i <= 20; i++)
    {
        printf("根号 %d = %d \n",i,SqrtN(i));
    }
    return 0;
}
