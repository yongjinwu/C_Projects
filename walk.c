

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h> 
//arrays are RxC
int moveRight(int x,int y,int step,char board[10][10])
{
 if(y+1<=9)
 {
   board[x][y+1]=char(step+66)
   return 0;
 }
 return 1;
}

int moveLeft(int x,int y,int step,char board[10][10])
{
 if(y-1>=0)
 {
   board[x][y-1]=char(step+66)
   return 0;
 }
 return 1;
}

int moveDown(int x,int y,int step,char board[10][10])
{
 if(x+1<=9)
 {
   board[x+1][y]=char(step+66)
   return 0;
 }
 return 1;
}

int moveUp(int x,int y,int step,char board[10][10])
{
 if(x-1>=0)
 {
   board[x-1][y]=char(step+66)
   return 0;
 }
 return 1;
}




int main()
{
    int i;
    int j;
    int curX=0;
    int curY=0;
    int direction;
  char walk[10][10];
  
  //initialize array to contain only '.' characters
  for (i=0;i<10;i++)
  {
    for (j=0;j<10;j++)
    {
        walk[i][j]='.';
    }
  }
  walk[curX][curY]='A';
  //25 steps for B,C,D,...,Z
  for(i=0;i<25;i++)
  {
  //generate a number for direction
  srand (time (NULL));
  direction=(rand()%4);
 
  if (direction==0)
  {
    if(moveRight(curX,curY,i,walk)==0)
    {
      curY+=1;
    }
  }
 
  }
    return 0;
}



