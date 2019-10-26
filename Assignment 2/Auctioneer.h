#ifndef AUCTIONNER.H
#define AUCTIONEER.H
#include "TEXTFILE.H"

using namespace std;
class Auctioneer{

public:

    Auctioneer(){};

    void CheckCompatible(Bid s[],Bid b[]){

        Textfile f;
        f.write("Matched bids:");
        for(int i = 0; i < 10; i++){

                //going through all the buyers
            for(int k = 0; k < 10; k++){

                //getting price of the seller
                double Sellvalue = s[i].getprice();
                bool sAvail = s[i].getAvailability();

                //getting price of the buyer
                double Buyvalue = b[k].getprice();
                bool bAvail = b[k].getAvailability();

                //cout<<Sellvalue<< " "<< sAvail<< " "<<Buyvalue<< " "<<bAvail<<endl;

                //checking if prices are matched
                if(Buyvalue >= Sellvalue){
                        //making sure that they are available for transaction
                    if(sAvail && bAvail){
                        //writing to text file


                        f.write(s[i].retrieveResult(),b[k].retrieveResult());

                        //checking if the quantities match
                        if(s[i].getquant() == b[k].getquant()){
                                //in case they are both equal
                                b[k].setquant(0);
                                s[i].setquant(0);
                                b[k].setUnavailable();
                                s[i].setUnavailable();
                        }else if(s[i].getquant() > b[k].getquant()){
                                s[i].setquant(s[i].getquant()-b[k].getquant());
                                b[k].setquant(0);
                                b[k].setUnavailable();
                        }else{
                                b[k].setquant(b[k].getquant()-s[i].getquant());
                                s[i].setquant(0);
                                s[i].setUnavailable();

                            }
                            //f.write("\t");
                            f.ItemChange(s[i].retrieveResult(),b[k].retrieveResult());
                    }

                }
            }
        }

        f.write("\nUnmatched Buy Bids");
        for(int k =0; k < 10; k++){
            if(b[k].getAvailability()){
                    f.write(b[k].retrieveResult());
            }
        }
          f.write("\nUnmatched Sell Bids");
        for(int k =0; k < 10; k++){
            if(s[k].getAvailability()){
                    f.write(s[k].retrieveResult());
            }

        }


    }

};


#endif // AUCTIONNER
