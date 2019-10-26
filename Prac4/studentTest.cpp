#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#include "STUDENT.H"

int main(){

    //default constructor
    Student ibrahim;

    //custom constructor
    Student john(1234,"John",5643,"enrolled");

    ibrahim.display();


    john.display();

    return 0;
}
