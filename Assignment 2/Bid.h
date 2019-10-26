#ifndef BID.H
#define BID.H
#include <sstream>
#include <string>

using namespace std;

class Bid{
private:
    string TraderName;
    int BidId;
    char BidType;
    double price;
    int quantity;
    bool available = true;

public:
    //default constructor
    Bid(){}

    void createOrder(string n, int bId, char bt, double p, int q){
        TraderName = n;
        BidId = bId;
        BidType = bt;
        price = p;
        quantity = q;
    }

    void showall(){
        cout<< TraderName<< "\t "<< BidId<<"\t "<< BidType<<"\t $"<< price << "\t "<< quantity<<endl;
    }

    string retrieveResult(){
        std::stringstream info;
        info << TraderName<< "\t "<< BidId<<"\t "<< BidType<<"\t $"<< price << "\t "<< quantity;
        std::string s = info.str();
        return s;
    }

    int getBidid(){
        return BidId;
    }

    double getprice(){
        return price;
    }

    int getquant(){
        return quantity;
    }

    void setquant(int q){
        quantity = q;
    }

    //making the order unavailable
    void setUnavailable(){
        available = false;
    }

    //returning if its still available or not
    bool getAvailability(){
        return available;
    }


};


#endif // BID
