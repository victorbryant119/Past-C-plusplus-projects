/*  PIC 10B 2A, Midterm Exam
        Purpose: Student Datasets
        Author: Wenchen Shi
        Date: 11/04/2021
        Cite:
    */
// common categories are in class student
// identify and separated into two classes USC and UCLA
//1. upload the files
//2.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "ucla_student.h"
#include "usc_student.h"
using namespace std;

void displayStudents(vector<student*> vec) {
    //using iomanip to line up
    cout << left << setw(20) << "Student_Name" << left << setw(12) << "Gender" << left << setw(14) << "Birthday" << left << setw(28) <<"First_Gen_College_student"<< "Scholarship" << endl;
//    cout << "Student_Name\t" << "Gender\t" << "Birthday\t\t" << "First_Gen_College_Student\t" << "Scholarship\t"<< endl;
    for (int i = 0; i < vec.size(); i++) {
        //print out the display of the actual student data
        vec[i]->display();
    }
}

int main() {
    string temp, fullName, firstName, lastName, middleInitial, gender, bDay, fGen, scholarship;
    bool hasMI = false;
    int counter = 0;
    vector<student*> myVec;
    ifstream myFile("UCLA.txt");
    ifstream myFile2("USC.txt");
//make sure no repeated headers
    if (myFile.is_open()) {
        while (counter < 4) {
            myFile >> temp;
            counter++;
        }
//Check if there is a middle name
        while (myFile) {
            hasMI = false;
            myFile >> firstName;
            myFile >> middleInitial;

            if (middleInitial[1] == '.') {
                hasMI = true;
                myFile >> lastName;
            }
            else
            {
                lastName = middleInitial;
            }

            myFile >> gender;
            myFile >> bDay;
            myFile >> fGen;
//combine the first middle and last names into one string
            if (hasMI) {
                fullName = firstName + " " + middleInitial + " " + lastName;
            }
            else
            {
                fullName = firstName + " " + lastName;
            }
            myVec.push_back(new ucla_student(fGen, fullName, bDay, gender));
        }
        myVec.pop_back();
    }
//reset counter to 0 to check no repeated headers
    counter = 0;
    if (myFile2.is_open()) {
        while (counter < 4) {
            myFile2 >> temp;
            counter++;
        }

        while (myFile2) {
            hasMI = false;
            myFile2 >> firstName;
            myFile2 >> middleInitial;

            if (middleInitial[1] == '.') {
                hasMI = true;
                myFile2 >> lastName;
            }
            else {
                lastName = middleInitial;
            }

            myFile2 >> gender;
            myFile2 >> bDay;
            myFile2 >> scholarship;

            if (hasMI) {
                fullName = firstName + " " + middleInitial + " " + lastName;
            }
            else
            {
                fullName = firstName + " " + lastName;
            }
            myVec.push_back(new usc_student(scholarship, fullName, bDay, gender));
        }
        myVec.pop_back();
    }
//call functions displayStudents to print out the display
    displayStudents(myVec);

     return 0;
}
