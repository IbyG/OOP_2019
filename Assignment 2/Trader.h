#ifndef TRADER.H
#define TRADER.H
#include <time.h>
#include <math.h>
#include <random>
#include <stdlib.h>
#include "SIMULATOR.H"
#include "TEXTFILE.H"
using namespace std;



class Trader{
private:
    string traderName;
    char traderType;

    const double MINPRICE = 50.00;
    const double MAXPRICE = 150.00;

    const int MINQUANTITY = 5;
    const int MAXQUANTITY = 50;

public:
    //generates bids between minprice and max price also minquantity and maxquantity
    //void generateBidB(char, int pos = 0, int user = 0);
    //void generateBidS(char, int pos = 0, int user = 0);
    void showbuyers();
    void showsellers();
    int getid();
    void PasstoSimulatorB();
    void PasstoSimulatorS();


    //issue when id did Bid ids[10] the first 10 did not show and
    //the last 10 did

};







#endif // TRADER
