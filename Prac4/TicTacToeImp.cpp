

//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip>

#include "TicTacToe.h"

using namespace std;

void ticTacToe::play()
{
    bool done = false;
    char player = 'X';

    displayBoard();

    while (!done)
    {
        done = getXOMove(player);

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

void ticTacToe::displayBoard() const
{
    cout << "   1    2    3" << endl << endl;

    for (int row = 0; row < 3; row++)
    {
        cout << row + 1;

        for (int col = 0; col < 3; col++)
        {
            cout << setw(3) << board[row][col];

            if (col != 2)
                cout << " |";
        }

        cout << endl;

        if (row != 2)
            cout << " ____|____|____" << endl
                 << "     |    |    " << endl;
    }

    cout << endl;
}

bool ticTacToe::isValidMove(int row, int col) const
{
    if (true /*See your solution to Practical 3 Task 3.3 or ask your tutor for a solution */)
        return true;
    else
        return false;
}

bool ticTacToe::getXOMove(char playerSymbol)
{
    int row, col;

    do
    {
        cout << "Player " << playerSymbol
             << " enter move: ";
        cin >> row >> col;
        cout << endl;
    }
    while (!isValidMove(row - 1, col - 1) );

    row--;
    col--;

    noOfMoves++;

    board[row][col] = playerSymbol;
    displayBoard();

    status gStatus = gameStatus();

    if (gStatus == WIN)
    {
        cout << "Player " << playerSymbol << " wins!" << endl;
        return true;
    }
    else if (gStatus == DRAW)
    {
        cout << "This game is a draw!" << endl;
        return true;
    }
    else if(noOfMoves >= 9) {
    	return true;
    } else
        return false;
}

status ticTacToe::gameStatus()
{
    //Write your code here to check if the game has been in a win status or a draw status
    //Check rows for a win

    int allfull;

    //checking if all positions are taken
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++){
            if(board[row][col] != ' ')
                allfull += 1;
        }

    if(allfull == 9){
        return DRAW;
    }

    // any of the rows is same
 for (int i=0; i<=2; i++)
 {
  if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!= ' ')
    return WIN;

 }

 // any of the columns is same
 for(int i=0; i<=2; i++)
 {
  if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!= ' ')
    return WIN;

 }

 // 1st diagonal is same
 if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
    return WIN;


 // 2nd diagonal is same
 if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board [0][2]!=' ')
    return WIN;

   return CONTINUE;
}

void ticTacToe::reStart()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

/*
//either hard coded or through user input
ticTacToe::ticTacToe(int row, int col){
    for (int Row = 0; Row < row; Row++)
        for (int Col = 0; Col < col; Col++)
            board[Row][Col] = ' ';

    noOfMoves = 0;
}
*/
