//Searches a partially filled array of nonnegative integers.
#include <iostream>

#include <sstream>

using namespace std;

const int DECLARED_SIZE = 10;

void fillArray(int a[], int size, int& numberUsed) {
    cout << "Enter up to " << size << " nonnegative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";

    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        a[index] = next;
        index++;
        cin >> next;
    }

    numberUsed = index;
}

string search(const int a[], int numberUsed, int target)
{
    stringstream ss;


    //looping through array
    for(int i = 0; i <= numberUsed; i++){
        if(target == a[i]){
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

int main( )
{
    int arr[DECLARED_SIZE], listSize, target;

    fillArray(arr, DECLARED_SIZE, listSize);

    char ans;

    //store the positions of the selected value
    string result;

    do
    {
        cout << "Enter a number to search for: ";
        cin >> target;

        result = search(arr, listSize, target);


        if (result == "")
            cout << target << " is not on the list.\n";
        else
            cout << target << " is stored in array position "
                 << result << endl
                 << "(Remember: The first position is 0.)\n";

        cout << "Search again?(y/n followed by return): ";
        cin >> ans;
    } while ((ans != 'n') && (ans != 'N'));

    cout << "End of program.\n";
    return 0;
}
