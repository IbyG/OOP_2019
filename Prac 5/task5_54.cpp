#include <iostream>

#include "Student.h"

using namespace std;

int main( )
{
    string name;
    int units;

    cout<<"what's your name:\n";
    cin>>name;
    cout<<"How many units are you doing\n";
    cin>>units;

    Student stud(name,units);

    stud.unitsTaken();

    stud.displayInfo();



}
