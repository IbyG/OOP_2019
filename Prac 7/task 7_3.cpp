
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream mathfile;
    mathfile.open("mathsheet.txt", std::ios_base::app);

    if(mathfile.fail()){
        cout<<"Failed to connect"<<endl;
    }


    string sym, oper;
    int num1, num2;
    while(mathfile){

    mathfile >> num1>>sym>>num2>>oper;
    //cout<<num1<<sym<<num2<<oper<<endl;

    ofstream results;
    results.open("MathAnswers.txt",std::ios_base::app);
    results<<num1<< " * "<< num2<< " = "<<num1*num2<<endl;;



    }

    cout<<"done"<<endl;


    return 0;
}
