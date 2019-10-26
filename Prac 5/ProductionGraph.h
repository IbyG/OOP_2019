#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <iostream>
using namespace std;

class ProductionGraph{
private:
    //pointer pointing to the value
   int NUMBER_OF_PLANTS;

    //the dynamic array
    int* darray;

public:
    ProductionGraph(int arraySize){
        //setting the size of the array
        darray = new int[arraySize];

        //storing the value
        NUMBER_OF_PLANTS = arraySize;
    }

    //releasing the allocated memory
    ~ProductionGraph(){delete[]darray;};

    void inputData(int production[]);
    void getTotal(int&);
    void graph(const int production[]);
    void printAsterisks(int);
};

void ProductionGraph::inputData(int production[])
{
    for (int i = 1; i <= NUMBER_OF_PLANTS; i++)
    {
        cout<<NUMBER_OF_PLANTS<<endl;

        cout << endl
             << "Enter production data for plant number "
             << i << endl;
        getTotal(production[i - 1]);
    }
}

void ProductionGraph::getTotal(int& amount)
{
    cout << "Enter a positive integer of units produced by each department, ranging from 1-20.\n" << endl;
    cin >> amount;
    while (amount < 0)
    {
    	    cout<<"input again" << endl;
        cin >> amount;
    }
}

void ProductionGraph::graph(const int production[])
{
    cout << "\nUnits produced in units:\n";
    for (int i = 1; i <= NUMBER_OF_PLANTS; i++)
    {
        cout << "Plant #" << i << " ";
        printAsterisks(production[i - 1]);
        cout << endl;
    }
}

void ProductionGraph::printAsterisks(int n)
{
    for (int count = 1; count <= n; count++)
        cout << "*";
}


#endif // PRODUCTION_H_
