#include<iostream>
#include <cstdlib>

using namespace std;

void task21();
void odd21(int,int);
void even21(int,int);
void testOverloading(int, int);
void testOverloading(double,double);
void testOverloading(int, double);
void overloadTest();
void DefaultTest();
void testDefaultArg(int day=1,string month = "Jan", int year = 2017);
void quotremTest();
void out(int&,int&);
void sortTest();
void sorT(int&,int&,int&);


int main(){

    //task21(); //task2.1


    //overloadTest(); //task 2.2

    // DefaultTest(); //2.3

    //quotremTest(); //2.4

    //sortTest(); //2.5

    return 0;
}


//#################################################################################################################################################

//task 2.1
void task21(){

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


    if(firstNum % 2 == 0){
        odd21(firstNum, secondNum);
    }else{
        even21(firstNum,secondNum);
    }

}

void odd21(int firstNum, int secondNum){
    int temp,evenValue=0;

    temp = firstNum + 1;


    while(temp <= secondNum)
    {
        cout<< temp << "\n";
        //summing up all the even values between the two ranges
        evenValue += (temp - 1);
        temp += 2;
    }
    cout<<"Sum of All the even numbers: "<< evenValue<<endl;
}

void even21(int firstNum, int secondNum){

    int temp,evenValue=0;
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
    cout<<"Sum of All the even numbers: "<< evenValue<<endl;
}


//#################################################################################################################################################
//this function is used for 2.2
void overloadTest(){

    int num1, num2, choice;
    double nom1, nom2;

    cout<<"finding the fraction of 2 values"<<endl;

    cout<<"1. int int"<<endl;
    cout<<"2. double double"<<endl;
    cout<<"3. int double"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"Type two integers"<<endl;
            cin >> num1 >> num2;
            testOverloading(num1,num2);
            break;
        case 2:
            cout<<"Type two double"<<endl;
            cin >> nom1 >> nom2;
            testOverloading(nom1,nom2);
            break;
        case 3:
            cout <<"Type int then a double"<<endl;
            cin >> num1 >> nom2;
            testOverloading(num1,nom2);
            break;

    }


}

//task 2.2
void testOverloading(int numerator, int denominator){
    int fraction = numerator / denominator;
    cout<< "Fraction1 = "<<fraction<<endl;
}

void testOverloading(double numerator, double denominator) {
    double fraction = numerator / denominator;
    cout << "Fraction2 = " << fraction << endl;
}

void testOverloading(int numerator, double denominator) {
    double fraction = numerator / denominator;
    cout << "Fraction3 = " << fraction << endl;
}

//#################################################################################################################################################
//task 2.3
void DefaultTest(){
    testDefaultArg();
    testDefaultArg(10);
    testDefaultArg(10,"Jul");
    testDefaultArg(10,"Jul",2018);

}

//the issue here was the the default values were assigned in this function
//the default function CAN ONLY BE ASSIGNED IN FUNCTION PROTOTYPE AT THE TOP
void testDefaultArg(int day,string month, int year){
    cout<< "Today is " <<day<<" "<<month<<" "<<year<<endl;
}

//#################################################################################################################################################
//2.4
void quotremTest(){
    int num1, num2;

    cout<<"Type in two integers to get the quotient and remainder"<<endl;
    cin >> num1 >> num2;
    out(num1,num2);

}

void out(int& num1, int& num2){
    cout<<"The Quotient of "<<num1 << " and " << num2 << " is: " << num1/num2 <<endl;
    cout<<"The Remainder of "<<num1 << " and " << num2 << " is: " << num1%num2;
}

//#################################################################################################################################################
//2.5

void sortTest(){
    int n1,n2,n3;

    cout<<"Enter 3 integers"<<endl;
    cin >> n1>>n2>>n3;
    sorT(n1,n2,n3);
}

//sorting 3 integers
void sorT(int& a, int& b, int& c){
    //stores the value temporarly
    int temp;

    //loops twice, simple version of bubble sort
    for(int i = 0; i <= 1; i ++){
            if(a > b){
                temp = b;
                b = a;
                a = temp;
            }
            if(b > c){
                temp = c;
                c = b;
                b = temp;
            }
    }

    cout<<"Num1: "<<a<<" Num2: "<<b<<" Num3: "<<c<<endl;



}

