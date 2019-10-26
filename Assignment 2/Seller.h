#ifndef SELLER.h
#define SELLER.h

using namespace std;

class Seller: public Trader{
public:
    Seller(Simulator& s){
        //creating 10 sellers
        for(int i = 0; i < 10; i++){
            s.generateBidS('s', i,i);
        }

        //displays the buyers and stores them in text file
        s.showbuyers();

       /*
       displays sellers and stores them in text file
       initialises the auction transactions to take place.
       */
        s.showsellers();
       //s.showall();

    }

};

#endif // SELLER
