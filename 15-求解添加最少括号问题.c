#include <stdio.h>
#include <string.h>

#define MAX 100
#define INF 0x3f3f3f3f

//回溯加动态规划
int Min = INF;

void Fun(char str[],int stack[],int top,int i,int n,int dp)
{
    if(str[i] == '\0')
    {
        if(top > 0)
        {
            dp += top;
        }
        if(Min > dp)
        {
            Min = dp;
        }
    }
    else
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            stack[top++] = str[i];
            Fun(str,stack,top,i+1,n,dp);
        }
        else if(top>0 && ((str[i]==')' && stack[top-1]=='(') || (str[i] == ']' && stack[top-1] == '[') || (str[i] == '}' && stack[top-1] == '{')))
        {
            top--;
            Fun(str,stack,top,i+1,n,dp);
        }
        else if(top <= 0)
        {
            dp++;
            Fun(str,stack,top,i+1,n,dp);
        }
        else
        {
            dp++;
            top--;
            Fun(str,stack,top,i,n,dp);
            top++;
            Fun(str,stack,top,i+1,n,dp);
        }
    }
}


int main()
{
    char str[] = "({)}";
    int n = strlen(str);
    int stack[MAX];
    int top = 0;
    int dp = 0;
    Fun(str,stack,top,0,n,dp);
    printf("%d \n",Min);
    return 0;
}
