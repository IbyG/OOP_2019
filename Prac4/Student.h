#ifndef STUDENT_H_
#define STUDENT_H_

#include<iostream>
using namespace std;

class Student{
private:
    int studentId;
    string studentName;
    int courseNo;

    //this could be a boolean
    string enrolmentStatus;
public:
    //default constructor
    Student(){
        studentId = 0000;
        studentName = "Ibrahim";
        courseNo = 1234;
        enrolmentStatus = "enrolled";
    }
    //constructor with user input
    Student(int I, string n,int cn, string es ){
        studentId = I;
        studentName = n;
        courseNo = cn;
        enrolmentStatus = es;
    }


    void setID(int i);
    void setName(string n);
    void setCourseNum(int c);
    void setEnrolment(string e);

    int getId();
    string getName();
    int getCourseNum();
    string getEnrolment();

    void display();
};





void Student::setID(int i){
    studentId = i;
}

void Student::setCourseNum(int c){
    courseNo = c;
}

void Student::setName(string n){
    studentName = n;
}

void Student::setEnrolment(string e){
    enrolmentStatus = e;
}

int Student::getId(){
    return studentId;
}

string Student::getName(){
    return studentName;
}

int Student::getCourseNum(){
    return courseNo;
}


string Student::getEnrolment(){
    return enrolmentStatus;
}

//displaying all the values from object
void Student::display(){

    cout<<"Your id: "<< getId() <<endl<<
    "Your Name is: "<<getName()<<endl<<
    "Your Course Number is: "<<getCourseNum()<<endl<<
    "Your enrollment status is: "<<getEnrolment()<<endl<<endl;

}

#endif // STUDENT_H_
