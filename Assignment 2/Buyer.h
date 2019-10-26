#ifndef BUYER.H
#define BUYER.H

using namespace std;

// inhereting generatebid from trader
class Buyer: public Trader{

public:
    Buyer(Simulator& s){

        //creating 10 buyers
        for(int i = 0; i < 10; i++){
            s.generateBidB('b', i,i);
        }

    }

};



#endif // BUYER



