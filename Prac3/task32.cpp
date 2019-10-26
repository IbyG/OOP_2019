#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

const int ROWS=3;
const int COLS=4;

void validateRC(int&,int&);
void checkLURD(int table[ROWS][COLS],int,int);

int main() {
	srand(time(0));

	int table[ROWS][COLS];

	for (int i = 0; i < ROWS; i ++) {
		for (int j = 0; j < COLS; j++)   {
			table[i][j] = rand()%3-1;
		}
	}

	for (int i = 0; i < ROWS; i ++)  {
		for (int j = 0; j < COLS; j++){
			cout << setw(3) << table[i][j];
		}

		cout << endl;
	 }

	 int row, col;
	 cout<<"Type in row and column so you can find its neighbors:"<<endl;
     cin>>row>>col;

     //checking if user input is valid
     validateRC(row,col);

     checkLURD(table,row,col);


	return 0;
}

//validating the user input of row and column
void validateRC(int& row, int& col){

    while(row < 1 && row > ROWS && col < 1 && col > COLS){
        cout<<"What you have typed was invalid please try again(1-4): "<<endl;
        cin>>row>>col;
    }

    //making it validate for grid
    row -= 1;
    col -= 1;
}


//need a function here to accept position and then produce
//left up down and right values
//take the array, user input of x and y
void checkLURD(int table[ROWS][COLS], int row, int col){

    cout<<"you have selected: "<<table[row][col]<<endl;

    //up

    if((row - 1) < ROWS && (row - 1) >= 0 ){
        cout<<endl;
        cout<<"Up is: "<<table[row - 1][col]<<endl;
        cout<<"ROW: "<<row - 1<<" COL: "<<col<<endl;
    }

    if((row + 1)< ROWS&& (row + 1) >= 0){
        cout<<endl;
        cout<<"Down is: "<<table[row + 1][col]<<endl;
        cout<<"ROW: "<<row+1<<" COL: "<<col<<endl;
    }

    if((col-1)< COLS && (col - 1) >= 0){
        cout<<endl;
        cout<<"Left is: "<<table[row][col -1]<<endl;
        cout<<"ROW: "<<row<<" COL: "<<col-1<<endl;
    }

    if((col + 1)< COLS && (col + 1) >= 0){
        cout<<endl;
        cout<<"Right is: "<<table[row][col + 1]<<endl;
        cout<<"ROW: "<<row<<" COL: "<<col+1<<endl;
    }



}
