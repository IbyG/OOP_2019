
#include <iostream>
using namespace std;

class Student{
private:
    string name;
    int numUnits;
    string *unitList;
    string unitName;

public:
    Student(string tname, int tnumUnits){
        name = tname;
        numUnits = tnumUnits;

        unitList = new string[numUnits];
    }

    void unitsTaken(){
        for(int i = 0; i < numUnits; i++){
            cout<<"Unit "<<i+1<<" Name: "<<endl;
            cin>>unitName;
            unitList[i] = unitName;
        }
    }

    //displaying user name and the units that they have selected
    void displayInfo(){
        cout<<"Student Name: "<<name<<endl;
        cout<<"The Units: "<<endl;
        for(int i = 0; i < numUnits; i++){
            cout<<i<<". "<<unitList[i]<<endl;
        }

    }

    ~Student(){delete[]unitList;};

};
