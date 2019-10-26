#include <iostream>

#include "BID.H"
#include "TRADER.H"
#include "SELLER.H"
#include "BUYER.H"
#include "SIMULATOR.H"
#include "TEXTFILE.H"




void tenBuyers();
void tenSellers();
int getid();

using namespace std;

int main(){
    srand((unsigned int)time(NULL));


    Simulator s;
    //creating 10 buyers
    Buyer b(s);
    //b.PasstoSimulator();

    //creating 10 sellers
    //also initialises the simulator
    Seller a(s);





    return 0;
}



