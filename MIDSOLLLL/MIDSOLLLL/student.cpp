//
//  student.cpp
//  Week 8 Tuesday
//
//  Created by James Chapman on 11/15/21.
//

#include "student.hpp"

//MARK: STUDENT STUFF
Student::Student(std::string name, char gender, std::string birthday) : name(name), gender(gender), birthday(birthday) {
    //In general we would want to do some error checking to make sure the data has the correct format
    //Use assert() to do this
}

std::string Student::get_name() {
    return name;
}
char Student::get_gender() {
    return gender;
}
std::string Student::get_birthday() {
    return birthday;
}

Student::~Student() {
    
}

//MARK: UCLA STUDENT STUFF
Ucla_student::Ucla_student(std::string name, char gender, std::string birthday, char firstGen) : Student(name, gender, birthday), firstGen(firstGen) {
    //In general we would want to do some error checking to make sure the data has the correct format
    //Use assert() to do this. For example, we may want to make sure firstGen == 'Y' or firstGen == 'N'
    //Written by James Chapman
};

char Ucla_student::get_firstGen() {
    return firstGen;
}

std::string Ucla_student::display() {
    std::stringstream out;
    out << std::left << std::setw(16) << name << std::setw(8) << gender << std::setw(16) << birthday << firstGen;
    return out.str();
}



//MARK: USC STUDENT STUFF
Usc_student::Usc_student(std::string name, char gender, std::string birthday, char scholarship) : Student(name, gender, birthday), scholarship(scholarship) {
    //In general we would want to do some error checking to make sure the data has the correct format
    //Use assert() to do this. For example, we may want to make sure scholarship == 'Y' or scholarship == 'N'
}

char Usc_student::get_scholarship() {
    return scholarship;
}

std::string Usc_student::display() {
    std::stringstream out;
    out << std::left << std::setw(16) << name << std::setw(8) << gender << std::setw(44) << birthday << scholarship;
    return out.str();
}

