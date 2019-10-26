#ifndef COORDINATOR_H_
#define COORDINATOR_H_

class Coordinator {
	Sender sender;
	Receiver receiver;
public:
	void run();
};

void Coordinator::run() {
	//sender.setMessage(); // the sender set a message
	Date d[100] = sender.producedates();

    //receiver.receiveMessage(sender.getMessage()); // get message from the sender and pass it to the receiver

    receiver.displayMessage(d);
    //receiver.printMessage();
}
#endif /* COORDINATOR_H_ */
