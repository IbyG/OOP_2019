#include<iostream>
#include <cstdlib>
#include <time.h> //for the random seed
using namespace std;

void options();
void display1();
void display2();
void display3();
void display4();
int task15();
void display6();

int main(){

    int option = 0;

    do{
        options();

        cin>> option;
        switch(option){
            case 1:
                display1();
                break;
            case 2:
                display2();
                break;
            case 3:
                display3();
                break;
            case 4:
                display4();
                break;
            case 5:
                task15();
                break;
            case 6:
                display6();
                break;
        }


    }while(option != 7);



    return 0;
}

void options(){
    cout<< "1. view 1.1 (intro)\n";
    cout<< "2. view 1.2 (name and age)\n";
    cout<< "3. view 1.3 (odd and even)\n";
    cout<< "4. view 1.4 (nested loop)\n";
    cout<< "5. view 1.5\n";
    cout<< "6. view 1.6 (number game)\n";
    cout<< "7. exit\n";
}

//1.1
void display1(){
    cout<< "Welcome to OOP class.\n";
}

//getting user name and age
void display2(){
    //user name
    string name;
    //user age
    int age;

    cout<< "What your name: ";
    cin>> name;

    cout<<"How old are you: ";
    cin>> age;

    cout<< "your name is " << name << " And your age is " << age<<endl;
}

//1.3
void display3(){
    /*
    firstNum -first input
    secondNum -second input
    evenValue -the sum of all the even numbers
    temp - stores firstNum when printing even and odd values
    */
    int firstNum, secondNum, evenValue = 0, temp = 0;


    //getting user input
    do{
        cout<< "Type in an integer";
        cin>> firstNum;

        cout<<"Type in another integer";
        cin>>secondNum;

        //validating if firstnum is smaller than sceond num
        if(firstNum >= secondNum){
            cout<<"/nFirst number needs to be smaller than second number";
        }
    }while(firstNum >= secondNum);


    cout<<"All the odd numbers\n";
    if(firstNum % 2 == 0){
        temp = firstNum + 1;

        while(temp <= secondNum)
        {
            cout<< temp << "\n";
            //summing up all the even values between the two ranges
            evenValue += (temp - 1);
            temp += 2;
        }
    }
    else{
        temp = firstNum;

        while(temp <= secondNum)
        {
            cout<< temp << "\n";

            //it goes overboard by one
            if(evenValue < secondNum){
                //summing up all the even values between the two ranges
                evenValue += (temp + 1);
            }

            temp += 2;
        }
    }

    cout<<"Sum of All the even numbers: "<< evenValue<<endl;

}


//1.4 printing times table
void display4(){
    for(int i = 1; i <= 10; i++){
        for(int k = 1; k <= 10;  k++){
            cout<<i<<" x "<<k<<" = "<<(i*k)<<endl;
        }
        //line break
        cout<<endl;
    }
}


//task 1.5
int task15()
{
     int month, day;
     cout << "Welcome to your friendly weather program.\n"
     << "Enter today's date as two integers for the month and the day:\n";

     cin >> month;
     cin >> day;

    //srand is random seed which sets the the value for rand()
     srand(month*day);

     int prediction;
     char ans;

     cout << "Weather for today:\n";

     //a do while loop that gets the modulus of 3 and based on the output
     // a switch case statement goes through and prints out the appropriate response
     do
     {
        prediction = rand() % 3;
        switch (prediction)
        {
         case 0:
            cout << "The day will be sunny!!\n";
            break;
         case 1:
            cout << "The day will be cloudy.\n";
            break;
         case 2:
            cout << "The day will be stormy!.\n";
            break;
         default:
            cout << "Weather program is not functioning properly.\n";
     }
        //asking the user to repeat this loop or not
        cout << "Want the weather for the next day?(y/n): ";
        cin >> ans;
     } while (ans == 'y' || ans == 'Y');

    //closing of the program
     cout << "That's it from your 24 hour weather program.\n";
     return 0;
}

//task 1.6
void display6(){

    //random seed
    srand(time(NULL));
    //producing random number between 1-15
    int randomNum = (rand() % 15) + 1;
    int userAns, turn = 0;

    //cout<<randomNum<<endl;

    do{
        cout<< "What number do you think it is: ";
        cin>> userAns;

        //testing the user answer
        if(userAns < randomNum){
            cout<<"too low"<<endl;
            turn += 1;
        }
        else if(userAns > randomNum){
            cout<<"too large"<<endl;
            turn += 1;
        }
        else{
            cout<<"You're correct"<<endl;
            turn = 3;
        }

    }while(userAns != randomNum && turn != 3);

    cout<<"The number was: "<<randomNum<<endl;

}
