#ifndef BOARD_H_
#define BOARD_H_


#include<stdio.h>
#include<stdlib.h>
#include <list>



using namespace std;

class Board{

//private values used only in this header
private:
    int row,col;
    //pointer of pointers, dereferencing it
    int **grid;
    list<int> left;

public:

    Board(int r, int c) {
		row = r;
		col = c;
		grid = new int*[row]; //adding the x axis
		for (int i = 0; i < row; i++)
			grid[i] = new int[col]; //adding the y axis

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				grid[i][j] = 0;

		for (int i = 0; i < row*col; i++) {
			left.push_back(i);
		}

	}

    //destructor
	~Board() {
		for (int i = 0; i < row; i++)
			delete[] grid[i];

		delete[] grid;
	}

	Board(Board& cboard) {
		row = cboard.row;
		col = cboard.col;

		grid = new int*[row];
		for (int i = 0; i < row; i++)
			grid[i] = new int[col];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				grid[i][j] = cboard.grid[i][j];
	}

    void printBoard();
    bool checkIfFilled(int,int);
    bool addMove(char,int,int);
    void playerTurn(char,int&, char);
    void split(int&,int&,int);
    bool checkFull();
    void decisionValidate(int,char);
    int getRow();
    int getCol();
};


//prints the display of the board
void Board::printBoard() {
	cout << "    ";
	//printing the column numbers
	for (int j = 0; j < col; j++) {
		cout << j + 1 << "   ";
	}
	cout << endl;

	for (int i = 0; i < row; i++) {
		cout << "  ";
		for (int j = 0; j < col; j++) {
			cout << " ---";
		}
		cout << endl;

        //printing the row numbers
		cout << (i + 1) << " |";

		for (int j = 0; j < col; j++) {
			if (grid[i][j] == 0) {
				cout << "   |";
			} else if (grid[i][j] > 0) {
			    printf(" %c", grid[i][j]);
			    cout<< " |";
				//cout << " " << grid[i][j] << " |";
			} else if (grid[i][j] < 0) {
			    //print the char from the int array grid
			    printf(" %c", grid[i][j]);
			    cout<< " |";
				//cout << "" << grid[i][j] << " |";
			}
		}
		cout << endl;
	}
	cout << "  ";

	for (int j = 0; j < col; j++) {
		cout << " ---";
	}
	cout << endl << endl;
}

//checks the 2d array if the position is taken or not
bool Board::checkIfFilled(int x, int y){

    //false means not empty this includes walls and
    //block filled with O
    x -= 1;
    y -= 1;

    if(x < 0)
        return false;
    if(x > row-1)
        return false;
    if(y < 0)
        return false;
    if(y > col)
        return false;


    if(grid[x][y] != 0 )
        return false;


    //cout<<"Grid: "<<grid[x][y]<<endl;
    return true;



}





int Board::getRow(){
    return row;
}

int Board::getCol(){
    return col;
}


//checking if the entire board spaces are taken up
bool Board::checkFull(){
     //counter keeping track of how many spots are full
	int allFull = 0;

	//checking the board to see if it is full
	for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if (grid[i][j] != 0)
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




bool Board::addMove(char player, int x, int y){
   //adjusting, the board starts at 0 0 not 1 1
    x -= 1;
    y -= 1;

    //setting the position in the grid to the player
    grid[x][y] = player;

    return(true);
}


void Board::split(int& x, int& y, int value){
    x = value/10;
    y = value%10;

}


//keeps track of the player position
//movechoice is L U R D
//currentPos is the players current position
//player is R or B
void Board:: playerTurn(char moveChoice,int& currentPos, char player){
    //converting to lower case
    moveChoice = tolower(moveChoice);

    //splitting the combine int into 2
    int x = currentPos/10;
    int y = currentPos%10;

    //check if there is something in this postion here


    //this position is taken up
    addMove('O',x,y);


    //moving the player
    switch(moveChoice){
        case 'l':
            currentPos -= 1;
            split(x,y,currentPos);
            //new current position
            currentPos = ((x*10) + y);

            decisionValidate(currentPos,player);


            addMove(player,x,y);
            break;
        case 'r':
            currentPos += 1;
            split(x,y,currentPos);
            currentPos = ((x*10) + y);

            decisionValidate(currentPos,player);

            addMove(player,x,y);
            break;
        case 'u':
            currentPos -= 10;
            split(x,y,currentPos);
            currentPos = ((x*10) + y);

            decisionValidate(currentPos,player);

            addMove(player,x,y);
            break;
        case 'd':
            currentPos += 10;
            split(x,y,currentPos);
            currentPos = ((x*10) + y);

            decisionValidate(currentPos,player);

            addMove(player,x,y);
            break;
        default:
            cout<<player<<" What you have typed is invalid.\nTry Again: "<<endl;
            cin>>moveChoice;
            playerTurn(moveChoice,currentPos,player);





    }




}

//checking if the user choice is a good choice or leads to there death
void Board::decisionValidate(int newPosition, char player){

    int x,y;
    //separating the digits
    split(x,y,newPosition);

    //if they hit o or board one person hits
    //if the collide its a draw

    if(!checkIfFilled(x,y)){
            cout<<"Game Over: "<< player<<" Crashed"<<endl;
            //safe exit
            exit(0);
    }



}



#endif // BOARD_H_
