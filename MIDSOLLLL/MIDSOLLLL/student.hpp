//
//  student.hpp
//  Week 8 Tuesday
//
//  Created by James Chapman on 11/15/21.
//
//MARK: I am putting all class definitions in this file

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <iomanip>
//Include correct libraries
//Doing so in the h file will include it in the corresponding cpp file

class Student {
protected:
    std::string name;
    char gender;
    std::string birthday;   //Should probably use a different format than string but this is sufficient for our purposes

public:
    Student(std::string name, char gender, std::string birthday);
    
    std::string get_name();
    char get_gender();
    std::string get_birthday();
    
    //MARK: Virtual Function
    virtual std::string display() = 0;
    virtual ~Student() = 0;
};

//Convention is to use capital first letter for classes
class Ucla_student : public Student {
private:
    char firstGen;
    
public:
    Ucla_student(std::string name, char gender, std::string birthday, char firstGen);
    
    char get_firstGen();
    std::string display();
    
    ~Ucla_student() {};
};

class Usc_student : public Student {
private:
    char scholarship;
    
public:
    Usc_student(std::string name, char gender, std::string birthday, char scholarship);
    
    char get_scholarship();
    std::string display();
    ~Usc_student() {};
};


#endif /* student_hpp */
