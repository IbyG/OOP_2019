#ifndef TEXTFILE.H
#define TEXTFILE.H
#include <iostream>
#include <fstream>
using namespace std;

class Textfile{
public:

    Textfile(){};
    //wrighting the result to a textfile
    void write(string text){

        ofstream auctionFile;
        auctionFile.open("AuctionResults.txt",std::ios_base::app);
        auctionFile<<text<<"\n";
        auctionFile.close();

    }

    //used for the matched bids
    void write(string t1,string t2){

        ofstream auctionFile;
        auctionFile.open("AuctionResults.txt",std::ios_base::app);
        auctionFile<<t1<<" <======>"<<t2<<"\t";
        auctionFile.close();

    }

    //used for after deduction of items
    void ItemChange(string t1,string t2){

        ofstream auctionFile;
        auctionFile.open("AuctionResults.txt",std::ios_base::app);
        auctionFile<<" Becomes "<<t1<<" <======>"<<t2<<"\n";
        auctionFile.close();

    }

};


#endif // TEXTFILE
