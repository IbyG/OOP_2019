#ifndef SIMULATOR.H
#define SIMULATOR.H
#include "AUCTIONEER.H"

class Bid;
class Auctioneer;
using namespace std;

class Simulator{

public:

    Bid sellers[10];
    Bid buyers[10];

   void showall(){

    for(int i = 0; i < 10;i++){
        buyers[i].showall();
    }

    for(int i = 0; i < 10;i++){
       sellers[i].showall();
    }

   }


void generateBidB(char bidtype, int pos, int user){

    string Names[10] = {"Ibrahim", "Dean", "Dongmo", "Marcus", "Stephen",
    "Ben", "Mark", "Ken", "Johnny", "Josh"};


    double price = rand()%150+50; //from 50 to 200
    int quant = rand()%50+5; //from 5 to 55



    buyers[user].createOrder(Names[pos],getid(),bidtype,price,quant);
    //cout<<Names[pos]<<endl;
    //ids[user].showall();


}

void generateBidS(char bidtype, int pos, int user){

    string Names[10] = {"George", "Jack", "Alfie", "Isla",
    "Freddie", "Leo", "Emily", "Ava", "Splinter", "Donatello"};


    double price = rand()%150+50; //from 50 to 200
    int quant = rand()%50+5; //from 5 to 55



    sellers[user].createOrder(Names[pos],getid(),bidtype,price,quant);
    //ids[user].showall();


}

int getid(){

    return(rand() % 8999 + 1000); //from 1000 to 9999


}

//displays the buyers and stores them in text file
void showbuyers(){
    for(int i = 0; i < 10; i++){
        buyers[i].showall();

        //writing to textfile
        Textfile f;
        f.write(buyers[i].retrieveResult());

    }

}
/*
       displays sellers and stores them in text file
       initialises the auction transactions to take place.
*/
void showsellers(){
    Textfile f;
    for(int i = 0; i < 10; i++){
        sellers[i].showall();

        //writing to texfile
        f.write(sellers[i].retrieveResult());
    }
    f.write("");

    //after showing sellers, start the transactions
    Auctioneer a;
    a.CheckCompatible(sellers,buyers);
}



};


#endif // SIMULATOR
