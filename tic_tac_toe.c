#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBoard();
int winner_check();
char board[10]={'0','1','2','3','4','5','6','7','8','9'};

int main()
{   
    char replay='Y';
    do
    {
        int player=1, input, status=-1, result;
        board[0]='0',board[1]='1',board[2]='2',board[3]='3',board[4]='4',board[5]='5',board[6]='6',board[7]='7',board[8]='8',board[9]='9';
        printBoard();

        while (status == -1)
        {
            player=(player%2==0) ? 2 : 1;
            char mark=(player==1)? 'X' : 'O' ;
            printf("Enter the number for player %d where you want to put your %c: ", player, mark);
            scanf("%d",&input);

            if(input<1 || input>9)
            {
                printf("Invaild input.");
            }

            if(board[input]!='X' && board[input]!='O')
            {
                board[input]=mark;
            }
            else{
                printf("You have entered in already filled box, please choose another one, This is your last chance: ");
                scanf("%d",&input);
                if(board[input]!='X' && board[input]!='O')
                {
                    board[input]=mark;
                }
            }
            printBoard();

            result=winner_check();
            if (result==1)
            {
                printf("Player %d is the Winner.", player);
                printf("\nDo you want to start a new game? (Y/N)\n");
                scanf(" %c",&replay);
                break;
            }
            else if(result==0)
            {
                printf("Draw");
                printf("\nDo you want to start a new game? (Y/N)\n");
                scanf(" %c",&replay);
                break;
            }
            player++;
        }
    }while(replay == 'y' || replay == 'Y');

return 0;
}


void printBoard(){
    // system("cls");
    printf("\n\n");
    printf("======== TIC TAC TOE ========\n");
    printf("        |        |        \n");
    printf("    %c   |   %c    |    %c   \n",board[1],board[2],board[3]);
    printf("        |        |        \n"); 
    printf("--------|--------|--------\n");
    printf("        |        |        \n");
    printf("    %c   |   %c    |    %c   \n",board[4],board[5],board[6]);
    printf("        |        |        \n");  
    printf("--------|--------|--------\n");
    printf("        |        |        \n");
    printf("    %c   |   %c    |    %c   \n",board[7],board[8],board[9]);
    printf("        |        |        \n"); 
    printf("\n\n");
}


int winner_check()
{
    /* checking every possible combinations of winner */
    if(board[1]==board[2] && board[2]==board[3])
    {
        return 1;
    }
    if(board[4]==board[5] && board[5]==board[6])
    {
        return 1;
    }
    if(board[7]==board[8] && board[8]==board[9])
    {
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7])
    {
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8])
    {
        return 1;
    }
    if(board[3]==board[6] && board[6]==board[9])
    {
        return 1;
    }
    if(board[1]==board[5] && board[5]==board[9])
    {
        return 1;
    }
    if(board[3]==board[5] && board[5]==board[7])
    {
        return 1;
    }

    /* To check if game is over or all boxes are full or not */
    int count=0;
    for(int i=1; i<=9; i++)
    {
        if(board[i]=='X' || board[i]=='O')
        {
            count++;
        }
    }

    if (count==9)
    {
        return 0;
    }

    return -1;
}