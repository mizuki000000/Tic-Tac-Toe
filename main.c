#include<stdio.h>
typedef struct{
      int x;
      int y;
      int turn;
    }Info;
#define N 3
#define V 3
int show(const int board[N][N]);
int input(Info *s);
int write(int board[N][N],Info *s);
int judge(int board[N][N],Info *s);
int main(){
    int board[N][N]={0};
    Info state= {0,0,1};
    int fc=0;
    do{
      show(board);
      input(&state);
      write(board,&state);
      judge(board,&state);
      state.turn++;
    }while(fc>0);
    printf("____終了____");
    show(board);
  
    return 0;
    }
int show(const int board[N][N]){
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(board[i][j]==1){
        printf("×");
      }else if(board[i][j]==2){
        printf("○");
      }else{
        printf(" ");
      }
      printf("|");
    }
    printf("\n");
  }
  return 0;
}
int input(Info *s){
  char c;
  printf("wasdで入力、eで決定");
  do{
    scanf("%c",&c);
    switch(c){
      case 'w':s->y++; break;
      case 's':s->y--; break;
      case 'a':s->x++; break;
      case 'd':s->x--; break;
    }
  }while(c!='e');
  return 0;
}
int write(int board[N][N],Info *s){
  int t=s->turn;
  int x=s->x;
  int y=s->y;
  int player=t%2;
  if(player==1){
     board[x][y]=1;
  }else{
     board[x][y]=2;
  }
}
int judge(int board[N][N],Info *s){
  int cx,cy,cxy;
  cx=s->x;
  cy=s->y;
  int x_cp,y_cp;
  x_cp=cx;
  y_cp=cy;
  for(cx=0;cx<N;cx++){
        for(cy=0;cy<N;cy++){
              cx=cx+board[x_cp][cy];
              cy=cy+board[cx][y_cp];
              cxy=cxy+board[cx][cy];
        }
  }
int c,fc;
      c=cx+100*cy+10000*cxy;
      fc=0;
   switch(c){
      case V:fc++; break;
      case 100*V:fc++; break;
      case 10000*V:fc++; break;
   }
      return fc;
}
