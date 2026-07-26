#include<stdio.h>
typedef struct{
      int x;
      int y;
      int turn;
    }Info;
#define N 3
int main(){
    int board[N][N]={0};
    Info state= {0,0,1};
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
int show(const int *board[N][N]){
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
    switch(input){
      case 'w':s->(*y)++; break;
      case 's':s->(*y)--; break;
      case 'a':s->(*x)++; break;
      case 'd':s->(*x)--; break;
    }
  }while(input!='e');
  return 0;
}
int write(int board[N][N],Info *s){
  t=s->turn;
  x=s->x;
  y=s->y;
  player=t%2;
  if(player==1){
     board[x][y]=1;
  }else{
     board[x][y]=2;
  }
}
int judge(int board[N][N],Info *s){
  int cx,cy,cxy;
  x=s->x;
  y=s->y;
  int x_cp,y_cp;
  x_cp=x;
  y_cp=y;
  for(x=0;x<N;x++){
        for(y=0;y<N;y++){
              cx=c+board[x_cp][y];
              cy=c+board[x][y_cp];
              cxy=c+board[x][y];
        }
  }
int c,v,fc;
      c=cx+100*cy+10000*cxy;
      v=3;
      fc=0;
   switch(c){
      case v:fc++; break;
      case 100*v:fc++; break;
      case 10000*v:fc++; break;
   }
      return fc;
}
