//
//  main.cpp
//  Week 8 Tuesday
//
//  Created by James Chapman on 11/16/21.
//
#include <iostream>
#include <vector>
#include <fstream>
#include "student.hpp"

using namespace std;
//MARK: This code was not tested on Visual Studio

/*MARK: Strategy
 0. Preliminary
    - Plan this out on paper
    - create a vector<Student*> allStudents (this is the polymorphism part).
    - Include all relevant libraries (and do so in header files also).
 
 1. Program the student, ucla_student, usc_student classes
    - Fill out the .h files first (this will help with planning)
        - state which variables will be stored
        - program relevant constructors
        - program other functions
    - Write the class functions in the .cpp files
 
 2. Program the file reading
    - First successfully open and close the files
    - Make sure you can read in lines
    - Write a function/code to parse each line into the relevant variables
        - Should test this since it is critical for the program
    - Turn these variables into a ucla_student or usc_student
        - my strategy was to allocate them on the heap and put the pointer in allStudents
    
 3. Program the output display
    - I created a display() function for ucla_student and usc_student to compartmentalize this behavior
        - for this reason, it is generally better to have this in the class and not in main.
        - This also lets you do virtual std::string display() = 0; in the student class
    - Look at the output and refine.
        - Just play around with the functions in iomanip until the output looks right.
 
 4. Test your code in visual studio
    - If you see errors, go back to previous steps and do this process again.
 
 */

/*MARK: Common errors
 1. Forgetting to include libraries, incorrect file names, etc. which caused compilation to fail.
    - Solution: test your code in visual studio and check file names
 2. Poor use of classes
    - Class doesn't really embody what a student is
    - It should store name, gender, birthday
    - It doesn't just read directly from the file and then print that to the console
    - Solution: Write your code so it aligns with what a student is.
 3. Not creating an abstract class (forgetting to do = 0 on virtual function)
    - Solution: include = 0 on virtual functions.
 4. Hard coding file paths
    - Points not deducted for this.
    - Your file system is different from another computer.
    - If you give your code to someone else, it won't be able to find the file you want it to read.
    - Solution: just do "filename.txt" instead of "PATH/filename.txt" so that c++ just looks in the current directory
 5. Forgetting to free memory on the heap
    - Solution: use delete to get rid of memory allocated on the heap
 */




//MARK: FUNCTIONS TO READ FILES
Student* readLineUCLA(string line) {
    //Can do this directly from the ifstream, but I just wanted to put this into a function
    stringstream in(line);
    string name;
    char gender;
    string birthday;
    char firstGen;
    getline(in, name, '\t');
    in >> gender >> birthday >> firstGen;
    return new Ucla_student(name, gender, birthday, firstGen);
}

Student* readLineUSC(string line) {
    //Can do this directly from the ifstream, but I just wanted to put this into a function
    stringstream in(line);
    string name;
    char gender;
    string birthday;
    char scholarship;
    getline(in, name, '\t');
    in >> gender >> birthday >> scholarship;
    return new Usc_student(name, gender, birthday, scholarship);
}




int main() {
    //Written by James Chapman
    //Pick a good name for this. Bad names include: students, etc.
    vector<Student*> allStudents;
    
    ifstream fin_ucla, fin_usc; //These are better than fin1 and fin2, etc. Leads to less confusion
    fin_ucla.open("UCLAsdwevr.txt");
    fin_usc.open("USC.txt");
    
    string line;
    getline(fin_ucla, line);    //get rid of title line
    while(true) {
        getline(fin_ucla, line);
        if(fin_ucla.fail())
            break;
        if(line.size() > 3)
            allStudents.push_back(readLineUCLA(line));
    }
    
    getline(fin_usc, line);
    while(true) {
        getline(fin_usc, line);
        if(fin_usc.fail())
            break;
        if(line.size() > 3)
            allStudents.push_back(readLineUSC(line));
    }
    
    fin_ucla.close();
    fin_usc.close();
    
    
    
    cout << "STUDENT_NAME\tGENDER\tBIRTHDAY\t\tFIRST_GEN_COLLEGE_STUDENT\tSCHOLARSHIP" << endl;
    
    for(int i = 0; i < allStudents.size(); i++)
        cout << (allStudents[i] -> display()) << endl;
    
    
    for(int i = 0; i < allStudents.size(); i++)
        delete allStudents[i];
    
    return 0;
}
