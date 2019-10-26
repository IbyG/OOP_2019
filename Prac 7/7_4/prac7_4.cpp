#include<iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include "DATE.H"
using namespace std;

int main(){

    srand (time(NULL));
    Date d[100];

    //creating 100 dates in array of objects
    for(int i = 0; i < 100; i++){
        d[i].setDate(rand() % 30 + 1,rand()%11 + 1, 2000);
        //d[i].setDate(10,10, 2000);
   }

   for(int i = 0; i < 100; i++){
        d[i].showdate();

   }

    ofstream file;
    file.open("season.txt", std::ios_base::app);


    //writing in textfile based off of season

   file<<"Season 1\n"<<endl;
   for(int i = 0; i < 100; i++){
    if( d[i].getMonth()== 3 || d[i].getMonth()== 4 || d[i].getMonth()== 5 ){
            d[i].showdate();
            file<<d[i];
            file<<"\n";
        }
   }

   file<<"\nSeason 2\n"<<endl;
   for(int i = 0; i < 100; i++){
    if( d[i].getMonth()== 6 || d[i].getMonth()== 7 || d[i].getMonth()== 8 ){
            d[i].showdate();
            file<<d[i];
            file<<"\n";
        }
   }

   file<<"\nSeason 3\n"<<endl;
   for(int i = 0; i < 100; i++){
    if( d[i].getMonth()== 9 || d[i].getMonth()== 10 || d[i].getMonth()== 11 ){
            d[i].showdate();
            file<<d[i];
            file<<"\n";
        }
   }

   file<<"\nSeason 4\n"<<endl;
   for(int i = 0; i < 100; i++){
    if( d[i].getMonth()== 12 || d[i].getMonth()== 1 || d[i].getMonth()== 2 ){
            d[i].showdate();
            file<<d[i];
            file<<"\n";

        }
   }


    //get 100 dates store in array
    //sort them out by season



    return 0;
}

