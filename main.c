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
  printf("start\n");
    int board[N][N]={0};
    Info state= {0,0,1};
    int fc=0;
    do{
      printf("show_s\n");
      show(board);
      printf("input_s\n");
      input(&state);
      printf("write_s\n");
      write(board,&state);
      printf("judge_s\n");
      judge(board,&state);
      state.turn++;
    }while(fc>0);
    printf("____終了____\n");
    show(board);
  
    return 0;
    }
int show(const int board[N][N]){
  int i,j;
  printf("現在の盤面:\n");
  for(i=0;i<N;i++){
    printf("|");
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
      case 'w':s->y++;break;
      case 's':s->y--; break;
      case 'a':s->x++; break;
      case 'd':s->x--; break;
    }
  }while(c!='e');
  s->y=s->y/N;
  s->x=s->x/N;
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
  int cx,cy,sx,sy,sxy;
  cx=s->x;
  cy=s->y;
  int x_cp,y_cp;
  x_cp=cx;
  y_cp=cy;
  for(cx=0;cx<N;cx++){
        for(cy=0;cy<N;cy++){
              sx+=board[x_cp][cy];
              sy+=board[cx][y_cp];
              sxy+=board[cx][cy];
        }
  }
int c,fc;
      c=sx+100*sy+10000*sxy;
      fc=0;
   switch(c){
      case V:fc++; break;
      case 100*V:fc++; break;
      case 10000*V:fc++; break;
   }
      return fc;
}

