#ifndef FLIGHT.H
#define FILGHT.H

#include<stdio.h>
#include<stdlib.h>
using namespace std;


class Flight{

private:
    char board[8][4];



public:
    //setting the board
    Flight(){
        //initilising the board
        for (int row = 0; row < 8; row++)
            for (int col = 0; col < 4; col++)
                board[row][col] = '-';
    }

    void askUser();
    bool checkfull(int,int);
    bool isValidMove(int,int);
    void displayBoard();



};


//printing the board to the screen
void Flight::displayBoard() {
	cout << "  1 2 3 4"<<endl;
	for (int row = 0; row < 8; row++) {
            cout<<row+1<<" ";
	    for(int col = 0; col < 4; col ++){
            cout<<board[row][col]<<" ";
	    }

	    cout<<endl;
	}

	cout << endl;
}


//asking user where to sit
void Flight::askUser(){

    int row,col;

    do {
		cout << "Where would you like to reserve a seat"<<endl;
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove( row - 1, col - 1));

    row--;
    col--;

	board[row][col] = 'X';

	displayBoard();
}

//checking if all is taken or not
bool Flight::checkfull(int row,int col)
{
     //counter keeping track of how many spots are full
	int allFull = 0;

	//checking the board to see if it is full
	for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if (board[i][j] != 'X')
            {
                allFull += 1;

            }

        }
    }
    //printf("\nAll full %d\n col: %d\n row: %d\n multiplied: %d\n", allFull, col, row, (row * col));
	if(allFull == (row * col))
    {
       // cout<<"Board Full"<<endl;
        return false;
    }
    else
    {
        return true;
    }
}


//check if the position is taken or not.
bool Flight::isValidMove( int row, int col) {
//Add conditions in the "if statement" to check if row and col are in the range between 0-2 and the cell is blank.
//Note that array index starts from 0

	if (row >= 0 && row <= 8 && col >= 0 && col <= 4) //making sure that input is within range
        if(board[row][col] == '-') //making sure it is not taken up
            return true;
    else{
        cout<<"invalid input"<<endl;
        return false;
    }

}

#endif // FLIGHT
