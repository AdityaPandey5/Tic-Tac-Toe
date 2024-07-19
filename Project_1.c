// TIC TAC TOE
#include<stdio.h>
char board[]={'0','1','2','3','4','5','6','7','8','9'};
void printboard();
int results();
void system();
void main()
{

    printboard();
    int player=1,input,status=2,flag;
    char mark;
    while (status==2)
    {

        //the gameplay
        if (player%2==0)
            mark = 'O';
        else
            mark = 'X';
        printf("Enter the position at which you want to keep your token for PLAYER %c: ",mark);
        scanf("%d",&input);
        if (input<1 || input>9 || board[input]=='X' || board[input]=='O')
        {
            printf("\nInvalid input\n");
            flag=0;
        }
        else 
        {
            flag=1;
        }
        if (flag==1)
        {
        board[input]=mark;
        printboard();

        //for results
        int result=results();
        if(result==1)
        {
            printf("Player %c is the winner",mark);
            return;
        }
        else if(result==3)
        {
            printf("The match is not won by any player");
            return;
        }
        
        player++;
        }
    }
}
void printboard()
{

    //Layout of the board
    system("cls");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n",board[1],board[2],board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n",board[4],board[5],board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n",board[7],board[8],board[9]);
    printf("     |     |     \n");
}
int results()
{

    //for true conditions i.e. match won by a player
    if (board[1]==board[2] && board[2]==board[3])
        return 1;
    if (board[4]==board[5] && board[5]==board[6])
        return 1;
    if (board[7]==board[8] && board[8]==board[9])
        return 1;
    if (board[1]==board[4] && board[4]==board[7])
        return 1;
    if (board[2]==board[5] && board[5]==board[8])
        return 1;
    if (board[3]==board[6] && board[6]==board[9])
        return 1;
    if (board[1]==board[5] && board[5]==board[9])
        return 1;
    if (board[3]==board[5] && board[5]==board[7])
        return 1;

    //for conditions not being true i.e. draw match
    int i,count=0;
    for (i=1 ; i <= 9 ; i++)
    {
        if (board[i]=='X' || board[i]=='O')
            count++;
    }
    if (count==9)
        return 3;
    
    //for failure of both scenerios 
    return 2;
}