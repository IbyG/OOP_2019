
#include <iostream>

using namespace std;

int main(){

    string theInput ="";

    cout<<"type in a series of characters and the program will remove integers if they appear"<<endl;
    cin>>theInput;


    //going through each char in string
    for(int i = 0; i < theInput.size(); ++i){
        //checking if char is not valid
        if(!((theInput[i] >= 'a' && theInput[i]<='z' ||
              (theInput[i]>= 'A' && theInput[i] <= 'Z'))))
           {
               //empty input
               theInput[i] = '\0';
           }

    }

    cout<<"Your line is: \n"<<theInput<<endl;


}
