#ifndef OBJECTY_H_
#define OBJECTY_H_


using namespace std;

class objecty{
public:
    static int item;

    objecty(){
        item ++;
        cout<<"Object Number: "<<item<<endl;
    }

};



#endif // OBJECTY_H_

