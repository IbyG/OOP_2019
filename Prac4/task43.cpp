#include<iostream>
#include "FLIGHT.H"

using namespace std;

int main(){

    //intilising the board object
    Flight initial;

    //displaying the empty board
    initial.displayBoard();


     string ans = "";

	do{
        cout<<"Would you like to reserve a seat: (y or Y): "<<endl;
        cin >>ans;
        initial.askUser();
	}while(ans != "n" && ans != "N" && initial.checkfull(8,4));



    return 0;
}
