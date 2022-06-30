/* 
* Name: <YOUR NAME>
* Roll number: <YOUR ROLL NUMBER>
* Type your code below this line
* There are no testcases. Mentor TA and Student will play to verify it!
*/

#include <stdio.h>

char board[1000][1000];
int N=3; // the board size

char player[2]  = {'X','O'};; // Player 1 is X and Player 2 is O


/* function to initialize the board to blank space */
void init(); 

/* function to print the board in front of the user */
void showconfig(void);

/* function to check if any player is winning or if it is a draw
returns 1 if win/draw and prints appropriate message
returns 0 if game can continue */
int checkwindir(int,char);

int checkwin();

/* function to check if a given move (i,j) is legal or not */
int checklegal(int, int);

/* function to implement an actual move */
void putsymbol(int,int,char);
int main()
{
  init(); //printing empty board
  int i,j,k,l,flag = 0;
  int p = 0;
  while(1)
  {
    printf("player %c",player[p]); 
    scanf("%d%d",&i,&j);  //input to put symbol in a box
    
    if(checklegal(i,j) == 0) continue; //checking whether legal or not
    putsymbol(i,j,player[p]);
    
    if(checkwin() == 1) //checking if 1 or 2 won
      break;
//checking is board filled if filled a draw
    flag = 0;
    for(k = 0;k < N;k++)
    {
      for(l = 0;l < N;l++)
      {
        if(board[k][l] != '\0') 
        {
          flag += 1;
        }
      }
    }
 
    if (flag == N*N)
    {
      printf("It's a Draw\n");
      break;
    }
//    printf("%c%d",board[i][j],(board[i][j] == player[p]));
    p = (p+1)%2;
    showconfig();
  }
}

void init() //function to initialise empty board
{
  printf("\n--------------\n");
  for (int i=0; i<N; i++)
  {
    for (int j=0; j<N; j++)
     printf("|   ");
    printf("|\n--------------\n");
  }
}

void showconfig() //function to show present configuration of board
{
  printf("\n--------------\n");
  for (int i=0; i<N; i++)
  {
    for (int j=0; j<N; j++)
     printf("| %c ",board[i][j]);
    printf("|\n--------------\n");
  }
}

int checkwindir(int dir,char c) //function to check if 1 or 2 won
{
  int i,j;
  switch(dir)
  {
  case 1:
  {
    for (i = 0;i < N;i++)
    {
      for (j = 0;j < N;j++)
        if(board[i][j] != c) break;
      if(j == N)
        return 1;
    }
  } break;
  case 2:
  {
    for (i = 0;i < N;i++)
    {
      for (j = 0;j < N;j++)
        if(board[j][i] != c) break;
      if(j == N)
        return 1;
    }
  } break;
  case 3:
  {
      for (j = 0;j < N;j++)
        if(board[j][j] != c) break;
      if(j == N)
        return 1;
  } break;
  case 4:
  {
      for (j = 0;j < N;j++)
        if(board[j][N-1-j] != c) break;
      if(j == N)
        return 1;
  }
  }
  return 0;
}
//function to implement checkwindir function
int checkwin(){ 
  for(int i = 1; i < 5; i++){
    for(int j = 0; j < 2; j++){
      int temp = checkwindir(i, player[j]);
      if(temp == 1){
        printf("Player %d Wins\n",j+1);
        return 1;
      }
    }
  }
  return 0;
}
//function to check whether step is legal or not
int checklegal(int i,int j)
{
  if (board[i][j] == '\0')
  return 1;
  else return 0;
}
//function to put symbol on the board
void putsymbol(int i,int j,char c)
{
  board[i][j] = c;
}

