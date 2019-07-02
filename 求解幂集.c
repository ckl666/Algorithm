#include <math.h>
#include <stdio.h>
#include <assert.h>






/*方法一
void Inc(int *b,int n)
{
    assert(b != NULL);
    int i = 0;
    for(i = 0; i < n; i++)
    {
        if(b[i] == 0)
        {
            b[i] = 1;
            break;
        }
        else
        {
            b[i] = 0;
        }
    }
}

int PSet(int *a,int *b,int n)
{
    assert(a != NULL && b != NULL);
    int i = 0;
    int pw = 1;
    for(i = 0; i < n; i++)
    {
        pw *= 2;
    }
    for(i = 0; i < pw; i++)
    {
        printf("{");
        int j = 0;
        for(j = 0; j < n; j++)
        {
            if(b[j] != 0)
            {
                printf("%d ",a[j]);
            }
        }
        printf("}\n");
        Inc(b,n);
    }
}

*/

int main()
{
    int n = 3;
    int a[] = {1,2,3};
    int b[] = {0,0,0};
    PSet(a,b,n);
    //printf("%d \n",pw);
    return 0;
}
