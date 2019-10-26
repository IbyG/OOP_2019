#ifndef HUMANP.H


#include "Board.h"
class Board;

class HUMANP{
public:
    //gets user input
    void hplayer(char& rc, char& bc){

        cout<< "Red player type L, U, R, D: "<<endl;
        cin>> rc;

        cout<<  "Blue player type L, U, R, D: "<<endl;
        cin>> bc;
    }

};



#endif // HUMANP
