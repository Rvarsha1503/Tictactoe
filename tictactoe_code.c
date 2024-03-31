#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER ='O';


void resetboard();
void printboard();
int checkfreespace();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);

int main(){
    
    char winner = ' ';
    char responce;
    char a;
    
    printf("\t\t\t\t\t\t_____________________________________\n\n");
    printf("\t\t\t\t\t\t*************************************\n");
    printf("\t\t\t\t\t\t   Let's start the game, shall we?\n");
    printf("\t\t\t\t\t\t      To start, Enter any key\n");
    printf("\t\t\t\t\t\t*************************************\n");
    printf("\t\t\t\t\t\t_____________________________________\n\n"); 

    getch();


    printf("\n\n\n \t\t\t\t\t\tX - you. O - computer.\n\n\n\n\n");

    do
    {
       winner = ' ';
       responce = ' '; 
       resetboard();       // To clear the existing board on the screen for new turn.
    
            while(winner == ' ' && checkfreespace() != 0)
            {
                printboard();       /*to print the board.*/

                playermove();       // to register the player's move.
                
                winner = checkwinner();

                if (winner != ' ' || checkfreespace() == 0)
                {
                    break;
                }

                computermove();       // to register the computer's move.
                
                winner = checkwinner();

                if (winner != ' ' || checkfreespace() == 0)
                {
                    break;
                }
            }

        printboard();
        printwinner(winner);

        printf("\t\t\t\t\t\tWould you like to play again? \n\t\t\t\t\t\tY - for yes, N -for no. (not case sensitive)\n\t\t\t\t\t\t");
        
        scanf("%c", &a);
        scanf("%c", &responce);
        responce = toupper(responce);        

    } while (responce == 'Y');
    
    printf("\t\t\t\t\t\t_____________________________________\n\n");
    printf("\t\t\t\t\t\t*************************************\n");
    printf("\t\t\t\t\t\t       Thanks for playing!\n");
    printf("\t\t\t\t\t\t*************************************\n");
    printf("\t\t\t\t\t\t_____________________________________\n"); 

  return 0;  
}

void resetboard(){
     
     for(int i=0; i<3; i++)
     {
        for(int j=0; j<3; j++)
        {
          board[i][j] = ' ';
        }  
     }

}
void printboard(){
     
     printf("\t\t\t\t\t\t %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
     printf("\n\t\t\t\t\t\t---|---|---\n");
     printf("\t\t\t\t\t\t %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
     printf("\n\t\t\t\t\t\t---|---|---\n");
     printf("\t\t\t\t\t\t %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
     printf("\t\t\t\t\t\t\n\n");
    
}

int checkfreespace(){
    
    int freespaces = 9;
    for (int i=0; i<3; i++)
    {
         for (int j=0; j<3; j++)
        {
            if (board[i][j] != ' ')
            {
                freespaces--;
            }
        }  
    } 
    
    return freespaces;
}

void playermove(){
    
    int x;
    int y;

    for(int i=0; board[x][y] != ' '; i++)
    {
        printf("\n\t\t\t\t\t\tEnter the row you wanna move to (1-3): \n\t\t\t\t\t\t");
        scanf("%d", &x);
        x--;
        
        printf("\n\t\t\t\t\t\tEnter the coloum you wanna move to (1-3): \n\t\t\t\t\t\t");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("\t\t\t\t\t\tInvalid move!");
        } 
        else
        {
            board[x][y] = PLAYER;
            break;
        }
   }
}

void computermove(){
     
     int x,y;
    srand(time(0));
    if (checkfreespace > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;       
    } 
    else
    {
        printwinner(' ');
    }

}

char checkwinner(){
    // checking winner in rows.

    for(int i=0; i<3; i++)
    {
       if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
       {
           return board[i][0];
       }
    } 
  
   //checking winner for coloums.

    for(int i=0; i<3; i++)
    {
       if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
       {
           return board[0][i];
       }
    } 

    //checking winner for diagonals.
    
       if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
       {
           return board[0][0];
       }
       if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
       {
           return board[0][2];
       }

   return ' ';      
}

void printwinner(char winner){

    if (winner == PLAYER)
    {
        
        printf("\t\t\t\t\t\t*************************************\n");
        printf("\t\t\t\t\t\t_____________________________________\n"); 
        printf("\t\t\t\t\t\tYOU WIN B!! YAAAASSS SLAAAAAY!!\n");
        printf("\t\t\t\t\t\t*************************************\n");
        printf("\t\t\t\t\t\t_____________________________________\n\n"); 
    }
    else if (winner == COMPUTER)
    {
        printf("\t\t\t\t\t\tPSST! YOU LOOSE!!\n");
    }
    else
    {
        printf("\t\t\t\t\t\tIT'S A TIE! AWW!\n");
    }
}
