#ifndef KATE_H_
#define KATE_H_

class Receiver {
	string message;
public:
	void receiveMessage(string ss) {message = ss;}
	void printMessage() {cout << "You said: " << message << endl;}

	//printing the dates
	void displayMessage(Date d[]){

        for(int i = 0; i < 100; i++){
            d[i].showdate();

        }
	}
};
#endif /* KATE_H_ */
