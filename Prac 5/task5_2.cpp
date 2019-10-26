#include <iostream>
using namespace std;

int main( )
{
    int row, col;
    cout << "Enter the row and column dimensions of the array:\n";
    cin >> row >> col;

    //pointer to a pointer pointing to the memory position
    int **grid = new int*[row];

    //creating the 2d array by having n amount of cols per row
    for (int i = 0; i < row; i++)
        grid[i] = new int[col];

    cout << "Enter " << row << " rows of "
         << col << " integers each:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> grid[i][j];

    cout << "Echoing the 2 dimensional array:\n";
    for (int i = 0; i < row; i++)   {
        for (int j = 0; j < col; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    //destructor deleting each row
    for (int i = 0; i < row; i++)
        delete[] grid[i];

    //deleting the entire memory position of array
    delete[] grid;

    return 0;
}


