#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void displayBoard(char board[][4]) {
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

bool isValidMove(char board[][4], int row, int col) {
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

//checking if the board is full
bool checkfull(char board[][4],int row,int col)
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



void askUser(char board[][4]){

    int row,col;

    do {
		cout << "Where would you like to reserve a seat"<<endl;
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(board, row - 1, col - 1));

    row--;
    col--;

	board[row][col] = 'X';

	displayBoard(board);
}

int main() {

	char board[8][4];
	int noOfMoves;

	for (int row = 0; row < 8; row++)
		for (int col = 0; col < 4; col++)
			board[row][col] = '-';


	displayBoard(board);
    string ans = "";

	do{
        cout<<"Would you like to reserve a seat: (y or Y): "<<endl;
        cin >>ans;
        askUser(board);
	}while(ans != "n" && ans != "N" && checkfull(board,8,4));



	return 0;
}
