#include<iostream>
#include<string>
using namespace std;

#include"sender.h"
#include"receiver.h"
#include"coordinator.h"
#include "DATE.h"


int main() {
	Coordinator c;
	c.run();
	return 0;
}
