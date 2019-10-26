#include<iostream>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#include "BOARD.H"
#include "AI.H"
#include "HUMANP.H"



void checkBoardSize(int&,int&);
void playAI(int AIchoice,Board board);
void HumanPlayer(Board board);

int main()
{
     //random will just be producing random numbers and trying to and then test if
    int row, col, playMode;

    cout <<"Input the size of board, min(4x4)" << endl;
	cin >> row >> col;

	//validating user input
	if(row < 4 && col < 4)
        checkBoardSize(row,col);

	//initilising the display of the board
    Board board(row,col);


    cout<<"1. PvP\n2. PvDumb\n3. PvMedium"<<endl;
    cin>>playMode;
    switch(playMode){
        case 1:
            HumanPlayer(board);
            break;
        case 2:
            playAI(1,board);
            break;
        case 3:
            playAI(2,board);
            break;

        }



    //playing the game


    return 0;
}

void playAI(int AIchoice,Board board){
    //x is row y is col
    //Rpos and Bpos is the current position of players
    int x,y, Rpos = 22, Bpos = ((board.getRow()-1)*10) + (board.getCol() - 1) ;


    //L U R D choice by the player
    char Rchoice, Bchoice;

    //do {


		cout << "Game board:" << endl;

        //default places for both players red and blue
		board.addMove('R', 2,2);
		board.addMove('B', board.getRow()-1,board.getCol()-1);

		//printing board
		board.printBoard();


        do{
            cout<< "Red player type L, U, R, D: "<<endl;
            cin>> Rchoice;

            //the ai players
            AI aiplayer;


            switch(AIchoice){
                case 1:
                    Bchoice = aiplayer.Dumb();
                    break;
                case 2:
                    Bchoice = aiplayer.medium(board,Bpos, board.getRow(), board.getCol());
                    break;
                default:
                    cout<<"No choice"<<endl;
            }

            cout<<Bchoice<<endl;

            //get current position of player
            //set that to O
            //place the playyer in new position


        board.playerTurn(Rchoice, Rpos, 'R');
        board.playerTurn(Bchoice, Bpos, 'B');
        board.printBoard();


        }while(true);

    //}while(true);

}

void HumanPlayer(Board board){
    //initilising the game by asking the user
    //there move
    //x y is col and grid
    //Rpos and Bpos is the current position of players
    int x,y, Rpos = 22, Bpos = ((board.getRow()-1)*10) + (board.getCol() - 1) ;


    //L U R D choice by the player
    char Rchoice, Bchoice;


		cout << "Game board:" << endl;

        //default places for both players red and blue
		board.addMove('R', 2,2);
		board.addMove('B', board.getRow()-1,board.getCol()-1);

		//printing board
		board.printBoard();



        do{
            HUMANP humanp;
            humanp.hplayer(Rchoice,Bchoice);

            //get current position of player
            //set that to O
            //place the playyer in new position

            board.playerTurn(Rchoice, Rpos, 'R');
            board.playerTurn(Bchoice, Bpos, 'B');
            board.printBoard();

        }while(board.checkFull());

        cout<<"draw as the board is full"<<endl;




}


//makes sure user input is within boundaries
void checkBoardSize(int& row, int& col){

    do
        {
            cout<<"What you have typed is invalid, Please try again min(4x4)"<<endl;
            cin >> row >> col;
        }while(row < 4 && col < 4);

}
