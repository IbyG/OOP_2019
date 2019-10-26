//Program to demonstrate the CDAccount structure type.
#include <iostream>
using namespace std;


class Date
{



public:
     int day;
    int month;
    int year;

    //uses iostream:
    void getDate()
    {
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter year: ";
        cin >> year;
    }

};

//Improved structure for a bank certificate of deposit:
class CDAccount
{
private:
    double initialBalance;
    double interestRate;
    int term;//months until maturity
    Date maturity; //date when CD matures


public:
    double balanceAtMaturity(){
        double rateFraction, interest;
        rateFraction = interestRate/100.0;
        interest = initialBalance*(rateFraction*(term/12.0));
        return(initialBalance + interest);
    }

    //uses iostream:
    void getCDData()
    {
        cout << "Enter account initial balance: $";
        cin >> initialBalance;
        cout << "Enter account interest rate: ";
        cin >> interestRate;
        cout << "Enter the number of months until maturity: ";
        cin >> term;
        cout << "Enter the maturity date:\n";
        maturity.getDate();
    }

    void printAccount(){

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
         cout << "When the CD matured on "
         << maturity.day
         << "-"<< maturity.month << "-"
        << maturity.year << endl
         << "it had a balance of $"
         << balanceAtMaturity() << endl;

    }

};



int main( )
{
    CDAccount account;
    cout << "Enter account data on the day account was opened:\n";
    account.getCDData();
    account.balanceAtMaturity();
    account.printAccount();







    return 0;
}




