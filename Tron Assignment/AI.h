#ifndef AI_H_
#define AI_H_


#include "Board.h"
class Board;

class AI{
public:


    //just picks a random number different from the previous choice
    char Dumb(){

    static int previousDecisions = 0;
    int decision = 0;

    //gettin a move that is different from previous moves
    do{
       decision = produceNum();
    }while( previousDecisions == decision);

    previousDecisions = decision;


    return moves(decision);


    }


    /*
            if we go UP then our next options would be everything else but the opposite
            which is DOWN.

            get current position
            check if at corner or edge and that eliminates some moves

    */
    char medium(Board board, int currentPos, int row, int col){

        static int previousDecision = 0;
        //the decision in int form
        int decision = 0;
        //the decision converted to char
        char fdecision;

        int x ,y;
        char filled;
        bool u; bool d; bool l; bool r;
        u=d=l=r = false;



        //splitting the current pos into 2 digits
        board.split(y,x,currentPos);

        //cout<<"Current pos: "<<x<<y<<endl;

        //checking if the positions around current position is taken
        checkOpenPositions(board,filled, u,d,l,r,x,y);




        //making sure that the current move isnt the opposite of previous move
         do{
            decision = produceNum();
        }while(!validMove(decision,previousDecision));

        fdecision = moves(decision);
        //cout<<"Fdecisions is: "<<fdecision<<endl;

        if(fdecision == 'U' && u){
            previousDecision = decision;
            //cout<<"B Decision: "<<decision<<endl;
            return moves(decision);
        }


        if(fdecision == 'D' && d){
            previousDecision = decision;
            //cout<<"B Decision: "<<decision<<endl;
            return moves(decision);
        }

        if(fdecision == 'R' && r){
            previousDecision = decision;
            //cout<<"B Decision: "<<decision<<endl;
            return moves(decision);
        }

        if(fdecision == 'L' && l){
             previousDecision = decision;
             //cout<<"B Decision: "<<decision<<endl;
             return moves(decision);
        }


        //cout<< currentPos<<" x: "<<row<<"y: "<<col<<endl;


        //cout<<"B filled: "<<filled<<endl;
        return filled;

    }

    //produces random int from 1 to 4
    int produceNum(){
        srand(time(NULL));
        return (rand() % 4)+1;
    }

    //makes sure the AI does not go back the way they came
    bool validMove(int num, int prevnum){

        //first ever move
        if(prevnum == 0)
            return true;

        //last move is down this move is up(crash)
        if(num == 1 && prevnum == 2)
            return false;

        //last move is up this move is down(crash)
        if(num == 2 && prevnum == 1)
            return false;
        //last move is left this move is right(crash)
        if(num == 3 && prevnum == 4)
            return false;

        //last move is right this move is left(crash)
        if(num == 4 && prevnum == 3)
            return false;


        return true;
    }

    char moves(int decision){
        //cout<<"B Decision: "<<decision<<endl;
        switch(decision){
        case 1:
            return 'U';
            break;
        case 2:
            return 'D';
            break;
        case 3:
            return 'R';
            break;
        case 4:
            return 'L';
            break;
        }
    }

    //checking the surrounding of current player to see if available or not
    void checkOpenPositions(Board board,char& filled, bool& u,bool& d, bool& l, bool& r, int x, int y){


        //cout<<"CheckopenPositions x:"<<x<<" y: "<<y<<endl;

        //check up
        if(board.checkIfFilled(x,y-1)){
             filled = 'U';
            // cout<<"Up is available "<<x<<" "<<y-1<<endl;
             u = true;
        }

        //check down
        if(board.checkIfFilled(x,y+1)){
            filled = 'D';
            //cout<<"Down is available "<<x<<" "<<y+1<<endl;
            d = true;
        }


        //check right
        if(board.checkIfFilled(x+1,y)){
            filled = 'R';
            //cout<<"Right is available "<<x+1<<" "<<y<<endl;
            r = true;
        }


        //check left
        if(board.checkIfFilled(x-1,y)){
            filled = 'L';
            //cout<<"Left is available "<<x-1<<" "<<y<<endl;
            l = true;
        }

    }

};



#endif // AI_H_
