#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
typedef struct{
      int x;
      int y;
      int turn;
      int menber;
    }Info;
#define N 3
#define V 3
int show(const int board[N][N]);
int input(const int board[N][N],Info *s);
int write(int board[N][N],Info *s);
int judge(int board[N][N],Info *s);
int main(){
  int menber;
  int fc=0;
  int board[N][N]={0};
  Info state= {0,0,1};
  do{
    printf("1:1人、2:2人で遊ぶ\n 入力\n");
    scanf("%d",&state.menber);
    if (state.menber != 1 && state.menber != 2){
      printf("入力に失敗しました。\n");
        while (getchar() != '\n');
        state.menber = 0;
        continue;
    }
  }while(state.menber != 1 && state.menber != 2);
 
  do{
    state.x = 0;
    state.y = 0;  
    //printf("show_s\n");
    show(board);
    //printf("input_s\n");
    input(board,&state);
    //printf("write_s\n");
    write(board,&state);
    //printf("judge_s\n");
    printf("player:%d,%d\n", state.x, state.y);
    judge(board,&state);
    state.turn++;
    printf("結果確認：%d\n", fc);
  }while(fc==0);
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
      if(board[j][i]==1){
        printf("×");
      }else if(board[j][i]==2){
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
int input(const int board[N][N],Info *s){
  char c;
  int turn=s->turn%2;
  printf("pleyer%d人",s->menber);
  if((s->menber==1)&&(turn==0)){
    int x,y;
    do{
    x=rand()%N;
    y=rand()%N;
    }while (board[s->y][s->x]==0);
    s->x=x;
    s->y=y;
    printf("CPU:%d,%d",x,y);
  }else{
    printf("wasdで入力、eで決定\n");
    do{
      scanf("%c",&c);
      switch(c){
        case 'w':s->y--; break;
        case 's':s->y++; break;
        case 'a':s->x--; break;
        case 'd':s->x++; break;
      }
      s->y=s->y%N;
      s->x=s->x%N;
    }while(c!='e');
    
    if(s->x<0){
      s->x+=N;
    }
    if(s->y<0){
      s->y+=N;
    }
    if(board[s->y][s->x]!=0){
      printf("その枠は埋まっています\n");
      input(board,s);
    }
  }
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
