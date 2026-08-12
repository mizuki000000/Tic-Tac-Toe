#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define N 3
#define V 3
#define total_players 2

typedef struct{
      int x;
      int y;
      int turn;
      int menber;
      int current_turn;
      int count_1[3*N];
      int count_2[3*N];
    }Info;
int show(const int board[N][N]);
int input(const int board[N][N],Info *s);
int write(int board[N][N],const Info *s);
int judge(int board[N][N],Info *s);
int main(){
  //設定
  int menber;
  int fc=0;
  int board[N][N]={0};
  Info state= {0};
  srand(time(NULL));
  //プレイヤー数の選択
  do{
    printf("1:1人、2:2人で遊ぶ\n 入力\n");
    scanf("%d",&state.menber);
    if (state.menber != 1 && state.menber != 2&& state.menber != 3){
      printf("入力に失敗しました。\n");
        while (getchar() != '\n');
        state.menber = 0;
        continue;
    }
  }while(state.menber != 1 && state.menber != 2&& state.menber != 3);
  //メインループ
  do{
    state.x = 0;
    state.y = 0;
    state.current_turn = state.turn%2;
    //printf("current_turn:%d",state.current_turn) ;
    //printf("show_s\n");
    show(board);
    printf("input_s\nturn=%d menber=%d x=%d y=%d\n",
       state.turn,
       state.menber,
       state.x,
       state.y);
    input(board,&state);
    //printf("write_s\n");
    write(board,&state);
    //printf("judge_s\n");
    //printf("player:%d,%d\n", state.x, state.y);
    fc=judge(board,&state);
    state.turn++;
    printf("結果確認：%d\n", fc);
  }while(fc==0);
  printf("____終了____\n");
    show(board);
    switch(fc){
      case -1:printf("draw");
    
    }
    return 0;
    }
int show(const int board[N][N]){
  int i,j;
  printf("現在の盤面:\n");
  for(i=0;i<N;i++){
    printf("|");
    for(j=0;j<N;j++){
      switch(board[i][j]){
        case 1:
          printf("1");break;
        case 2:
          printf("2");break;
        case 0:
          printf("0");break;
      }
      printf("|");
    }
    printf("\n");
  }
  return 0;
}
int input(const int board[N][N],Info *s){
  char c;
  s->x = 0;
  s->y = 0; 
  printf("pleyer%d人",s->menber);
  if((s->menber==1)&&(s->current_turn==0)){
    printf("CPU:\n");
    int x,y;
    do{
      x=rand()%N;
      y=rand()%N;
      //printf("CPU_think:%d,%d\n",x,y);
      //printf("board_check:%d\n",board[y][x]);
    }while (board[y][x]!=0);
    s->x=x;
    s->y=y;
    printf("CPU_select:%d,%d\n",x,y);
  }else if(s->menber==3){
      printf("CPU:\n");
    int x,y;
    do{
      x=rand()%N;
      y=rand()%N;
      //printf("CPU_think:%d,%d\n",x,y);
      //printf("board_check:%d\n",board[y][x]);
    }while (board[y][x]!=0);
    s->x=x;
    s->y=y;
    printf("CPU_select:%d,%d\n",x,y);
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
}
int write(int board[N][N],const Info *s){
  if(s->current_turn==1){
     board[s->y][s->x]=1;
  }else{
     board[s->y][s->x]=2;
  }
}
int judge(int board[N][N],Info *s){
  int fc=0,i=0,j=0;
  int m;
  if(s->turn>=N*N-1){
    fc=-1;
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      switch(board[i][j]){
        case 1:s->count_1[i]++;break;
        case 2:s->count_2[i]++;break;
      }
      switch(board[j][i]){
        case 1:s->count_1[i+N]++;break;
        case 2:s->count_2[i+N]++;break;
      }
    
       //printf("p1_count:%d,",s->count_1[i]);
       //printf("p2_count:%d,",s->count_2[i]);
    }   
    switch(board[i][i]){
      case 1:s->count_1[2*N]++;break;
      case 2:s->count_2[2*N]++;break;
    }
       switch(board[i][N-1-i]){
      case 1:s->count_1[1+2*N]++;break;
      case 2:s->count_2[1+2*N]++;break;
    }
  }
  for(i=0;i<N*N;i++){
    if(s->count_1[i]==N){
      fc=1;
    }
    if(s->count_2[i]==N){
      fc=2;
    }
    s->count_1[i]=0;
    s->count_2[i]=0;
  }
  return fc;
}
