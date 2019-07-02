#include <stdio.h>
#include <string.h>

#define MAX 8

int tit = 1;

int board[MAX][MAX];

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    if(size == 1) return ;
    int s = size/2;
    int t = tit++;
    //左上角
    if(tr+s > dr && tc+s > dc)
    {
        ChessBoard(tr,tc,dr,dc,s);
    }
    else
    {
        board[tr+s-1][tc+s-1] = t;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    //右上角
    if(tr+s <= dr && tc+s > dc)
    {
        ChessBoard(tr+s,tc,dr,dc,s);
    }
    else
    {
        board[tr+s][tc+s-1] = t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }

    //左下角
    if(tr+s > dr && tc+s <= dc)
    {
        ChessBoard(tr,tc+s,dr,dc,s);
    }
    else
    {
        board[tr+s-1][tc+s] = t;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    
    //右下角
    if(tr+s <= dr && tc+s <= dc)
    {
        ChessBoard(tr+s,tc+s,dr,dc,s);
    }
    else
    {
        board[tr+s][tc+s] = t;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}

void Show()
{
    int i = 0;
    int j = 0;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            printf("%3d",board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    memset(board,0xff,sizeof(int)*MAX*MAX);
    board[2][3] = 0;
    ChessBoard(0,0,2,3,MAX);
    Show();
    return 0;
}
