
#include <iostream>

#include <sstream>

#include "ONEDARRAY.H"

using namespace std;


int main( )
{
    OneDArray user;
    user.fillArray();
    char ans;

    //store the positions of the selected value
    string result;
    int target;

    do
    {
        cout << "Enter a number to search for: ";
        cin >> target;

        //searching the array for the target
        result = user.search(target);
        //displaying if found or not found
        user.displayPositions(target, result);


        cout << "Search again?(y/n followed by return): ";
        cin >> ans;
    } while ((ans != 'n') && (ans != 'N'));

    cout << "End of program.\n";

    return 0;
}
