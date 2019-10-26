#ifndef ONEDARRAY.H
#define ONEDARRAY.H

using namespace std;

class OneDArray{
private:
    static const int DECLARED_SIZE = 10;
    //the array that will store the integers
    int theIntegers[DECLARED_SIZE];
    //unknown use
    int numberUsed;

    int listSize;
    int target;



public:

    OneDArray(){} //initiliser

    void fillArray();
    string search(int);
    void displayPositions(int, string);


};


void OneDArray::fillArray(){
    cout << "Enter up to " << DECLARED_SIZE << " nonnegative whole numbers.\n"
             << "Mark the end of the list with a negative number.\n";

        int next, index = 0;
        cin >> next;
        while ((next >= 0) && (index < DECLARED_SIZE))
        {
            theIntegers[index] = next;
            index++;
            cin >> next;
        }

        numberUsed = index;
}

string OneDArray::search( int target)
{
    stringstream ss;
    bool found;

    //looping through array
    for(int i = 0; i <= numberUsed; i++){
        if(target == theIntegers[i]){
            //storing the array position
            ss<<" "<<i;
            found = true;
        }
    }

     if (found)
        return ss.str();
    else
        return "-1";
}


void OneDArray::displayPositions(int target,string result){
 if (result == "")
            cout << target << " is not on the list.\n";
        else
            cout << target << " is stored in array position "
                 << result << endl
                 << "(Remember: The first position is 0.)\n";
}

#endif // ONEDARRAY
