//Reads data and displays a bar graph showing productivity for each plant.
#include <iostream>

#include "PRODUCTIONGRAPH.H"

using namespace std;

int NUMBER_OF_PLANTS = 0;

int main( )
{
    cout << "This program displays a graph showing\n"
         << "production for each plant in the company.\n";

    cout<<"How many plants are you testing"<<endl;
    cin>>NUMBER_OF_PLANTS;


    int* production = new int[NUMBER_OF_PLANTS];


    ProductionGraph pg(NUMBER_OF_PLANTS);

    pg.inputData(production);
    pg.graph(production);

    pg.~ProductionGraph();

    return 0;
}


