#ifndef JONE_H_
#define JONE_H_
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "DATE.H"


class Sender {
	string message;
public:
	void setMessage();
	string getMessage() {return message;}
	Date producedates();
};

void Sender::setMessage() {
	string ss;
	cout << "Sender says:";
	getline(cin, ss);
	message = ss;
}

//100 objects being generated and returned
Date Sender::producedates(){
    srand (time(NULL));
    Date d[100];

    //creating 100 dates in array of objects
    for(int i = 0; i < 100; i++){
        d[i].setDate(rand() % 30 + 1,rand()%11 + 1, 2000);
        //d[i].setDate(10,10, 2000);
   }

   return d[100];

}




#endif /* JONE_H_ */
